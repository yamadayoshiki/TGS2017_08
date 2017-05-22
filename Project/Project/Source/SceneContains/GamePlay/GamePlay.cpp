#include "GamePlay.h"

#include <gslib.h>

#include "../SceneName.h"
#include "../../WorldContains/World/World.h"
#include"../../ActorContains/ActorGroup.h"
#include"../../CharacterContains/PlayerContains/Player/Player.h"
#include "../../Utility/InputState/InputState.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../Define/Def_Nagano.h"
#include "../../Define/Def_Nakayama.h"
#include "../../Utility/Rederer2D/Renderer2D.h"
#include"../../MapGenerator/MapGenerator.h"
#include "../../Utility/FourDirection/FourDirection.h"
#include "../../CharacterContains/EnemyContains/Enemys/Enemy01/Enemy01.h"

// コンストラクタ    
GamePlay::GamePlay(const IGameManagerPtr& gameManager)
	:Scene(gameManager) {
	gameManager->GetRenderer2D()->LoadTexture("game_back", "Resource/Texture/UI/Play/back_ground.png");
	p_GameManager->GetRenderer2D()->LoadTexture("chip", "Resource/Texture/wall.png");
}

// 開始     
void GamePlay::OnStart() {

	//マップデータによる生成
	p_World->generate(p_World, p_GameManager, "Resource/StreamingAssets/stage1.csv");

	Map map = p_World->GetMap();
	std::unordered_map<FourDirection, TileData> tmp = map.GetAroundTile(GSvector2(70, 90));

	//エネミー生成
	p_World->addActor(ActorGroup::Enemy, std::make_shared<Enemy01>(p_World.get(), GSvector2(CHIP_SIZE * 3, CHIP_SIZE * 15), FourDirection(FourDirectionName::Up), p_GameManager));

}

// 更新     
void GamePlay::OnUpdate(float deltaTime)
{
	gsTextPos(100, 100);
	gsDrawText("GamePlay");

	//if (p_GameManager->GetInputState()->IsKeyTrigger(GKEY_P)) {
	//	p_World->findActor(ActorName::Enemy_01)->dead();
	//}

	if (p_GameManager->GetInputState()->IsKeyTrigger(GKEY_RETURN) || 
		p_World->findActor(ActorName::EnemyManager)->getCount() <= 0) {
		p_World->EndRequest(SceneName::GameResult);
	}	
}

void GamePlay::OnDraw() const {
	p_GameManager->GetRenderer2D()->DrawTexture("game_back", GSvector2(0, 0));

	p_World->GetMap().draw();

	p_GameManager->GetPlayerParameter().DrawRemaining(p_GameManager->GetRenderer2D());
}
