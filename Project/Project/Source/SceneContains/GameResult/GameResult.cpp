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
	:Scene(gameManager) {
}

// �J�n     
void GameResult::OnStart(){
	MapOrder =p_GameManager->get_MapOrder();

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
	/*if (m_ResultTextureName == "Clear")
	{
		gsPlayMusic(BGM_GAME_CLER);
	}
	else
	{
		gsPlayMusic(BGM_GAME_OVER);
	}*/

	//���̃X�e�[�W�ɍs�����^�C�g���ɖ߂邩
	if (p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_B) &&
		CarsorMovement == 0 ) {
		if (m_ResultTextureName == "Clear" && MapOrder != 3) { MapOrder += 1; }
		p_GameManager->set_MapOrder(MapOrder);
		p_World->EndRequest(SceneName::GamePlay);
		gsPlaySE(SE_DECITION);
	}

	else if (p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_B) &&
		CarsorMovement == 1){
		MapOrder = 0;
		p_World->EndRequest(SceneName::GameTitle);
		gsPlaySE(SE_BACK);
	}
	
	//�ŏI�X�e�[�W�ŃQ�[���N���A��
	if (p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_B) &&
		CarsorMovement == 0 &&
		MapOrder > 2)
	{
		p_World->EndRequest(SceneName::GameOver);
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

	//���U���g����
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
		p_GameManager->GetRenderer2D()->DrawTexture("Cursor", GSvector2(SCREEN_SIZE.x / 2 - 450, SCREEN_SIZE.y / 2 + 190));
	}
	else
	{
		p_GameManager->GetRenderer2D()->DrawTexture("Cursor", GSvector2(SCREEN_SIZE.x / 2 + 30, SCREEN_SIZE.y / 2 + 190));
	}

	//���U���g�X�R�A�̕`��
	p_GameManager->GetScore()->draw();
	p_GameManager->GetScore()->setPosition(GSvector2(200,200));
	if (MapOrder == 1 && m_ResultTextureName == "Clear")
	{
		if (p_GameManager->GetScore()->ReleaseScore() >= 300)
		{
			p_GameManager->GetRenderer2D()->DrawTexture("RankS", GSvector2(550, 250));
		}
		else if (p_GameManager->GetScore()->ReleaseScore() >= 250)
		{
			p_GameManager->GetRenderer2D()->DrawTexture("RankA", GSvector2(550, 250));
		}
		else if (p_GameManager->GetScore()->ReleaseScore() >= 200)
		{
			p_GameManager->GetRenderer2D()->DrawTexture("RankB", GSvector2(550, 250));
		}
		else if (p_GameManager->GetScore()->ReleaseScore() >= 100)
		{
			p_GameManager->GetRenderer2D()->DrawTexture("RankC", GSvector2(550, 250));
		}

	}
	if (MapOrder == 2 && m_ResultTextureName == "Clear")
	{
		if (p_GameManager->GetScore()->ReleaseScore() >= 300)
		{
			p_GameManager->GetRenderer2D()->DrawTexture("RankS", GSvector2(550, 250));
		}
		else if (p_GameManager->GetScore()->ReleaseScore() >= 250)
		{
			p_GameManager->GetRenderer2D()->DrawTexture("RankA", GSvector2(550, 250));
		}
		else if (p_GameManager->GetScore()->ReleaseScore() >= 200)
		{
			p_GameManager->GetRenderer2D()->DrawTexture("RankB", GSvector2(550, 250));
		}
		else if (p_GameManager->GetScore()->ReleaseScore() >= 100)
		{
			p_GameManager->GetRenderer2D()->DrawTexture("RankC", GSvector2(550, 250));
		}
	}
}

void GameResult::End()
{
	gsStopMusic(BGM_GAME_CLER);
	gsStopMusic(BGM_GAME_OVER);
}
