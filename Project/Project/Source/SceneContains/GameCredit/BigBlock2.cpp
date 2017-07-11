#include "BigBlock2.h"

#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../Utility/Rederer2D/Renderer2D.h"

#include "../../Define/Def_Nagano.h"
#include <gslib.h>

//�R���X�g���N�^
BigBlock2::BigBlock2(const IGameManagerPtr & gameManager)
	:Transition(gameManager) {
}

// �f�X�g���N�^
BigBlock2::~BigBlock2()
{
}

// �J�n     
void BigBlock2::onStart()
{
	timer_ = 0.0f;
	//�p�����[�^�̐ݒ�
	m_Param.SetPosition(GSvector2(550, 100));
	m_Param.SetRect(*p_GameManager->GetRenderer2D()->GetTextureRect("BigBlock2"));
	m_Param.SetCenter({ 0.0f, 0.0f });
	m_Param.SetColor(m_Color);
	m_Param.SetScale({ 1.0f, 1.0f });
	m_Param.SetRotate(0.0f);
}

//�X�V
void BigBlock2::onUpdate(float deltaTime)
{
	if (m_Color.a <= 0.5 || m_Color.a >= 1.0f) {
		m_Alpha = m_Alpha * -1;
	}
	m_Color.a = m_Color.a + m_Alpha;
	m_Param.SetColor(m_Color);

	float posX = gsRandf(-2, 2);
	float posY = gsRandf(-2, 2);
	m_Param.SetPosition(GSvector2(550 + posX, 100 + posY));

	if (timer_ >= 120.0f)
	{
		is_end = true;
	}
	timer_ += deltaTime;
}

//�`��
void BigBlock2::onDraw() const
{
	//�傫���u���b�N�̕`��
	p_GameManager->GetRenderer2D()->DrawTexture("BigBlock2", m_Param);
}

bool BigBlock2::isEnd()
{
	return is_end;
}

