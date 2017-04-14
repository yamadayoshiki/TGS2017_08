#include "PlayerState_N_AttackBase.h"

#include "../../../PlayerState_Enum.h"
#include "../../../../Player_AttackRange.h"
#include "../../../../../../Base/ActorGroup.h"
#include "../../../../../../../World/World.h"
#include "../../../../../../../Define.h"

// �R���X�g���N�^
PlayerState_N_AttackBase::PlayerState_N_AttackBase(Vector3 & pos, Matrix & mat) : PlayerState(pos, mat), mStartPos(Vector3::Zero) {}

// �e��ԓƎ��̏�����
void PlayerState_N_AttackBase::unique_init(Actor & actor){
	// �U������̐���
	actor.getWorld()->addActor(ActorGroup::PLAYER_ATTACK_RANGE, std::make_shared<Player_AttackRange>(actor.getWorld(), mPosition + Vector3::Up * 20 + actor.getPose().Backward() * 15 * 2));
	// ���W�̑��
	mStartPos = mPosition;
	
	// �p����̊e��ԓƎ��̏�����
	onUniqueInit(actor);
}

// �X�V����
void PlayerState_N_AttackBase::update(Actor & actor, float deltaTime){
	// �d�͂̉��Z
	mPosition += Vector3::Down * GRAVITY;
	// �U�����ɑO���Ɉړ�
	mPosition = Vector3::Lerp(mPosition, mStartPos + actor.getPose().Backward() * 15, 0.4f);

	// �A�j���[�V�������I�������ꍇIDLE�ɑJ��
	if (actor.getAnim().isAnimEnd()) {
		change(PlayerState_Enum::N_IDLE);
	}

	// �p����̍X�V����
	onUpdate(actor, deltaTime);
}

// �Փ˔���
void PlayerState_N_AttackBase::collide(const Actor & other){
	// �p����̏Փ˔���
	onCollide(other);
}

// �I�����̏���
void PlayerState_N_AttackBase::end(){
	// �p����̏I�����̏���
	onEnd();
}

// ���͏���
void PlayerState_N_AttackBase::input(){
	// �p����̓��͏���
	onInput();
}

