#include "PlayerState_N_Attack.h"

#include "../../../../../../../Input/InputMgr.h"

// �R���X�g���N�^
PlayerState_N_Attack::PlayerState_N_Attack(Vector3 & pos, Matrix & mat, PlayerMotionID motion, PlayerState_Enum next)
	: PlayerState_N_AttackBase(pos, mat), mMotion(motion), mNextState(next) {}

// �e��ԓƎ��̏�����
void PlayerState_N_Attack::onUniqueInit(Actor & actor){
	// ���[�V�����̑J��
	change_motion(actor, mMotion);

}

// �X�V����
void PlayerState_N_Attack::onUpdate(Actor & actor, float deltaTime){
	// �U���{�^�����������ꍇ
	if (InputMgr::GetInstance().IsButtonDown(Buttons::BUTTON_CIRCLE)) {
		// �U�����ɂ����ړ��̓��͂��\�ɂ��邱�ƂōU�������̌���
		move(actor, deltaTime, 0.0f);
		// ���̍U���Ɉڍs
		change(mNextState);
	}
}
