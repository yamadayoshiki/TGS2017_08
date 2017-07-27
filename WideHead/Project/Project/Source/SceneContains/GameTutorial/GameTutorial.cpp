#include "GameTutorial.h"

#include <gslib.h>
#include<GSmusic.h>

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
#include"../../CharacterContains/Factory/CharacterFactory.h"
#include"../../Utility/Sound/SoundName.h"
#include "../../StagingContains/TransitionStaging/Transition/Transition.h"
#include"../../UIContains/UIManager/UIManager.h"
#include "../../UIContains/Number/Number.h"
#include "../../UIContains/Sprite/Sprite.h"
#include "../../UIContains/Button/Button.h"
#include "../SceneManager/SceneChildMgr.h"
#include "../../Utility/Score/Score.h"
#include "../../WorldContains/EventMessage/EventMessage.h"
#include "Pause\GameTutorialPause.h"
#include "Close\GameTutorialClose.h"
#include "Play\GameTutorialPlay.h"
#include "Ready\GameTutorialReady.h"
#include "../Elements/Guide/Guide.h"
#include "../../Wall/BreakWall.h"
#include "../../CharacterContains/EnemyContains/Entity/Enemys/Enemy05/Enemy05.h"
#include "../../CharacterContains/EnemyContains/Entity/Enemys/Enemy12/Enemy12.h"
#include "../Elements/TargetCircle/TargetCircle.h"
#include "../Elements/FlashSprite/FlashSprite.h" 
#include "../../TextureContains/Texture/Texture.h"
GameTutorial::GameTutorial(const IGameManagerPtr & gameManager)
	: Scene(gameManager)
	, p_Guide(std::shared_ptr<Guide>())
	, p_SkipUI(std::shared_ptr<FlashSprite>())
	, p_BreakWall(std::shared_ptr<BreakWall>())
	, p_Enemy05(std::shared_ptr<Enemy05>())
	, p_Enemy12(std::shared_ptr<Enemy12>())
	, p_ButtonUI(std::weak_ptr<Button>())
	, p_PauseBack(std::weak_ptr<Sprite>()) {
}

void GameTutorial::SetUp() {
	p_SceneChildMgr = std::make_unique<SceneChildMgr>(shared_from_this());
	p_SceneChildMgr->Add(SceneName::Start, std::make_shared<GameTutorialReady>());
	p_SceneChildMgr->Add(SceneName::Play, std::make_shared<GameTutorialPlay>());
	p_SceneChildMgr->Add(SceneName::Pause, std::make_shared<GameTutorialPause>());
	p_SceneChildMgr->Add(SceneName::Close, std::make_shared<GameTutorialClose>());
	p_SceneChildMgr->SetUp();
}

void GameTutorial::OnStart() {
	//Map�f�[�^�̐ݒ�
	MapSetDeta();

	// UI�̐���
	ActorPtr p_UIMgr = std::make_shared<UIManager>(p_World.get(), p_GameManager, m_SceneName);
	p_World->addActor(ActorGroup::UI, p_UIMgr);

	//�|�[�Y��ʃ{�^��UI
	p_ButtonUI = std::dynamic_pointer_cast<Button>(
		p_UIMgr->findChildren([&](const Actor& actor)
	{
		if (actor.getName() == ActorName::UI_Button)
			return true;
		else
			return false;
	}));
	//�|�[�Y��ʔw�i
	p_PauseBack = std::dynamic_pointer_cast<Sprite>(
		p_UIMgr->findChildren([&](const Actor& actor)
	{
		if (actor.getName() == ActorName::UI_Sprite)
		{
			if (dynamic_cast<Sprite*>(const_cast<Actor*>(&actor))->GetUsage() == "PauseBackGround")
				return true;
		}
		return false;
	}));

	//�q�̃Z�b�g�A�b�v
	p_SceneChildMgr->SetUpChild();
	p_SceneChildMgr->Change(SceneName::Start);

	//�e��p�����[�^�[������
	p_ButtonUI.lock()->ChangeDisplayMode(DisplayMode::NonDisplay);
	p_PauseBack.lock()->ChangeDisplayMode(DisplayMode::NonDisplay);

	//UI������
	p_Guide = std::make_shared<Guide>(p_World.get(), p_GameManager);
	p_World->addActor(ActorGroup::UI, p_Guide);
	p_SkipUI = std::make_shared<FlashSprite>(p_World.get(), GSvector2(892.5, 930), p_GameManager, std::make_shared<Texture>("TutorialSkipFlash", p_GameManager->GetDrawManager(), DrawOrder::UI_Front2));
	p_SkipUI->initialize();
	ActorPtr enemyMgr = p_World->findActor(ActorName::EnemyManager);
	//���u���b�N�̐���
	std::shared_ptr<BreakWall> leftWall = std::make_shared<BreakWall>(p_World.get(), GSvector2(608, 736), p_GameManager);
	enemyMgr->addChild(std::dynamic_pointer_cast<Actor>(leftWall));
	p_World->addActor(ActorGroup::UI, std::make_shared<TargetCircle>(p_World.get(), p_GameManager, leftWall));
	//�E�u���b�N�̐���
	p_BreakWall = std::make_shared<BreakWall>(p_World.get(), GSvector2(864, 736), p_GameManager);
	enemyMgr->addChild(std::dynamic_pointer_cast<Actor>(p_BreakWall));
	p_World->addActor(ActorGroup::UI, std::make_shared<TargetCircle>(p_World.get(), p_GameManager, p_BreakWall));
	//�G�l�~�[05�̐���
	enemyMgr->addChild(p_Enemy05 = std::make_shared<Enemy05>(p_World.get(), GSvector2(928, 480), FourDirection(FourDirectionName::Left), p_GameManager));
	//�G�l�~�[12�̐���
	enemyMgr->addChild(p_Enemy12 = std::make_shared<Enemy12>(p_World.get(), GSvector2(928, 160), FourDirection(FourDirectionName::Left), p_GameManager));

	//BGM�Đ�
	gsBindMusic(BGM_GAME_PLAY);
	gsPlayMusic();
}

void GameTutorial::OnUpdate(float deltaTime) {
	//�q�V�[���̍X�V
	p_SceneChildMgr->Update(deltaTime);
	//�X�L�b�vUI�̍X�V
	p_SkipUI->update(deltaTime);
}

void GameTutorial::OnEnd() {
	//�q�V�[���̏I��
	p_SceneChildMgr->End();
	p_SceneChildMgr->ReleaseWorld();

	//�e��UI���̉��
	p_ButtonUI.reset();
	p_PauseBack.reset();
	p_Guide.reset();
	p_BreakWall.reset();
	p_Enemy05.reset();
	p_Enemy12.reset();
	p_SkipUI.reset();

	//BGM��~
	gsStopMusic();
}

void GameTutorial::HandleMessage(EventMessage message, void * param) {
	switch (message)
	{
	case EventMessage::END_SCENE:
		if (IsExistBrother((const SceneName&)param) == true)
			p_World->EndRequest((const SceneName&)param);
		return;
	}

	p_SceneChildMgr->HandleMessage(message, param);
}

std::weak_ptr<Button> GameTutorial::GetButtonUI() {
	return p_ButtonUI;
}

std::weak_ptr<Sprite> GameTutorial::GetPauseBack() {
	return p_PauseBack;
}

std::shared_ptr<Guide> GameTutorial::GetGuide() {
	return p_Guide;
}

std::shared_ptr<FlashSprite> GameTutorial::GetSkipUI() {
	return p_SkipUI;
}

std::shared_ptr<BreakWall> GameTutorial::GetBreakWall() {
	return p_BreakWall;
}

std::shared_ptr<Enemy05> GameTutorial::GetEnemy05() {
	return p_Enemy05;
}

std::shared_ptr<Enemy12> GameTutorial::GetEnemy12() {
	return p_Enemy12;
}

void GameTutorial::MapSetDeta() {
	//�}�b�v�f�[�^�ɂ�鐶��
	p_World->SetMapGenerator(p_World, p_GameManager);
	p_World->SetCharacterFactory(new CharacterFactory(p_World, p_GameManager));
	MapOrder = p_GameManager->get_MapOrder();
	p_World->generate(p_World, p_GameManager, "Resource/StreamingAssets/stage0.csv");
}
