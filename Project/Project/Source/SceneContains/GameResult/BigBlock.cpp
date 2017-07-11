#include "BigBlock.h"

#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../Utility/Rederer2D/Renderer2D.h"

#include "../../Define/Def_Nagano.h"
#include <gslib.h>

//�R���X�g���N�^
BigBlock::BigBlock(const IGameManagerPtr & gameManager)
	:Transition(gameManager){
}

// �f�X�g���N�^
BigBlock::~BigBlock() 
{
}

// �J�n     
void BigBlock::onStart() 
{
	timer_ = 0.0f;
	//�p�����[�^�̐ݒ�
	m_Param.SetPosition(GSvector2(550, 300));
	m_Param.SetRect(*p_GameManager->GetRenderer2D()->GetTextureRect("BigBlock"));
	m_Param.SetCenter({ 0.0f, 0.0f });
	m_Param.SetColor(m_Color);
	m_Param.SetScale({ 1.0f, 1.0f });
	m_Param.SetRotate(0.0f);
}

//�X�V
void BigBlock::onUpdate(float deltaTime) 
{
	if (m_Color.a <= 0.5 || m_Color.a >= 1.0f) {
		m_Alpha = m_Alpha * -1;
	}
	m_Color.a = m_Color.a + m_Alpha;
	m_Param.SetColor(m_Color);

	float posX = gsRandf(-2, 2);
	float posY = gsRandf(-2, 2);
	m_Param.SetPosition(GSvector2(550 + posX, 300 + posY));

	if (timer_ >= 120.0f)
	{
		is_end = true;
	}
	timer_ += deltaTime;
}

//�`��
void BigBlock::onDraw() const 
{
	//�傫���u���b�N�̕`��
	p_GameManager->GetRenderer2D()->DrawTexture("BigBlock", m_Param);
}

bool BigBlock::isEnd() 
{
	return is_end;
}

