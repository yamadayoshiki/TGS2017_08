#include "GameResult.h"

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

#include"ResultStart\ResultStart.h"
#include"ResultStaging\ResultStaging.h"
#include"ResultEnd\ResultEnd.h"



// �R���X�g���N�^    
GameResult::GameResult(const IGameManagerPtr& gameManager)
	: Scene(gameManager){
	isGameClear = false;
}

void GameResult::SetUp(){
	p_SceneChildMgr = std::make_unique<SceneChildMgr>(shared_from_this());
	p_SceneChildMgr->Add(SceneName::ResultStart, std::make_shared<ResultStart>());
	p_SceneChildMgr->Add(SceneName::ResultStaging, std::make_shared<ResultStaging>());
	p_SceneChildMgr->Add(SceneName::ResultEnd, std::make_shared<ResultEnd>());
	p_SceneChildMgr->Change(SceneName::ResultStart);
}

// �J�n     
void GameResult::OnStart() {
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
	//�u���b�N2�摜
	p_Block2 = std::dynamic_pointer_cast<Sprite>(
		p_UIMgr->findChildren([&](const Actor& actor)
	{
		if (actor.getName() == ActorName::UI_Sprite)
		{
			if (dynamic_cast<Sprite*>(const_cast<Actor*>(&actor))->GetUsage() == "Block2")
				return true;
		}
		return false;
	}));

	//�q�̃Z�b�g�A�b�v
	p_SceneChildMgr->SetUpChild();
	p_SceneChildMgr->Change(SceneName::ResultStart);

	//�e��p�����[�^�[������
	p_ScoreUI.lock()->ChangeDisplayMode(DisplayMode::NonDisplay);
	p_RankUI.lock()->ChangeDisplayMode(DisplayMode::NonDisplay);
	p_Platform.lock()->ChangeDisplayMode(DisplayMode::NonDisplay);
	p_Block.lock()->ChangeDisplayMode(DisplayMode::NonDisplay);
	p_Block2.lock()->ChangeDisplayMode(DisplayMode::NonDisplay);

	//BGM�̐ݒ�
	gsBindMusic(BGM_GAME_CLER);
	//BGM�Đ�
	gsPlayMusic();
}

// �X�V     
void GameResult::OnUpdate(float deltaTime) {
	//�q�V�[���̍X�V
	p_SceneChildMgr->Update(deltaTime);

	if (p_GameManager->GetInputState()->IsKeyTrigger(GKEY_RETURN)) {
		p_GameManager->set_MapOrder(0);
		p_World->EndRequest(SceneName::GameCredit);
		return;
	}
}

void GameResult::OnDraw() const{
}

void GameResult::OnEnd() {
	//�q�V�[���̏I��
	p_SceneChildMgr->End();
	p_SceneChildMgr->ReleaseWorld();

	//BGM��~
	gsStopMusic();
}

void GameResult::HandleMessage(EventMessage message, void * param){
	p_SceneChildMgr->HandleMessage(message, param);
}

std::weak_ptr<Number> GameResult::GetScoreUI()
{
	return p_ScoreUI;
}

std::weak_ptr<Rank> GameResult::GetRankUI()
{
	return p_RankUI;
}

std::weak_ptr<Sprite> GameResult::GetPlatform()
{
	return p_Platform;
}

std::weak_ptr<Sprite> GameResult::GetBlock()
{
	return p_Block;
}

std::weak_ptr<Sprite> GameResult::GetBlock2()
{
	return p_Block2;
}
