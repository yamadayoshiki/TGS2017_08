#include "Charge.h"
#include"../../../Base/GameManagerContains/GameManager/GameManager.h"
#include"../../../Utility/Rederer2D/Renderer2D.h"
#include "../../../ActorContains/Transform/Transform.h"
#include"../../PlayerContains/Player/Player.h"

Charge::Charge(IWorld * world, const GSvector2 & position, const IGameManagerPtr & gameManager, const Player_WPtr& player)
	:Actor(world, ActorName::Charge, position, gameManager),
	p_Player(player)
{
	p_Renderer = gameManager->GetRenderer2D();
}

//�f�X�g���N�^
Charge::~Charge()
{
	delete p_AnimationTexture;
}
//������
void Charge::initialize()
{
	m_Charge_Stage = Charge_Stage::Zero;

	//�e�N�X�`���̌��݂̖��O�̐ݒ�
	m_CurrrentName = "";
	m_PreviosName = m_CurrrentName;

	//�A�j���[�V�����̃p�����[�^�̐ݒ�
	p_Animation = new Animation(*p_Renderer->GetTextureRect(m_CurrrentName), 64, 3);
	p_AnimationTexture = new AnimationTexture(m_CurrrentName, p_Renderer, p_Animation);
	p_AnimationTexture->Initialize();
}

//�X�V����
void Charge::onUpdate(float deltaTime)
{
	//�A�j���[�V�����̍X�V
	p_AnimationTexture->Update(deltaTime);
	//�`���[�W�i�K�̍X�V
	ChargeUpdate();

	p_Transform = p_Player.lock()->getTransform();

	if (p_Player.lock()->getParameter().getChargeFlag() == false) {
		//���S
		dead();
	}
}

//�`�揈��
void Charge::onDraw()const
{
	p_AnimationTexture->GetParameter()->SetPosition(getPosition());
	p_AnimationTexture->GetParameter()->SetRotate(p_Transform->m_Angle);
	p_AnimationTexture->GetParameter()->SetCenter({ 32.0f, 32.0f });
	p_AnimationTexture->GetParameter()->SetScale({ 1.0f , 1.0f });
	p_AnimationTexture->GetParameter()->SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });
	//�A�j���[�V�����̕`��
	p_AnimationTexture->Draw();
}

//�`���[�W�i�K�̍X�V
void Charge::ChargeUpdate()
{
	switch (p_Player.lock()->getParameter().getChargePower())
	{
	case Charge_Stage::Zero:
		break;

	case Charge_Stage::Frist:
		m_PreviosName = m_CurrrentName;
		m_CurrrentName = "Charge1";
		break;

	case Charge_Stage::Second:
		m_PreviosName = m_CurrrentName;
		m_CurrrentName = "Charge2";
		break;

	case Charge_Stage::Third:
		m_PreviosName = m_CurrrentName;
		m_CurrrentName = "Charge3";
		break;
	}

	if (m_CurrrentName == m_PreviosName) return;
	//�A�j���[�V�����̃p�����[�^�̍Đݒ�
	p_Animation = new Animation(*p_Renderer->GetTextureRect(m_CurrrentName), 64, 3);
	p_AnimationTexture->setName_Animation(m_CurrrentName, p_Animation);
}

