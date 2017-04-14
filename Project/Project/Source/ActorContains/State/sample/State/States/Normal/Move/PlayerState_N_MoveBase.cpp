#include "PlayerState_N_MoveBase.h"

#include "../../../PlayerState_Enum.h"
#include "../../../../PlayerMotionID.h"
#include "../../../../../../../Define.h"
#include "../../../../../../../Input/InputMgr.h"

// �R���X�g���N�^
PlayerState_N_MoveBase::PlayerState_N_MoveBase(Vector3 & pos, Matrix & mat) : PlayerState(pos, mat) {}

// �e��ԓƎ��̏�����
void PlayerState_N_MoveBase::unique_init(Actor & actor){
	// �p����̊e��ԓƎ��̏�����
	onUniqueInit(actor);
}

// �X�V����
void PlayerState_N_MoveBase::update(Actor & actor, float deltaTime){
	// �d�͂����Z
	mPosition += Vector3::Down * GRAVITY;

	// �ړ��̓��͏�Ԃɂ���ď�Ԃ�ύX�i�ҋ@�A�����A����j
	if (InputMgr::GetInstance().AnalogPadVectorL().Length() <= 0) {
		change(PlayerState_Enum::N_IDLE);
	}
	else if (InputMgr::GetInstance().AnalogPadVectorL().Length() <= 0.5f) {
		change(PlayerState_Enum::N_WALK);
	}
	else {
		change(PlayerState_Enum::N_RUN);
	}

	// �p����̍X�V����
	onUpdate(actor, deltaTime);
}

// �Փ˔���
void PlayerState_N_MoveBase::collide(const Actor & other){
	if (other.getName() == "Enemy_AttackRange") {
		change(PlayerState_Enum::DAMAGE);
	}

	// �p����̏Փ˔���
	onCollide(other);
}

// �I�����̏���
void PlayerState_N_MoveBase::end(){
	// �p����̏I�����̏���
	onEnd();
}

// ���͏���
void PlayerState_N_MoveBase::input(){
	// �W�����v
	if (InputMgr::GetInstance().IsButtonDown(Buttons::BUTTON_CROSS))  change(PlayerState_Enum::N_JUMP);
	// �K�[�h
	else if (InputMgr::GetInstance().IsButtonOn(Buttons::BUTTON_L1)) change(PlayerState_Enum::GUARD);
	// �U��1
	else if (InputMgr::GetInstance().IsButtonDown(Buttons::BUTTON_CIRCLE)) change(PlayerState_Enum::N_ATTACK1);
	// �o����Ԃɐ؂�ւ�
	else if (awake_pad()) change(PlayerState_Enum::AWAKE);
	
	// �p����̓��͏���
	onInput();
}

