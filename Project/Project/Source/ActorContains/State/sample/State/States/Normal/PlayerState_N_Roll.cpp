#include "PlayerState_N_Roll.h"

#include "../../PlayerState_Enum.h"
#include "../../../PlayerMotionID.h"

// �R���X�g���N�^
PlayerState_N_Roll::PlayerState_N_Roll(Vector3 & pos, Matrix & mat) : PlayerState(pos, mat){}

// �e��ԓƎ��̏�����
void PlayerState_N_Roll::unique_init(Actor & actor){
	// ���[�V�����̕ύX
	change_motion(actor, PlayerMotionID::ROLL, 2.0f);
}

// �X�V����
void PlayerState_N_Roll::update(Actor & actor, float deltaTime){
	// �O���Ɉړ�
	mPosition += mRotation.Backward() * 2.0f;
	
	// �A�j���[�V�������I��������ҋ@��ԂɑJ��
	if (actor.getAnim().isAnimEnd()) {
		change(PlayerState_Enum::A_IDLE);
	}
}

// �Փ˔���
void PlayerState_N_Roll::collide(const Actor & other) {}

// �I�����̏���
void PlayerState_N_Roll::end(){}

// ���͏���
void PlayerState_N_Roll::input(){
	// �o����Ԃɐ؂�ւ�
	if (awake_pad()) change(PlayerState_Enum::N_IDLE);
}

