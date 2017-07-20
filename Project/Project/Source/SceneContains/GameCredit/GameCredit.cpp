#include "GameCredit.h"

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
#include"../../MapGenerator/MapGenerator.h"
#include "../../Utility/FourDirection/FourDirection.h"
#include"../../CharacterContains/Factory/CharacterFactory.h"
#include"../../Utility/Sound/SoundName.h"
#include "../../StagingContains/TransitionStaging/Transition/Transition.h"
#include"../../UIContains/UIManager/UIManager.h"
#include "../../UIContains/Number/Number.h"
#include "../../UIContains/Sprite/Sprite.h"
#include "../../UIContains/Button/Button.h"
#include"../../UIContains/Rank/Rank.h"
#include "../SceneManager/SceneChildMgr.h"
#include "../../Utility/Score/Score.h"

#include"CreditStart\CreditStart.h"
#include"CreditStaging\CreditStaging.h"
#include"CreditEnd\CreditEnd.h"

// �R���X�g���N�^    
GameCredit::GameCredit(const IGameManagerPtr& gameManager)
	:Scene(gameManager){
}

void GameCredit::SetUp() {
	p_SceneChildMgr = std::make_unique<SceneChildMgr>(shared_from_this());
	p_SceneChildMgr->Add(SceneName::CreditStart, std::make_shared<CreditStart>());
	p_SceneChildMgr->Add(SceneName::CreditStaging, std::make_shared<CreditStaging>());
	p_SceneChildMgr->Add(SceneName::CreditEnd, std::make_shared<CreditEnd>());
	p_SceneChildMgr->Change(SceneName::CreditStart);
}

// �J�n     
void GameCredit::OnStart() {
	//MapOrder�̎擾
	MapOrder = p_GameManager->get_MapOrder();

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
	//�R���{UI�̎擾
	p_ComboUI = std::dynamic_pointer_cast<Number>(
		p_UIMgr->findChildren([&](const Actor& actor)
	{
		if (actor.getName() == ActorName::UI_Number)
		{
			if (dynamic_cast<Number*>(const_cast<Actor*>(&actor))->GetUsage() == "Combo")
				return true;
		}
		return false;
	}));
	//���g���C��UI�̎擾
	p_RetryUI = std::dynamic_pointer_cast<Number>(
		p_UIMgr->findChildren([&](const Actor& actor)
	{
		if (actor.getName() == ActorName::UI_Number)
		{
			if (dynamic_cast<Number*>(const_cast<Actor*>(&actor))->GetUsage() == "Retry")
				return true;
		}
		return false;
	}));
	//Ranku UI�̎擾
	p_RankUI = std::dynamic_pointer_cast<Rank>(
		p_UIMgr->findChildren([&](const Actor& actor)
	{
		if (actor.getName() == ActorName::UI_Rank)
		{
			if (dynamic_cast<Rank*>(const_cast<Actor*>(&actor))->GetUsage() == "Rank")
				return true;
		}
		return false;
	}));
	//���U���g���ʂ̊�Չ摜
	p_Platform = std::dynamic_pointer_cast<Sprite>(
		p_UIMgr->findChildren([&](const Actor& actor)
	{
		if (actor.getName() == ActorName::UI_Sprite)
		{
			if (dynamic_cast<Sprite*>(const_cast<Actor*>(&actor))->GetUsage() == "Platform")
				return true;
		}
		return false;
	}));
	//�u���b�N�摜
	p_Block = std::dynamic_pointer_cast<Sprite>(
		p_UIMgr->findChildren([&](const Actor& actor)
	{
		if (actor.getName() == ActorName::UI_Sprite)
		{
			if (dynamic_cast<Sprite*>(const_cast<Actor*>(&actor))->GetUsage() == "Block")
				return true;
		}
		return false;
	}));
	//�g�[�^���X�R�A�t�H���g�摜
	p_Tortal = std::dynamic_pointer_cast<Sprite>(
		p_UIMgr->findChildren([&](const Actor& actor)
	{
		if (actor.getName() == ActorName::UI_Sprite)
		{
			if (dynamic_cast<Sprite*>(const_cast<Actor*>(&actor))->GetUsage() == "TotalScore")
				return true;
		}
		return false;
	}));
	//�}�b�N�X�R���{�t�H���g�摜
	p_MaxCombo = std::dynamic_pointer_cast<Sprite>(
		p_UIMgr->findChildren([&](const Actor& actor)
	{
		if (actor.getName() == ActorName::UI_Sprite)
		{
			if (dynamic_cast<Sprite*>(const_cast<Actor*>(&actor))->GetUsage() == "MaxCombo")
				return true;
		}
		return false;
	}));
	//���g���C�t�H���g�摜
	p_Retry = std::dynamic_pointer_cast<Sprite>(
		p_UIMgr->findChildren([&](const Actor& actor)
	{
		if (actor.getName() == ActorName::UI_Sprite)
		{
			if (dynamic_cast<Sprite*>(const_cast<Actor*>(&actor))->GetUsage() == "Retry")
				return true;
		}
		return false;
	}));

	//�q�̃Z�b�g�A�b�v
	p_SceneChildMgr->SetUpChild();
	p_SceneChildMgr->Change(SceneName::CreditStart);

	//�e��p�����[�^�[������
	p_ScoreUI.lock()->ChangeDisplayMode(DisplayMode::NonDisplay);
	p_ComboUI.lock()->ChangeDisplayMode(DisplayMode::NonDisplay);
	p_RetryUI.lock()->ChangeDisplayMode(DisplayMode::NonDisplay);
	p_RankUI.lock()->ChangeDisplayMode(DisplayMode::NonDisplay);
	p_Platform.lock()->ChangeDisplayMode(DisplayMode::NonDisplay);
	p_Block.lock()->ChangeDisplayMode(DisplayMode::NonDisplay);
	p_Tortal.lock()->ChangeDisplayMode(DisplayMode::NonDisplay);
	p_MaxCombo.lock()->ChangeDisplayMode(DisplayMode::NonDisplay);
	p_Retry.lock()->ChangeDisplayMode(DisplayMode::NonDisplay);
	//BGM�̐ݒ�
	gsBindMusic(BGM_GAME_CLER);
	//BGM�Đ�
	gsPlayMusic();
}

// �X�V     
void GameCredit::OnUpdate(float deltaTime) {
	//�q�V�[���̍X�V
	p_SceneChildMgr->Update(deltaTime);
}

void GameCredit::OnDraw() const{
}

void GameCredit::OnEnd(){
	//�q�V�[���̏I��
	p_SceneChildMgr->End();
	p_SceneChildMgr->ReleaseWorld();

	//BGM��~
	gsStopMusic();
}

void GameCredit::HandleMessage(EventMessage message, void * param) {
	p_SceneChildMgr->HandleMessage(message, param);
}

std::weak_ptr<Number> GameCredit::GetScoreUI()
{
	return p_ScoreUI;
}

std::weak_ptr<Number> GameCredit::GetComboUI()
{
	return p_ComboUI;
}

std::weak_ptr<Number> GameCredit::GetRetryUI()
{
	return p_RetryUI;
}

std::weak_ptr<Rank> GameCredit::GetRankUI()
{
	return p_RankUI;
}

std::weak_ptr<Sprite> GameCredit::GetPlatform()
{
	return p_Platform;
}

std::weak_ptr<Sprite> GameCredit::GetBlock()
{
	return p_Block;
}

std::weak_ptr<Sprite> GameCredit::GetTortal()
{
	return p_Tortal;
}

std::weak_ptr<Sprite> GameCredit::GetMaxCombo()
{
	return p_MaxCombo;
}

std::weak_ptr<Sprite> GameCredit::GetRetry()
{
	return p_Retry;
}
