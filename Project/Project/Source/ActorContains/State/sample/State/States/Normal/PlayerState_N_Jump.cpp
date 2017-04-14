#include "PlayerState_N_Jump.h"

#include "../../PlayerState_Enum.h"
#include "../../../PlayerMotionID.h"
#include "../../../../../../Define.h"

#include <algorithm>

// �R���X�g���N�^
PlayerState_N_Jump::PlayerState_N_Jump(Vector3& pos, Matrix& mat) : PlayerState(pos, mat),mJumpPower(0) {}

// �e��ԓƎ��̏�����
void PlayerState_N_Jump::unique_init(Actor & actor){
	// ���[�V�����̕ύX
	change_motion(actor, PlayerMotionID::NORMAL_JUMP);
	// �W�����v�͂̏�����
	mJumpPower = PLAYER_JUMP_POWER;
}

// �X�V����
void PlayerState_N_Jump::update(Actor & actor, float deltaTime){
	// �W�����v�͂̌��Z
	mJumpPower = std::max<float>(mJumpPower - PLAYER_JUMP_DUMP, 0.0f);
	// ���W�ɃW�����v�͂����Z
	mPosition += Vector3::Down * GRAVITY + Vector3::Up * mJumpPower;
	// �ړ��̓��͏���
	move(actor, deltaTime, 2.5f);
	// ���ɐݒu�����܂��͂��W�����v�͂��Ȃ��Ȃ����ꍇ�ɑҋ@��ԂɑJ��
	if (actor.isOnFloor() && mJumpPower == 0) {
		change(PlayerState_Enum::N_IDLE);
	}
}

// �Փ˔���
void PlayerState_N_Jump::collide(const Actor & other) {
	// �U�����ꂽ��_���[�W��ԂɑJ��
	if (other.getName() == "Enemy_AttackRange") {
		change(PlayerState_Enum::DAMAGE);
	}
}

// �I�����̏���
void PlayerState_N_Jump::end(){}

// ���͏���
void PlayerState_N_Jump::input(){}





