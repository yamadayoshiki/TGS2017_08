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

#include"ResultStart\ResultStart.h"
#include"ResultStaging\ResultStaging.h"
#include"ResultEnd\ResultEnd.h"



// �R���X�g���N�^    
GameResult::GameResult(const IGameManagerPtr& gameManager)
	:Scene(gameManager)
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
	
	//BGM�̐ݒ�
	gsBindMusic(BGM_GAME_CLER);
	//BGM�Đ�
	gsPlayMusic();
}

// �X�V     
void GameResult::OnUpdate(float deltaTime) {
	
	m_SceneManager->Update(deltaTime);

	timer_ += deltaTime;
}

void GameResult::OnDraw() const
{
	//���̃X�e�[�W�ɍs�����^�C�g���ɖ߂邩
	p_GameManager->GetRenderer2D()->DrawTexture("game_back", GSvector2(0, 0));

	m_SceneManager->Draw();
}

void GameResult::OnEnd()
{
	m_SceneManager = nullptr;
}
