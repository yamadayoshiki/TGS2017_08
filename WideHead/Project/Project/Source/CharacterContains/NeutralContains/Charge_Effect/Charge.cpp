#include "Charge.h"
#include"../../../Base/GameManagerContains/GameManager/GameManager.h"
#include"../../../Utility/Rederer2D/Renderer2D.h"
#include "../../../ActorContains/Transform/Transform.h"
#include"../../PlayerContains/Player/Player.h"
#include"../../../Utility/Texture2DParameter/Texture2DParameter.h"

Charge::Charge(IWorld * world, const GSvector2 & position, const IGameManagerPtr & gameManager, const Player_WPtr& player)
	:Actor(world, ActorName::Charge, position, gameManager),
	p_Player(player) {
}

//�f�X�g���N�^
Charge::~Charge()
{
	delete p_AnimationTexture;
}
//������
void Charge::onInitialize()
{
	m_Charge_Stage = Charge_Stage::Zero;
	p_Player.lock()->getParameter().m_ChargeConter = 0.0f;
	p_Player.lock()->getParameter().m_ChargePower = 0;
	p_Player.lock()->getParameter().Chargeflag = false;


	//�e�N�X�`���̌��݂̖��O�̐ݒ�
	m_CurrrentName = "Charge0";
	m_PreviosName = m_CurrrentName;

	//�A�j���[�V�����̃p�����[�^�̐ݒ�
	p_AnimationTexture = new AnimationTexture(m_CurrrentName, p_GameManager->GetDrawManager(), DrawOrder::Effect_Front, 64, 3);
	p_AnimationTexture->Initialize();
}

//�X�V����
void Charge::onUpdate(float deltaTime)
{
	//�`���[�W�i�K�̍X�V
	ChargeUpdate();
	//�v���C���[�̃g�����X�t�H�[�����擾
	p_Transform = p_Player.lock()->getTransform();
	//�A�j���[�V�����̍X�V
	p_AnimationTexture->Update(deltaTime);
	//�t���O��false�Ȃ玀�S����
	if (p_Player.lock()->getParameter().getCreateFlag() == false) {
		//���S
		dead();
	}
}

//�`�揈��
void Charge::onDraw()const
{
	p_AnimationTexture->GetParameter()->m_Position = p_Transform->m_Position + p_Player.lock()->getTransform()->GetForward() * 4;
	p_AnimationTexture->GetParameter()->m_Rotate = p_Transform->m_Angle;
	p_AnimationTexture->GetParameter()->m_Center = { 32.0f, 32.0f };
	p_AnimationTexture->GetParameter()->m_Scale = { 1.0f , 1.0f };
	p_AnimationTexture->GetParameter()->m_Color = { 1.0f, 1.0f, 1.0f, 1.0f };
}

//�`���[�W�i�K�̍X�V
void Charge::ChargeUpdate()
{
	switch (p_Player.lock()->getParameter().getChargePower())
	{
	case Charge_Stage::Zero:
		m_PreviosName = m_CurrrentName;
		m_CurrrentName = "Charge0";
		break;

	case Charge_Stage::Frist:
		m_PreviosName = m_CurrrentName;
		m_CurrrentName = "Charge1";
		p_Player.lock()->getParameter().Chargeflag = true;
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
	delete p_AnimationTexture;
	p_AnimationTexture = new AnimationTexture(m_CurrrentName, p_GameManager->GetDrawManager(), DrawOrder::Effect_Front, 64, 3);
	//p_AnimationTexture->Initialize();
}
