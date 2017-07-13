#include "GameResult.h"

#include <gslib.h>
#include<GSmusic.h>

#include "../SceneName.h"
#include "../../WorldContains/World/World.h"
#include"../../ActorContains/ActorGroup.h"
#include"../../Utility/Rederer2D/Renderer2D.h"
#include"../../CharacterContains/PlayerContains/Player/Player.h"
#include "../../Utility/InputState/InputState.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../Define/Def_Nagano.h"
#include"../../Utility/Sound/SoundName.h"
#include"../../Utility/Score/Score.h"
#include"../../UIContains/UIManager/UIManager.h"
#include"../../Utility/EnumRap/EnumRap.h"

#include"../../CharacterContains/NeutralContains/Smork_Effect/Smork_Effect.h"
#include"ResultStart\ResultStart.h"
#include"ResultStaging\ResultStaging.h"
#include"ResultEnd\ResultEnd.h"
#include"BigBlock.h"


// �R���X�g���N�^    
GameResult::GameResult(const IGameManagerPtr& gameManager)
	:Scene(gameManager),
	m_Transition(std::make_shared<BigBlock>(gameManager))
{
	
}

// �J�n     
void GameResult::OnStart() {
	MapOrder = p_GameManager->get_MapOrder();

	m_SceneManager = new SceneManager();
	m_SceneManager->Initialize();

	//�V�[���̒ǉ�
	m_SceneManager->Add(SceneName::ResultStart, std::make_shared<ResultStart>(p_World.get(),p_GameManager));
	m_SceneManager->Add(SceneName::ResultStaging, std::make_shared<ResultStaging>(p_World.get(),p_GameManager));
	m_SceneManager->Add(SceneName::ResultEnd, std::make_shared<ResultEnd>(p_World.get(), p_GameManager));

	m_SceneManager->Change(SceneName::ResultStart);
	
	// UI�̐���
	//p_World->addActor(ActorGroup::UI, std::make_shared<UIManager>(p_World.get(), p_GameManager, m_SceneName));

	//BGM�̐ݒ�
	gsBindMusic(BGM_GAME_CLER);
	//BGM�Đ�
	gsPlayMusic();
}

// �X�V     
void GameResult::OnUpdate(float deltaTime) {

	//�I���̍X�V
	SelectUpdate();
	
	m_SceneManager->Update(deltaTime);

	timer_ += deltaTime;
}

void GameResult::OnDraw() const
{
	//���̃X�e�[�W�ɍs�����^�C�g���ɖ߂邩
	p_GameManager->GetRenderer2D()->DrawTexture("game_back", GSvector2(0, 0));

	m_SceneManager->Draw();
}

void GameResult::End()
{
	m_SceneManager = nullptr;
}

//�I���̍X�V
void GameResult::SelectUpdate()
{
	////���̃X�e�[�W���Ȃ��ꍇ�Q�[���N���A�֑J��
	//if ((this->MapOrder == 6)) {
	//	p_World->EndRequest(SceneName::GameTitle);
	//	return;
	//}
}
