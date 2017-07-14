#include"PlayerState_O_MoveBase.h"
#include"../../../PlayerStateName.h"
#include"../../../../../../ActorContains/ActorGroup.h"
#include"../../../../../NeutralContains/Charge_Effect/Charge.h" 
#include "../../../../../../ActorContains/BodyContains/Elements/ContactSet/ContactSet.h"

//�R���X�g���N�^
PlayerState_O_MoveBase::PlayerState_O_MoveBase(const Player_WPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player,gameManager){}

//�e��ԓƎ��̏�����
void PlayerState_O_MoveBase::unique_init()
{
	if (p_Player.lock()->getParameter().getChargeFlag() == false) {
		p_Player.lock()->getParameter().Chargeflag = true;
		p_Player.lock()->getWorld()->addActor(
			ActorGroup::Effect, 
			std::make_shared<Charge>(
				p_Player.lock()->getWorld(), 
				m_Children[ActorName::Player_Arm]->getPosition(), p_GameManager,p_Player));
	}
	TextureName_Change("Player_Open");
	// �p����̊e��ԓƎ��̏�����
	onUniqueInit();
}
//�X�V����
void PlayerState_O_MoveBase::update(float deltaTaime)
{
	if (p_Input->PadVelocity().length() >= 0.5f) {
		change(PlayerStateName::O_Walk);
	}
	else if (p_Input->PadVelocity().length() <= 0.0f) {
		change(PlayerStateName::O_Idle);
	}

	//�`���[�W
	m_Parameter.Charge(deltaTaime);

	//�p����̍X�V����
	onUpdate(deltaTaime);
}
//�Փ˔���
void PlayerState_O_MoveBase::collide(const Actor& other, const Body::ContactSet& contactSet)
{
	//�A�[���ɓ������Ă�����Ԃ�
	if (m_Children[ActorName::Player_Arm]->isCollide(other).m_IsCollide && is_Scorp_Angle(other)) return;

	//�G�Ƃ̏Փˏ���
	Collide(other,contactSet);

	//�p����̏Փˏ���
	onCollide(other,contactSet);
}
//�I������
void PlayerState_O_MoveBase::end()
{
	//�p����̏I������
	onEnd();
}
//���͏���
void PlayerState_O_MoveBase::input()
{
	if (!p_Input->IsPadState(GS_XBOX_PAD_B)) {
		change(PlayerStateName::Swich);
	}
	//�_�b�V��
	if (p_Input->IsPadStateTrigger(GS_XBOX_PAD_A) ||
		gsGetKeyState(GKEY_Z)) {
		change(PlayerStateName::Dash);
	}
	//�p����̓��͏���
	onInput();
}