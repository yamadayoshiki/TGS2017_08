#include "PlayerState_N_Guard.h"

#include "../../PlayerState_Enum.h"
#include "../../../PlayerMotionID.h"
#include "../../../../../../Input/InputMgr.h"

// �R���X�g���N�^
PlayerState_N_Guard::PlayerState_N_Guard(Vector3 & pos, Matrix & mat) : PlayerState(pos, mat){}

// �e��ԓƎ��̏�����
void PlayerState_N_Guard::unique_init(Actor & actor){
	// ���[�V�����̕ύX
	//change_motion(actor, PlayerMotionID::);
}

// �X�V����
void PlayerState_N_Guard::update(Actor & actor, float deltaTime) {
	// �A�j���[�V�������I��������ҋ@��ԂɑJ��
	if (actor.getAnim().isAnimEnd()) change(PlayerState_Enum::N_IDLE);
}


// �Փ˔���
void PlayerState_N_Guard::collide(const Actor & other) {
	if (other.getName() == "Enemy_AttackRange") {
		//change(PlayerState_Enum::);
	}
}

// �I�����̏���
void PlayerState_N_Guard::end(){}

// ���͏���
void PlayerState_N_Guard::input(){
	// �o����Ԃɐ؂�ւ�
	if (awake_pad()) change(PlayerState_Enum::AWAKE);
	// �K�[�h����
	else if (!InputMgr::GetInstance().IsButtonOn(Buttons::BUTTON_L1)) change(PlayerState_Enum::N_IDLE);
}

