#include "PlayerState_Normal.h"

#include "../../PlayerState_Enum.h"
#include "../../../PlayerMotionID.h"

// �R���X�g���N�^
PlayerState_Normal::PlayerState_Normal(Vector3 & pos, Matrix & mat) : PlayerState(pos, mat){}

// �e��ԓƎ��̏�����
void PlayerState_Normal::unique_init(Actor & actor){
	// ���[�V�����̕ύX
	change_motion(actor, PlayerMotionID::INJURED);
}

// �X�V����
void PlayerState_Normal::update(Actor & actor, float deltaTime){
	// �A�j���[�V�������I��������ҋ@��ԂɑJ��
	if (actor.getAnim().isAnimEnd()) change(PlayerState_Enum::N_IDLE);
}

// �Փ˔���
void PlayerState_Normal::collide(const Actor & other) {}

// �I�����̏���
void PlayerState_Normal::end(){}

// ���͏���
void PlayerState_Normal::input(){}


