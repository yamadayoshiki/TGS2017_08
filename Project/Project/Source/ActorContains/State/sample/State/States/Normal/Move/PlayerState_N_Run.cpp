#include "PlayerState_N_Run.h"

#include "../../../../PlayerMotionID.h"

// �R���X�g���N�^
PlayerState_N_Run::PlayerState_N_Run(Vector3& pos, Matrix& mat) : PlayerState_N_MoveBase(pos, mat) {}

// �e��ԓƎ��̏�����
void PlayerState_N_Run::onUniqueInit(Actor & actor){
	// ���[�V�����̕ύX
	change_motion(actor, PlayerMotionID::NORMAL_RUN);
}

// �e��ԓƎ��̏�����
void PlayerState_N_Run::onUpdate(Actor & actor, float deltaTime){
	// �ړ�����
	move(actor, deltaTime, 1.5f);
}


