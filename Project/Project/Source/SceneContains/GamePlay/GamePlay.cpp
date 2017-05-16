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

// コンストラクタ    
GamePlay::GamePlay(const IGameManagerPtr& gameManager)
	:Scene(gameManager) {
	gameManager->GetRenderer2D()->LoadTexture("game_back", "Resource/Texture/UI/Play/back_ground.png");
	p_GameManager->GetRenderer2D()->LoadTexture("chip", "Resource/Texture/wall.png");
}

// 開始     
void GamePlay::OnStart(){

	//キャラクターマネージャー
	p_World->setCharacterManager(new CharacterManager());
	//プレイヤー生成
	p_World->addActor(ActorGroup::Player, std::make_shared<Player>(p_World.get(), GSvector2(100.0f, 100.0f), p_GameManager));
	//マップデータによる生成
	p_World->generate(p_World, p_GameManager, "Resource/StreamingAssets/stage1.csv");

	Map map = p_World->GetMap();
	std::unordered_map<Tile, TileData> tmp = map.GetAroundTile(GSvector2(70, 90));

	GSvector2 tilePos = tmp[Tile::Down].Position();
	GSrect tileRect = tmp[Tile::Down].Rectangle();
	bool tileFlag = tmp[Tile::Down].Flag();
}

// 更新     
void GamePlay::OnUpdate(float deltaTime)
{
	gsTextPos(100, 100);
	gsDrawText("GamePlay");


	if (p_GameManager->GetInputState()->IsKeyTrigger(GKEY_RETURN)) {
		p_World->EndRequest(SceneName::GameTitle);
	}
}

void GamePlay::OnDraw() const{
	p_GameManager->GetRenderer2D()->DrawTexture("game_back", GSvector2(0, 0));

	p_World->GetMap().draw();
}
