#include "Charge.h"
#include"../../../Base/GameManagerContains/GameManager/GameManager.h"
#include"../../../Utility/Rederer2D/Renderer2D.h"

Charge::Charge(IWorld * world, const GSvector2 & position, const IGameManagerPtr & gameManager)
	:Actor(world,ActorName::Charge,position,gameManager)
{
	p_Renderer = gameManager->GetRenderer2D();
}

//�f�X�g���N�^
Charge::~Charge()
{
	delete p_AnimationTexture;
	delete p_Animation;
}
//������
void Charge::initialize()
{
	//�e�N�X�`���̖��O�̐ݒ�
	m_Name = "Charge1";
	//�A�j���[�V�����̃p�����[�^�̐ݒ�
	p_Animation = new Animation(*p_Renderer->GetTextureRect(m_Name), 64, 1);
	p_AnimationTexture = new AnimationTexture(m_Name, p_Renderer, p_Animation);
	p_AnimationTexture->Initialize();
}

//�X�V����
void Charge::onUpdate(float deltaTime)
{
	//�A�j���[�V�����̍X�V
	p_AnimationTexture->Update(deltaTime);

	const auto& player = p_World->findActor(ActorName::Player);
	if (player == nullptr)return;
	m_Transform = player->getTransform();
}

//�`�揈��
void Charge::onDraw()const
{
	p_AnimationTexture->GetParameter()->SetPosition(m_Transform.m_Position);
	p_AnimationTexture->GetParameter()->SetRotate(m_Transform.m_Angle - 90);
	p_AnimationTexture->GetParameter()->SetCenter({ 32.0f, 32.0f });
	p_AnimationTexture->GetParameter()->SetScale({ 1.0f , 1.0f });
	p_AnimationTexture->GetParameter()->SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });
	//�A�j���[�V�����̕`��
	p_AnimationTexture->Draw();
}

