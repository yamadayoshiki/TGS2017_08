#include "PlayerState_N_Walk.h"

#include "../../../../PlayerMotionID.h"

// �R���X�g���N�^
PlayerState_N_Walk::PlayerState_N_Walk(Vector3 & pos, Matrix & mat) : PlayerState_N_MoveBase(pos, mat) {}

// �e��ԓƎ��̏�����
void PlayerState_N_Walk::onUniqueInit(Actor & actor){
	// ���[�V�����̕ύX
	change_motion(actor, PlayerMotionID::NORMAL_WALK);
}

// �e��ԓƎ��̏�����
void PlayerState_N_Walk::onUpdate(Actor & actor, float deltaTime){
	// �ړ�����
	move(actor, deltaTime, 1.0f);
}

