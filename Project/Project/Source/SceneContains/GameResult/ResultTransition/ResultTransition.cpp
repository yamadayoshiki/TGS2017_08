#include "ResultTransition.h"

#include "../../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../../Utility/Rederer2D/Renderer2D.h"

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
	m_Param.SetPosition(m_Position);
	m_Param.SetRect(*p_GameManager->GetRenderer2D()->GetTextureRect("Player_Image"));
	m_Param.SetCenter({ 0.0f, 0.0f });
	m_Param.SetColor(m_Color);
	m_Param.SetScale({ 1.0f, 1.0f });
	m_Param.SetRotate(0.0f);
}

//�X�V
void ResultTransition::onUpdate(float deltaTime)
{
	float t = m_Timer / m_Maxtimer;
	GScolor color = m_Color.lerp(GScolor(1.0f, 1.0f, 1.0f, 1.0f), t);
	m_Param.SetColor(color);

	GSvector2 pos = m_Position.lerp(GSvector2(0.0f, 0.0f), t*t);
	m_Param.SetPosition(pos);

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
	p_GameManager->GetRenderer2D()->DrawTexture("Player_Image", m_Param);
}

bool ResultTransition::isEnd()
{
	return is_end;
}
