#include "PlayerState_A_Jump.h"

#include "../../../../../../Define.h"
#include "../../../../../../Scene/Base/SceneData.h"
#include "../../../../../../World/World.h"
#include "../../PlayerState_Enum.h"
#include "../../../PlayerMotionID.h"

#include <algorithm>

// �R���X�g���N�^
PlayerState_A_Jump::PlayerState_A_Jump(Vector3& pos, Matrix& mat) : PlayerState(pos, mat), mJumpPower(0) {}

// �e��ԌŗL�̏�����
void PlayerState_A_Jump::unique_init(Actor & actor) {
	// ���[�V�����̕ύX
	change_motion(actor, PlayerMotionID::AWAKE_JUMP);
	// �W�����v�͂̏�����
	mJumpPower = PLAYER_JUMP_POWER;
}

// �X�V����
void PlayerState_A_Jump::update(Actor & actor, float deltaTime) {
	// �W�����v�͂̌��Z
	mJumpPower = std::max<float>(mJumpPower - PLAYER_JUMP_DUMP, 0.0f);
	// ���W�ɃW�����v�͂����Z
	mPosition += Vector3::Down * GRAVITY + Vector3::Up * mJumpPower;
	// �ړ��̓��͏���
	move(actor, deltaTime, 2.5f);
	// ���ɐݒu�����܂��͂��W�����v�͂��Ȃ��Ȃ����ꍇ�ɑҋ@��ԂɑJ��
	if (actor.isOnFloor() && mJumpPower == 0) {
		change(PlayerState_Enum::A_IDLE);
	}

	// ���X�ɑ̗͂����炵�Ă���
	actor.getWorld()->getSceneData()->getCurData().status.addDamage(PLAYER_AWAKE_BLOOD_USE);
	if (actor.getWorld()->getSceneData()->getCurData().status.mParams.hp <= 20) {
		change(PlayerState_Enum::NORMAL);
	}
}

// �Փ˔���
void PlayerState_A_Jump::collide(const Actor & other){
	// �U�����ꂽ��_���[�W��ԂɑJ��
	if (other.getName() == "Enemy_AttackRange") {
		change(PlayerState_Enum::DAMAGE);
	}
}

// �I�����̏���
void PlayerState_A_Jump::end() {}

// ���͏���
void PlayerState_A_Jump::input() {}




