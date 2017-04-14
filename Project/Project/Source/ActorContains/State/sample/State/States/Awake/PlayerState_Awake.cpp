#include "PlayerState_Awake.h"

#include "../../PlayerState_Enum.h"
#include "../../../PlayerMotionID.h"
#include "../../../../../../Define.h"

// �R���X�g���N�^
PlayerState_Awake::PlayerState_Awake(Vector3 & pos, Matrix & mat) : PlayerState(pos, mat) {}

// �e��ԌŗL�̏�����
void PlayerState_Awake::unique_init(Actor & actor){
	// ���[�V�����̕ύX(�o���A�j���[�V����)
	change_motion(actor, PlayerMotionID::POWER_UP);
}

// �X�V����
void PlayerState_Awake::update(Actor & actor, float deltaTime) {
	// �d�͂����Z
	mPosition += Vector3::Down * GRAVITY;

	// �A�j���[�V�����I�����A�ҋ@���(�o��)�Ɉڍs
	if (actor.getAnim().isAnimEnd()){
		change(PlayerState_Enum::A_IDLE);
	}
}

// �Փ˔���
void PlayerState_Awake::collide(const Actor & other){}

// �I�����̏���
void PlayerState_Awake::end(){}
