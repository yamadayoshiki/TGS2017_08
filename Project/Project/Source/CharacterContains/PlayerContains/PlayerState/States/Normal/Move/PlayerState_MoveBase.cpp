#include"PlayerState_MoveBase.h"
#include"../../../../../../ActorContains/Transform/Transform.h"
#include"../../../../../../ActorContains/BodyContains/Factory/BodyFactory.h"

//�R���X�g���N�^
PlayerState_MoveBase::PlayerState_MoveBase(const Player_WPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player, gameManager) {
}

//�e��ԓƎ��̏�����
void PlayerState_MoveBase::unique_init()
{
	if (p_Player.lock()->getParameter().getCreateFlag() == true) {
		p_Player.lock()->getParameter().Chargeflag = false;
		p_Player.lock()->getParameter().m_CreateFlag = false;
	}
	TextureName_Change("Player_Close");
	p_Player.lock()->getWorld()->GetBodyFactory()->Transform(p_Player.lock()->getBody(), Body::BodyDataName::Player_Close);
	p_Player.lock()->getParameter().m_ClipFlag = false;


	// �p����̊e��ԓƎ��̏�����
	onUniqueInit();
}
//�X�V����
void PlayerState_MoveBase::update(float deltaTaime)
{
	//�ړ��̓��͏�Ԃɂ���ď�Ԃ�ύX(�ҋ@�A����)
	if (p_Input->PadVelocity().length() >= 0.5f) {
		change(PlayerStateName::Walk);
	}
	else if (p_Input->PadVelocity().length() <= 0.0f) {
		change(PlayerStateName::Idle);
	}
	//�p����̍X�V����
	onUpdate(deltaTaime);
}
//�Փ˔���
void PlayerState_MoveBase::collide(const Actor& other, const Body::ContactSet& contactSet)
{
	//�G�Ƃ̏Փˏ���
	Collide(other,contactSet);

	//�p����̏Փˏ���
	onCollide(other,contactSet);
}
//�I������
void PlayerState_MoveBase::end()
{
	//�p����̏I������
	onEnd();
}
//���͏���
void PlayerState_MoveBase::input()
{
	//�A�[�����J��
	if (p_Input->IsPadStateTrigger(GS_XBOX_PAD_B))
		change(PlayerStateName::Open);
	//�_�b�V��
	if (p_Input->IsPadStateTrigger(GS_XBOX_PAD_A) &&
		p_Map.lock()->IsInFrontOfTheWall(
			p_Player.lock()->getPosition(), FourDirection(p_Player.lock()->getTransform()->m_Angle)) == false) {
		change(PlayerStateName::Dash);
	}

	//�p����̓��͏���
	onInput();
}