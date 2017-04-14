#include "PlayerState_A_Run.h"

#include "../../../../PlayerMotionID.h"

// �R���X�g���N�^
PlayerState_A_Run::PlayerState_A_Run(Vector3& pos, Matrix& mat) : PlayerState_A_MoveBase(pos, mat) {}

// �e��ԓƎ��̏�����
void PlayerState_A_Run::onUniqueInit(Actor & actor) {
	// ���[�V�����̕ύX
	change_motion(actor, PlayerMotionID::AWAKE_RUN);
}

// �e��ԓƎ��̏�����
void PlayerState_A_Run::onUpdate(Actor & actor, float deltaTime) {
	// �ړ�����
	move(actor, deltaTime, 2.0f);
}

