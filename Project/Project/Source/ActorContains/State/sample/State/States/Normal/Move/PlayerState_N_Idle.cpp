#include "PlayerState_N_Idle.h"

#include "../../../../PlayerMotionID.h"

// �R���X�g���N�^
PlayerState_N_Idle::PlayerState_N_Idle(Vector3& pos, Matrix& mat) : PlayerState_N_MoveBase(pos, mat){}

// �e��ԌŗL�̏�����
void PlayerState_N_Idle::onUniqueInit(Actor & actor){
	// ���[�V�����̕ύX
	change_motion(actor, PlayerMotionID::NORMAL_IDLE);
}









