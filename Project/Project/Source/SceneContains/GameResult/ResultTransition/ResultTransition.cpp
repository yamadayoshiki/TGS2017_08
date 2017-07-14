#include "ResultTransition.h"

#include "../../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../../Utility/Rederer2D/Renderer2D.h"
#include "../../../Utility/Texture2DParameter/Texture2DParameter.h"
#include "../../../Define/Def_Nagano.h"
#include <gslib.h>

//�R���X�g���N�^
ResultTransition::ResultTransition(const IGameManagerPtr & gameManager)
	:Transition(gameManager)
{
}

// �f�X�g���N�^
ResultTransition::~ResultTransition()
{
}

// �J�n     
void ResultTransition::onStart()
{
	m_Timer = 0.0f;
	//�p�����[�^�̐ݒ�
	p_Param->m_Position = m_Position;
	p_Param->m_Rect = *p_GameManager->GetRenderer2D()->GetTextureRect("Player_Image");
	p_Param->m_Center = { 0.0f, 0.0f };
	p_Param->m_Color = m_Color;
	p_Param->m_Scale = { 1.0f, 1.0f };
	p_Param->m_Rotate = 0.0f;
}

//�X�V
void ResultTransition::onUpdate(float deltaTime)
{
	float t = m_Timer / m_Maxtimer;
	GScolor color = m_Color.lerp(GScolor(1.0f, 1.0f, 1.0f, 1.0f), t);
	p_Param->m_Color = color;

	GSvector2 pos = m_Position.lerp(GSvector2(0.0f, 0.0f), t*t);
	p_Param->m_Position = pos;

	if (m_Timer >= 120.0f)
	{
		is_end = true;
	}
	m_Timer = MIN(m_Timer + deltaTime, m_Maxtimer);
}

//�`��
void ResultTransition::onDraw() const
{
	//�傫���u���b�N�̕`��
	p_GameManager->GetRenderer2D()->DrawTexture("Player_Image", p_Param);
}

bool ResultTransition::isEnd()
{
	return is_end;
}
