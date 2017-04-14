#include "PlayerState_A_Walk.h"

#include "../../../../PlayerMotionID.h"

// �R���X�g���N�^
PlayerState_A_Walk::PlayerState_A_Walk(Vector3 & pos, Matrix & mat) : PlayerState_A_MoveBase(pos, mat) {}

// �e��ԓƎ��̏�����
void PlayerState_A_Walk::onUniqueInit(Actor & actor) {
	// ���[�V�����̕ύX
	change_motion(actor, PlayerMotionID::AWAKE_WALK);
}

// �e��ԓƎ��̏�����
void PlayerState_A_Walk::onUpdate(Actor & actor, float deltaTime) {
	// �ړ�����
	move(actor, deltaTime, 1.0f);
}
