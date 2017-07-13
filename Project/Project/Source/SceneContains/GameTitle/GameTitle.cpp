#include "GameTitle.h"
#include <gslib.h>

#include "../SceneName.h"
#include "../../UIContains/UIManager/UIManager.h"
#include "../../ActorContains/ActorGroup.h"
#include"../../WorldContains/World/World.h"
#include "../../Utility/Rederer2D/Renderer2D.h"
#include"../../Utility/Score/Score.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../Define/Def_Nagano.h"
#include"../../Utility/InputState/InputState.h"
#include"../../Utility/Sound/SoundName.h"
#include"../../Utility/Animation/Animation.h"

#include<GSmusic.h>

// �R���X�g���N�^    
GameTitle::GameTitle(const IGameManagerPtr& gameManager)
	:Scene(gameManager) {
	p_Renderer = gameManager->GetRenderer2D();
}

//�f�X�g���N�^
GameTitle::~GameTitle()
{
	delete p_AnimationTexture;
}
//�e�N�X�`���̖��O�̐ݒ�
void GameTitle::setName_TitleAnimation(const std::string & name)
{
	m_Animation = nullptr;
	m_TitleName = name;
	//m_TitleName2 = name;
	m_Animation = new Animation(*p_Renderer->GetTextureRect(name), 50, 2);
	p_AnimationTexture->setName_Animation(name, m_Animation);
	p_AnimationTexture->Initialize();
}
//�A�j���[�V�����̃��[�v�񐔂��擾
unsigned int GameTitle::GetLoopTitleCount()
{
	return p_AnimationTexture->GetLoopCount();
}

// �J�n     
void GameTitle::OnStart() {
	p_GameManager->GetPlayerParameter().setRemaining(3);
	p_GameManager->GetScore()->initialze();
	MapOrder = 0;
	p_GameManager->set_MapOrder(MapOrder);

	gsBindMusic(BGM_GAME_TITLE);
	gsPlayMusic();


	//���O�̐ݒ�
	m_TitleName = "StartLogo";
	//m_TitleName2 = "StartLogo2";

	//�A�j���[�V�����̃p�����[�^�ݒ�
	m_Animation = new Animation(*p_Renderer->GetTextureRect(m_TitleName), 50, 8);
	/*m_Animation = new Animation(*p_Renderer->GetTextureRect(m_TitleName2), 50, 8);*/
	p_AnimationTexture = new AnimationTexture(m_TitleName, p_Renderer, m_Animation);
	//p_AnimationTexture = new AnimationTexture(m_TitleName2, p_Renderer, m_Animation);
	p_AnimationTexture->Initialize();

}

// �X�V
void GameTitle::OnUpdate(float deltaTime) {

	//�A�j���[�V�����̍X�V
	p_AnimationTexture->Update(deltaTime);

	//�Ŕ̓���
	if (TitleSpeed != 0)
	{
		TitleMove();
	}
	//B�{�^���ŃQ�[���v���C��
	if (p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_B) || p_GameManager->GetInputState()->IsKeyTrigger(GKEY_RETURN)) {
		gsPlaySE(SE_DECITION);
		p_World->EndRequest(SceneName::GamePlay);
	}
}

void GameTitle::OnDraw()const
{
	p_GameManager->GetRenderer2D()->DrawTexture("Title", GSvector2(0, 0));
	p_GameManager->GetRenderer2D()->DrawTexture("WideHead", GSvector2(100, TitleSpeed));
	if (TitleSpeed == 0)
	{
		p_GameManager->GetRenderer2D()->DrawTexture("Start", GSvector2(400, 700));
	}

	

	p_AnimationTexture->GetParameter()->SetPosition(GSvector2(450, 700));
	p_AnimationTexture->GetParameter()->SetCenter({ 25.0f, 25.0f });
	p_AnimationTexture->GetParameter()->SetScale({ 1.0f , 1.0f });
	p_AnimationTexture->GetParameter()->SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });
	//�A�j���[�V�����̕`��
	p_AnimationTexture->Draw();

}

void GameTitle::End()
{
	gsStopMusic();
	p_GameManager->set_MapOrder(MapOrder);
}

void GameTitle::TitleMove()
{
	TitleSpeed++;
	TitleSpeed = TitleSpeed + 1;

	if (TitleSpeed == 0)
	{
		TitleSpeed = 0;
	}
}

