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
#include "../../CharacterContains/EnemyContains/Enemys/Enemy02/Enemy02.h"
#include "../../CharacterContains/EnemyContains/Enemys/Enemy03/Enemy03.h"
#include "../../CharacterContains/EnemyContains/Enemys/Enemy05/Enemy05.h"


// �R���X�g���N�^    
GamePlay::GamePlay(const IGameManagerPtr& gameManager)
	:Scene(gameManager) {
	gameManager->GetRenderer2D()->LoadTexture("game_back", "Resource/Texture/UI/Play/back_ground.png");
	p_GameManager->GetRenderer2D()->LoadTexture("chip", "Resource/Texture/wall.png");
}

// �J�n     
void GamePlay::OnStart() {

	//�}�b�v�f�[�^�ɂ�鐶��
	p_World->generate(p_World, p_GameManager, "Resource/StreamingAssets/stage1.csv");

	Map map = p_World->GetMap();
	std::unordered_map<FourDirection, TileData> tmp = map.GetAroundTile(GSvector2(70, 90));

	//�G�l�~�[����
	p_World->addActor(ActorGroup::Enemy, std::make_shared<Enemy01>(p_World.get(), GSvector2(CHIP_SIZE * 19, CHIP_SIZE * 11), FourDirection(FourDirectionName::Left), p_GameManager));

	p_World->addActor(ActorGroup::Enemy, std::make_shared<Enemy03>(p_World.get(), GSvector2(CHIP_SIZE * 14, CHIP_SIZE * 16 + CHIP_SIZE / 2), FourDirection(FourDirectionName::Up), TurnDirection(TurnDirectionName::Clockwise), p_GameManager));

	p_World->addActor(ActorGroup::Enemy, std::make_shared<Enemy05>(p_World.get(), GSvector2(CHIP_SIZE * 22, CHIP_SIZE * 23), FourDirection(FourDirectionName::Left), p_GameManager));
	p_World->addActor(ActorGroup::Enemy, std::make_shared<Enemy05>(p_World.get(), GSvector2(CHIP_SIZE * 18, CHIP_SIZE * 5), FourDirection(FourDirectionName::Left), p_GameManager));
	p_World->addActor(ActorGroup::Enemy, std::make_shared<Enemy05>(p_World.get(), GSvector2(CHIP_SIZE * 10, CHIP_SIZE * 11), FourDirection(FourDirectionName::Left), p_GameManager));
	p_World->addActor(ActorGroup::Enemy, std::make_shared<Enemy05>(p_World.get(), GSvector2(CHIP_SIZE * 19, CHIP_SIZE * 23), FourDirection(FourDirectionName::Right), p_GameManager));

	p_World->addActor(ActorGroup::Enemy, std::make_shared<Enemy02>(p_World.get(), GSvector2(CHIP_SIZE * 11, CHIP_SIZE * 5), FourDirection(FourDirectionName::Right), FourDirection(FourDirectionName::Right), p_GameManager));
	p_World->addActor(ActorGroup::Enemy, std::make_shared<Enemy02>(p_World.get(), GSvector2(CHIP_SIZE * 15, CHIP_SIZE * 5), FourDirection(FourDirectionName::Right), FourDirection(FourDirectionName::Right), p_GameManager));

}

// �X�V     
void GamePlay::OnUpdate(float deltaTime){
	// Enter�L�[�������A�������͓����\�ȓG���O�ȉ��̏ꍇ�N���A
	if (p_GameManager->GetInputState()->IsKeyTrigger(GKEY_RETURN) ||
		p_World->GetSurviverSum() <= 0){
		p_World->EndRequest(SceneName::GameResult);
	}
}

void GamePlay::OnDraw() const {
	p_GameManager->GetRenderer2D()->DrawTexture("game_back", GSvector2(0, 0));

	p_World->GetMap().draw();

	p_GameManager->GetPlayerParameter().DrawRemaining(p_GameManager->GetRenderer2D());
	gsFontParameter(GS_FONT_BOLD, 50, "HG����B");
	gsTextPos(900, 50);
	gsDrawText("���� %d ��", p_World->GetSurviverSum());
	gsFontParameter(GS_FONT_BOLD, 20, "HG����B");
}
