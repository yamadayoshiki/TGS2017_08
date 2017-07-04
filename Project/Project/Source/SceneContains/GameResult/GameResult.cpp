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


// �R���X�g���N�^    
GameResult::GameResult(const IGameManagerPtr& gameManager)
	:Scene(gameManager),
	m_ScorePosition{ 0.0f,0.0f }
{
	
}

// �J�n     
void GameResult::OnStart() {
	MapOrder = p_GameManager->get_MapOrder();
	m_ScorePosition = GSvector2(550, 250);

	// UI�̐���
	p_World->addActor(ActorGroup::UI, std::make_shared<UIManager>(p_World.get(), p_GameManager, m_SceneName));

	m_CarsorMovement = CarsorMovement::Left;

	//BGM�̐ݒ�
	gsBindMusic(BGM_GAME_CLER);
	//BGM�Đ�
	gsPlayMusic();
}

// �X�V     
void GameResult::OnUpdate(float deltaTime) {

	//�I���̍X�V
	SelectUpdate();

	//�J�[�\���ړ�
	if (p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_LEFT) ||
		p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_RIGHT)) {
		if (m_CarsorMovement == CarsorMovement::Left)		{
			m_CarsorMovement = CarsorMovement::Right;
		}
		else{
			m_CarsorMovement = CarsorMovement::Left;
		}
	}
}

void GameResult::OnDraw() const
{
	//���̃X�e�[�W�ɍs�����^�C�g���ɖ߂邩
	p_GameManager->GetRenderer2D()->DrawTexture("game_back", GSvector2(0, 0));
	p_GameManager->GetRenderer2D()->DrawTexture("NextStage", GSvector2(SCREEN_SIZE.x / 2 - 400, SCREEN_SIZE.y / 2 + 178));
	p_GameManager->GetRenderer2D()->DrawTexture("ReturnTitle", GSvector2(SCREEN_SIZE.x / 2 + 128, SCREEN_SIZE.y / 2 + 178));

	//�J�[�\���`��
	if (m_CarsorMovement == CarsorMovement::Left)
	{
		p_GameManager->GetRenderer2D()->DrawTexture("Cursor", GSvector2(SCREEN_SIZE.x / 2 - 470, SCREEN_SIZE.y / 2 + 190));
	}
	else
	{
		p_GameManager->GetRenderer2D()->DrawTexture("Cursor", GSvector2(SCREEN_SIZE.x / 2 + 50, SCREEN_SIZE.y / 2 + 190));
	}

	//���U���g�X�R�A�̕`��
	p_GameManager->GetScore()->setPosition(GSvector2(200, 200));
	p_GameManager->GetScore()->draw(p_GameManager->GetRenderer2D());
}

void GameResult::End()
{
	gsStopMusic();
}

//�I���̍X�V
void GameResult::SelectUpdate()
{
	//���̃X�e�[�W�ɍs�����^�C�g���ɖ߂邩
	if (p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_B) == GS_FALSE) return;
	//���̃X�e�[�W���Ȃ��ꍇ�Q�[���N���A�֑J��
	if ((this->MapOrder == 6)) {
		p_World->EndRequest(SceneName::GameTitle);
		return;
	}

	switch (m_CarsorMovement)
	{
	case CarsorMovement::Left:
		MapOrder += 1;
		p_GameManager->set_MapOrder(MapOrder);
		p_World->EndRequest(SceneName::GamePlay);
		gsPlaySE(SE_DECITION);
		break;

	case CarsorMovement::Right:
		MapOrder = 0;
		p_World->EndRequest(SceneName::GameTitle);
		gsPlaySE(SE_BACK);
		break;
	}
}
