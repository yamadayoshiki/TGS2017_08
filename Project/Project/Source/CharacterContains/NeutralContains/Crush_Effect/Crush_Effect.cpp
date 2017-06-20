#include "Crush_Effect.h"
#include"../../../Base/GameManagerContains/GameManager/GameManager.h"
#include"../../../Utility/Rederer2D/Renderer2D.h"
#include"../../../ActorContains/Transform/Transform.h"

//�R���X�g���N�^
Crush_Effect::Crush_Effect(IWorld * world, const GSvector2 & position, IGameManagerPtr gameManager)
	:Actor(world, ActorName::Crush, position, gameManager)
{
	p_Renderer = gameManager->GetRenderer2D();
}

//�f�X�g���N�^
Crush_Effect::~Crush_Effect()
{
	delete p_AnimationTexture;
}

//������
void Crush_Effect::initialize()
{
	//�A�j���[�V�����̃p�����[�^�̐ݒ�
	Animation* animation = new Animation(*p_Renderer->GetTextureRect("Crush"), 32, 3);
	p_AnimationTexture = new AnimationTexture("Crush", p_Renderer, animation);
	p_AnimationTexture->Initialize();
}

//�X�V����
void Crush_Effect::onUpdate(float deltaTime)
{
	//�A�j���[�V�����̍X�V
	p_AnimationTexture->Update(deltaTime);

	if (p_AnimationTexture->GetLoopCount() >= 1) {
		//���S
		dead();
	}
}

//�`�揈��
void Crush_Effect::onDraw()const
{
	//�A�j���[�V�����̃p�����[�^�̐ݒ�
	p_AnimationTexture->GetParameter()->SetPosition(p_Transform->m_Position);
	p_AnimationTexture->GetParameter()->SetRotate(p_Transform->m_Angle - 90);
	p_AnimationTexture->GetParameter()->SetCenter({ 16.0f, 16.0f });
	p_AnimationTexture->GetParameter()->SetScale({ 1.0f , 1.0f });
	p_AnimationTexture->GetParameter()->SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });
	//�A�j���[�V�����̕`��
	p_AnimationTexture->Draw();
}