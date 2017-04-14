#include "PlayerState_N_Damage.h"

#include "../../PlayerState_Enum.h"
#include "../../../PlayerMotionID.h"
#include "../../../../../Base/ActorGroup.h"
#include "../../../../../../World/World.h"
#include "../../../../../../Scene/Base/SceneData.h"

// �R���X�g���N�^
PlayerState_N_Damage::PlayerState_N_Damage(Vector3& pos, Matrix& mat) : PlayerState(pos, mat) {}

// �e��ԓƎ��̏�����
void PlayerState_N_Damage::unique_init(Actor & actor){
	// ���[�V�����̕ύX
	change_motion(actor, PlayerMotionID::REACTION);
	// �_���[�W�ɂ��HP�̌��Z
	actor.getWorld()->getSceneData()->getCurData().status.addDamage(5);
}

// �X�V����
void PlayerState_N_Damage::update(Actor & actor, float deltaTime){
	// �A�j���[�V�������I��������ҋ@��ԂɑJ��
	if (actor.getAnim().isAnimEnd()) {
		change(PlayerState_Enum::N_IDLE);
	}
}

// �Փ˔���
void PlayerState_N_Damage::collide(const Actor & other) {}

// �I�����̏���
void PlayerState_N_Damage::end(){}

// ���͏���
void PlayerState_N_Damage::input(){}

