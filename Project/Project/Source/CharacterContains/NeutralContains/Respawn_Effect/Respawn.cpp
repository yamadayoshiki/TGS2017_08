#include"Respawn.h"
#include"../../../Base/GameManagerContains/GameManager/GameManager.h"
#include"../../../Utility/Rederer2D/Renderer2D.h"
#include"../../../ActorContains/Transform/Transform.h"

//�R���X�g���N�^
Respawn::Respawn(IWorld* world, const GSvector2& position, IGameManagerPtr gameManager)
	:Actor(world,ActorName::Respawn,position,gameManager)
{
	p_Renderer = gameManager->GetRenderer2D();
}
//�f�X�g���N�^
Respawn::~Respawn()
{
	delete p_AnimationTexture;
}
//������
void Respawn::initialize()
{
	//�A�j���[�V�����̃p�����[�^�̐ݒ�
	Animation* animation = new Animation(*p_Renderer->GetTextureRect("Respawn"), 64, 3);
	p_AnimationTexture = new AnimationTexture("Respawn", p_Renderer, animation);
	p_AnimationTexture->Initialize();
}
//�X�V����
void Respawn::onUpdate(float deltaTime)
{
	//�A�j���[�V�����̍X�V
	p_AnimationTexture->Update(deltaTime);

	if (p_AnimationTexture->GetLoopCount() >= 1) {
		//���S
		dead();
	}
}
//�`�揈��
void Respawn::onDraw()const
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