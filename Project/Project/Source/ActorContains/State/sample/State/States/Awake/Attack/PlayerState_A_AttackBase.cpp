#include "PlayerState_A_AttackBase.h"

#include "../../../PlayerState_Enum.h"
#include "../../../../Player_AttackRange.h"
#include "../../../../../../Base/ActorGroup.h"
#include "../../../../../../../Scene/Base/SceneData.h"
#include "../../../../../../../World/World.h"
#include "../../../../../../../Define.h"

// �R���X�g���N�^
PlayerState_A_AttackBase::PlayerState_A_AttackBase(Vector3 & pos, Matrix & mat) : PlayerState(pos, mat), mStartPos(Vector3::Zero) {}

// �e��ԓƎ��̏�����
void PlayerState_A_AttackBase::unique_init(Actor & actor){
	// �U������̐���
	actor.getWorld()->addActor(ActorGroup::PLAYER_ATTACK_RANGE, std::make_shared<Player_AttackRange>(actor.getWorld(), mPosition + Vector3::Up * 20 + actor.getPose().Backward() * 15 * 2));
	// ���W�̑��
	mStartPos = mPosition;
	
	// �p����̊e��ԓƎ��̏�����
	onUniqueInit(actor);
}

// �X�V����
void PlayerState_A_AttackBase::update(Actor & actor, float deltaTime){
	// �d�͂̉��Z
	mPosition += Vector3::Down * GRAVITY;
	// �U�����ɑO���Ɉړ�
	mPosition = Vector3::Lerp(mPosition, mStartPos + actor.getPose().Backward() * 15, 0.4f);

	// �A�j���[�V�������I�������ꍇIDLE�ɑJ��
	if (actor.getAnim().isAnimEnd()) {
		change(PlayerState_Enum::A_IDLE);
	}

	// �̗͂̌���
	actor.getWorld()->getSceneData()->getCurData().status.addDamage(PLAYER_AWAKE_BLOOD_USE);
	if (actor.getWorld()->getSceneData()->getCurData().status.mParams.hp <= 20) {
		change(PlayerState_Enum::NORMAL);
	}
	// �p����̍X�V����
	onUpdate(actor, deltaTime);
}

// �Փ˔���
void PlayerState_A_AttackBase::collide(const Actor & other){
	// �p����̏Փ˔���
	onCollide(other);
}

// �I�����̏���
void PlayerState_A_AttackBase::end(){
	// �p����̏I�����̏���
	onEnd();
}

// ���͏���
void PlayerState_A_AttackBase::input(){
	// �p����̓��͏���
	onInput();
}

