#include "PlayerState_A_Idle.h"

#include "../../../../PlayerMotionID.h"

// �R���X�g���N�^
PlayerState_A_Idle::PlayerState_A_Idle(Vector3& pos, Matrix& mat) : PlayerState_A_MoveBase(pos, mat) {}

// �e��ԌŗL�̏�����
void PlayerState_A_Idle::onUniqueInit(Actor & actor) {
	// ���[�V�����̕ύX
	change_motion(actor, PlayerMotionID::AWAKE_IDLE);
}








