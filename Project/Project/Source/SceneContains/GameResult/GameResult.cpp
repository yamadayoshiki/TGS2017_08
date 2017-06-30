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


// �R���X�g���N�^    
GameResult::GameResult(const IGameManagerPtr& gameManager)
	:Scene(gameManager),
	m_ScorePosition{ 0.0f,0.0f }
{
	StageRankNolma[0][(int)Rank::RankS] = 300;
	StageRankNolma[0][(int)Rank::RankA] = 250;
	StageRankNolma[0][(int)Rank::RankB] = 200;
	StageRankNolma[0][(int)Rank::RankC] = 100;

	StageRankNolma[1][(int)Rank::RankS] = 700;
	StageRankNolma[1][(int)Rank::RankA] = 550;
	StageRankNolma[1][(int)Rank::RankB] = 400;
	StageRankNolma[1][(int)Rank::RankC] = 300;

	StageRankNolma[2][(int)Rank::RankS] = 1000;
	StageRankNolma[2][(int)Rank::RankA] = 900;
	StageRankNolma[2][(int)Rank::RankB] = 800;
	StageRankNolma[2][(int)Rank::RankC] = 750;

	StageRankNolma[3][(int)Rank::RankS] = 1100;
	StageRankNolma[3][(int)Rank::RankA] = 1050;
	StageRankNolma[3][(int)Rank::RankB] = 950;
	StageRankNolma[3][(int)Rank::RankC] = 850;

	StageRankNolma[4][(int)Rank::RankS] = 1250;
	StageRankNolma[4][(int)Rank::RankA] = 1150;
	StageRankNolma[4][(int)Rank::RankB] = 1050;
	StageRankNolma[4][(int)Rank::RankC] = 950;

	StageRankNolma[5][(int)Rank::RankS] = 1300;
	StageRankNolma[5][(int)Rank::RankA] = 1200;
	StageRankNolma[5][(int)Rank::RankB] = 1100;
	StageRankNolma[5][(int)Rank::RankC] = 1000;

	StageRankNolma[6][(int)Rank::RankS] = 1350;
	StageRankNolma[6][(int)Rank::RankA] = 1250;
	StageRankNolma[6][(int)Rank::RankB] = 1150;
	StageRankNolma[6][(int)Rank::RankC] = 1050;

	StageRankNolma[7][(int)Rank::RankS] = 1400;
	StageRankNolma[7][(int)Rank::RankA] = 1300;
	StageRankNolma[7][(int)Rank::RankB] = 1200;
	StageRankNolma[7][(int)Rank::RankC] = 1100;
	OnStart();
}

// �J�n     
void GameResult::OnStart(){
	MapOrder =p_GameManager->get_MapOrder();
	m_ScorePosition = GSvector2(550, 250);

	if (p_GameManager->GetPlayerParameter().m_Remaining < 0)
	{
		//���񂾂Ƃ��̕`��
		m_ResultTextureName = "Over";
		m_SelectTextureName = "Restart";
		gsBindMusic(BGM_GAME_OVER);
	}
	else
	{
		//����łȂ��Ƃ�csv�̔ԍ��ǉ�
		m_ResultTextureName = "Clear";
		m_SelectTextureName = "NextStage";
		gsBindMusic(BGM_GAME_CLER);
	}
}

// �X�V     
void GameResult::OnUpdate(float deltaTime){
	
	//BGM�Đ�
	if (p_GameManager->GetPlayerParameter().m_Remaining < 0)
	{
		gsPlayMusic(BGM_GAME_OVER);

	}
	else
	{
		gsPlayMusic(BGM_GAME_CLER);
	}

	////�ŏI�X�e�[�W�ŃQ�[���N���A��
	//if (p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_B) &&
	//	CarsorMovement == 0 &&
	//	MapOrder == 7&&
	//	this->isGameClear == true)
	//{
	//	
	//	return;
	//}

	//���̃X�e�[�W�ɍs�����^�C�g���ɖ߂邩
	if (p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_B) &&
		CarsorMovement == 0 &&
		MapOrder <= 7)
	{
		if ((isGameClear == true)&&(this->MapOrder == 7)) { 
			p_World->EndRequest(SceneName::GameOver);
			return;
		}
		if (m_ResultTextureName == "Clear" && MapOrder < 7)
		{
			MapOrder += 1; 
		}
		p_GameManager->set_MapOrder(MapOrder);
		p_World->EndRequest(SceneName::GamePlay);
		gsPlaySE(SE_DECITION);

		return;
	}

	else if (p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_B) &&
		CarsorMovement == 1){
		MapOrder = 0;
		p_World->EndRequest(SceneName::GameTitle);
		gsPlaySE(SE_BACK);
	}

	//�J�[�\���ړ�
	if (p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_LEFT) ||
		p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_RIGHT)){
		if (CarsorMovement == 0)
		{
			CarsorMovement = 1;
		}
		else
		{
			CarsorMovement = 0;
		}
	}

	
}

void GameResult::OnDraw() const
{
	//���̃X�e�[�W�ɍs�����^�C�g���ɖ߂邩
	p_GameManager->GetRenderer2D()->DrawTexture(m_ResultTextureName, GSvector2(0, 0));
	p_GameManager->GetRenderer2D()->DrawTexture(m_SelectTextureName, GSvector2(SCREEN_SIZE.x / 2 - 400, SCREEN_SIZE.y / 2 + 178 ));
	p_GameManager->GetRenderer2D()->DrawTexture("ReturnTitle", GSvector2(SCREEN_SIZE.x / 2 + 128, SCREEN_SIZE.y / 2 + 178));

	//�J�[�\���`��
	if (CarsorMovement == 0)
	{
		p_GameManager->GetRenderer2D()->DrawTexture("Cursor", GSvector2(SCREEN_SIZE.x / 2 - 470, SCREEN_SIZE.y / 2 + 190));
	}
	else
	{
		p_GameManager->GetRenderer2D()->DrawTexture("Cursor", GSvector2(SCREEN_SIZE.x / 2 + 50, SCREEN_SIZE.y / 2 + 190));
	}

	//���U���g�X�R�A�̕`��
	p_GameManager->GetScore()->draw();
	p_GameManager->GetScore()->setPosition(GSvector2(200,200));
	if (m_ResultTextureName == "Clear")
	{
		int StageIndex = MapOrder;
		if (p_GameManager->GetScore()->ReleaseScore() >= StageRankNolma[StageIndex][(int)Rank::RankS])
		{
			p_GameManager->GetRenderer2D()->DrawTexture("RankS", m_ScorePosition);
		}
		else if (p_GameManager->GetScore()->ReleaseScore() >= StageRankNolma[StageIndex][(int)Rank::RankA])
		{
			p_GameManager->GetRenderer2D()->DrawTexture("RankA", m_ScorePosition);
		}
		else if (p_GameManager->GetScore()->ReleaseScore() >= StageRankNolma[StageIndex][(int)Rank::RankB])
		{
			p_GameManager->GetRenderer2D()->DrawTexture("RankB", m_ScorePosition);
		}
		else if (p_GameManager->GetScore()->ReleaseScore() >= StageRankNolma[StageIndex][(int)Rank::RankC])
		{
			p_GameManager->GetRenderer2D()->DrawTexture("RankC", m_ScorePosition);
		}
	}
}

void GameResult::End()
{
	gsStopMusic(BGM_GAME_CLER);
	gsStopMusic(BGM_GAME_OVER);
}
