#include "Neutral_Explosion.h"
#include"../../../Base/GameManagerContains/GameManager/GameManager.h"
#include"../../../Utility/Rederer2D/Renderer2D.h"
#include"../../../ActorContains/Transform/Transform.h"

//�R���X�g���N�^
Neutral_Explosion::Neutral_Explosion(
	IWorld* world,
	const GSvector2& position,
	IGameManagerPtr gameManager)
	:Actor(world, ActorName::Explosion, position, gameManager) {
	p_Renderer = gameManager->GetRenderer2D();
}

//�f�X�g���N�^
Neutral_Explosion::~Neutral_Explosion()
{
	delete p_AnimationTexture;
}

//������
void Neutral_Explosion::initialize()
{
	//�A�j���[�V�����̃p�����[�^�̐ݒ�
	Animation* animation = new Animation(*p_Renderer->GetTextureRect("Explosion"), 64, 1);
	p_AnimationTexture = new AnimationTexture("Explosion", p_Renderer, animation);
	p_AnimationTexture->Initialize();
}

//�X�V����
void Neutral_Explosion::onUpdate(float deltaTime)
{
	//�A�j���[�V�����̍X�V
	p_AnimationTexture->Update(deltaTime);

	if (p_AnimationTexture->GetLoopCount() >= 1) {
		//���S
		dead();
	}
}

//�`�揈��
void Neutral_Explosion::onDraw()const
{
	//�A�j���[�V�����̃p�����[�^�̐ݒ�
	p_AnimationTexture->GetParameter()->SetPosition(p_Transform->m_Position);
	p_AnimationTexture->GetParameter()->SetRotate(p_Transform->m_Angle - 90);
	p_AnimationTexture->GetParameter()->SetCenter({ 32.0f, 32.0f });
	p_AnimationTexture->GetParameter()->SetScale({ 1.0f , 1.0f });
	p_AnimationTexture->GetParameter()->SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });
	//�A�j���[�V�����̕`��
	p_AnimationTexture->Draw();
}