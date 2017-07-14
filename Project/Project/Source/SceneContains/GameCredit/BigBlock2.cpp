#include "BigBlock2.h"

#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../Utility/Rederer2D/Renderer2D.h"
#include "../../Utility/Texture2DParameter/Texture2DParameter.h"
#include "../../Define/Def_Nagano.h"
#include"../../TextureContains/Texture/Texture.h"
#include <gslib.h>

//�R���X�g���N�^
BigBlock2::BigBlock2(const IGameManagerPtr & gameManager)
	:Transition(gameManager) ,
	p_Texture(std::make_unique<Texture>("BigBlock2",p_GameManager->GetDrawManager(),DrawOrder::UI)){
	//�p�����[�^�̐ݒ�
	p_Texture->GetParameter()->m_Position = GSvector2(550, 300);
	p_Texture->GetParameter()->m_Center = { 0.0f,0.0f };
}

// �f�X�g���N�^
BigBlock2::~BigBlock2()
{
}

// �J�n     
void BigBlock2::onStart()
{
	timer_ = 0.0f;
	p_Texture->GetParameter()->m_Color.a = 1.0f;

}

//�X�V
void BigBlock2::onUpdate(float deltaTime)
{
	if (p_Texture->GetParameter()->m_Color.a <= 0.5 || p_Texture->GetParameter()->m_Color.a >= 1.0f) {
		m_Alpha = m_Alpha * -1;
	}
	p_Texture->GetParameter()->m_Color.a += m_Alpha;

	float posX = gsRandf(-2, 2);
	float posY = gsRandf(-2, 2);
	p_Texture->GetParameter()->m_Position = GSvector2(550 + posX, 100 + posY);

	if (timer_ >= 120.0f)
	{
		is_end = true;
	}
	timer_ += deltaTime;
}

//�`��
void BigBlock2::onDraw() const
{
	////�傫���u���b�N�̕`��
	//p_GameManager->GetRenderer2D()->DrawTexture("BigBlock2", p_Param);
}

bool BigBlock2::isEnd()
{
	return is_end;
}

