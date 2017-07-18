#include "GamePlay.h"

#include <gslib.h>
#include<GSmusic.h>

#include <chrono>

#include "../SceneName.h"
#include "../../WorldContains/World/World.h"
#include"../../ActorContains/ActorGroup.h"
#include"../../CharacterContains/PlayerContains/Player/Player.h"
#include "../../Utility/InputState/InputState.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../Define/Def_Nagano.h"
#include "../../Define/Def_Nakayama.h"
#include "../../Utility/Rederer2D/Renderer2D.h"
#include "../../Utility/Score/Score.h"
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

// �R���X�g���N�^    
GamePlay::GamePlay(const IGameManagerPtr& gameManager)
	: Scene(gameManager) {
	isGameClear = false;
}

void GamePlay::SetUp(){
	p_SceneChildMgr = std::make_unique<SceneChildMgr>(shared_from_this());
}

// �J�n     
void GamePlay::OnStart() {
	//Map�f�[�^�̐ݒ�
	MapSetDeta();

	// UI�̐���
	ActorPtr p_UIMgr = std::make_shared<UIManager>(p_World.get(), p_GameManager, m_SceneName);
	p_World->addActor(ActorGroup::UI, p_UIMgr);

	//�X�R�AUI�̎擾
	p_ScoreUI = std::dynamic_pointer_cast<Number>(
		p_UIMgr->findChildren([&](const Actor& actor)
	{
		if (actor.getName() == ActorName::UI_Number)
		{
			if (dynamic_cast<Number*>(const_cast<Actor*>(&actor))->GetUsage() == "Score")
				return true;
		}
		return false;
	}));
	//�v���C���[�c�@UI�̎擾
	p_PlayerRemainingUI = std::dynamic_pointer_cast<Number>(
		p_UIMgr->findChildren([&](const Actor& actor)
	{
		if (actor.getName() == ActorName::UI_Number)
		{
			if (dynamic_cast<Number*>(const_cast<Actor*>(&actor))->GetUsage() == "PlayerRemaining")
				return true;
		}
		return false;
	}));
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


	//�e��p�����[�^�[������
	p_GameManager->GetScore()->ScoreRest();
	PauseFlag = false;
	p_ButtonUI.lock()->ChangeDisplayMode(DisplayMode::NonDisplay);
	p_PauseBack.lock()->ChangeDisplayMode(DisplayMode::NonDisplay);

	gsBindMusic(BGM_GAME_PLAY);
	gsPlayMusic();
}

// �X�V     
void GamePlay::OnUpdate(float deltaTime) {
	//�|�[�Y�؂�ւ�
	if (p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_START) == GS_TRUE)
	{
		gsPlaySE(SE_PAUSE_OPEN);
		PauseFlag = !PauseFlag;
	}

	//�|�[�Y�̍X�V
	if (PauseFlag == true)
		PauseUpdate();

	// �����\�ȓG���O�ȉ��̏ꍇ�N���A
	if (p_World->GetSurviverSum(MapOrder) <= 0 || p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_X)) {
		isGameClear = true;
		p_World->EndRequest(SceneName::GameResult);
	}

	//�|�[�Y���
	if (PauseFlag == true)
	{

	}

	//UI�����ݒ�
	p_ScoreUI.lock()->SetNum(p_GameManager->GetScore()->ReleaseScore());
	p_PlayerRemainingUI.lock()->SetNum(p_GameManager->GetPlayerParameter().GetRemaining());
}

void GamePlay::OnDraw() const {
}

void GamePlay::OnEnd() {
	gsStopMusic();

	if (MapOrder >= 1)
		p_GameManager->set_MapOrder(MapOrder);

	else
		MapOrder = 0;
}
std::weak_ptr<Number> GamePlay::GetScoreUI()
{
	return p_ScoreUI;
}
std::weak_ptr<Number> GamePlay::GetPlayerRemainingUI()
{
	return p_PlayerRemainingUI;
}
std::weak_ptr<Button> GamePlay::GetButtonUI()
{
	return p_ButtonUI;
}
std::weak_ptr<Sprite> GamePlay::GetPauseBack()
{
	return p_PauseBack;
}
//Map�f�[�^�̐ݒ�
void GamePlay::MapSetDeta() {
	//�}�b�v�f�[�^�ɂ�鐶��
	p_World->SetMapGenerator(p_World, p_GameManager);
	p_World->SetCharacterFactory(new CharacterFactory(p_World, p_GameManager));
	MapOrder = p_GameManager->get_MapOrder();
	p_World->generate(p_World, p_GameManager, "Resource/StreamingAssets/stage" + std::to_string(MapOrder) + ".csv");
}
//�|�[�Y�̍X�V
void GamePlay::PauseUpdate()
{
	//�J�[�\���ړ�
	if (p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_DOWN) ||
		p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_UP)) {
		if (m_CarsorMovement == CarsorMovement::Up)
		{
			m_CarsorMovement = CarsorMovement::Down;
		}
		else
		{
			m_CarsorMovement = CarsorMovement::Up;
		}
	}

	//�|�[�Y�I��
	if (p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_B) == GS_FALSE)return;
	switch (m_CarsorMovement)
	{
	case CarsorMovement::Up:
		gsPlaySE(SE_DECITION);
		PauseFlag = false;
		break;
	case CarsorMovement::Down:
		gsPlaySE(SE_DECITION);
		MapOrder = 0;
		p_World->EndRequest(SceneName::GameTitle);
		break;
	}
}
