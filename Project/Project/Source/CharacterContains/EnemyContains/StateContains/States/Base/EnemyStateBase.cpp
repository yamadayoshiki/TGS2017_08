#include "EnemyStateBase.h"
#include "../../../Enemys/Base/EnemyBase.h"
#include "../../../../../Utility/MathSupport/MathSupport.h"
#include "../../../CommandContains/CommandManagers/Interface/IEnemyCommandManager.h"
#include "../../../../../Define/Def_Float.h"
#include "../../../../../WorldContains/IWorld.h"
#include "../../../../../Map/Map.h"
#include "../../../../../Define/Def_GSvector2.h"

//�R���X�g���N�^
EnemyStateBase::EnemyStateBase(const EnemyBasePtr& enemy)
	: p_Enemy(enemy) {
}

// ���͏���
void EnemyStateBase::input() {
}

//�ړ�����
void EnemyStateBase::ForwardMove(float deltaTime, float speed) {
	//�ړ��x�N�g�����Z�o
	GSvector2 move = GetVelocity(deltaTime, speed);

	//���͂��Ȃ��ꍇ��return
	if (move == GSVECTOR2_ZERO)
		return;

	//�ړ��x�N�g�������Ɍ�����ϊ�,�{�̂ɐݒ�
	p_Enemy->setAngle(MathSupport::GetVec2ToVec2Angle(move));

	//�ړ�����W�v�Z
	move = p_Enemy->getPosition() + move;

	//�{�̂ɍ��W��ݒ�
	p_Enemy->setPosition(move);
}

//�����ړ�����
void EnemyStateBase::RegardMove(FourDirection regardDirection, float deltaTime, float speed) {
	//�ړ��x�N�g�����Z�o
	GSvector2 move = GetVelocity(deltaTime, speed);

	//���͂��Ȃ��ꍇ��return
	if (move == GSVECTOR2_ZERO)
		return;

	//�ړ�����W�v�Z
	move = p_Enemy->getPosition() + move;

	//�{�̂ɍ��W��ݒ�
	p_Enemy->setPosition(move);
}

////�����ړ�����(CLAMP����)
//PushDirection EnemyStateBase::RegardMoveClamp(FourDirection regardDirection, float deltaTime, float speed) {
//	//���ʕϐ�
//	FourDirection result;
//
//	//�ړ��x�N�g�����Z�o
//	GSvector2 move = GetVelocity(deltaTime, speed);
//
//	//���͂��Ȃ��ꍇ��return
//	if (move == GSVECTOR2_ZERO)
//		return;
//
//	//�ړ�����W�v�Z
//	move = p_Enemy->getPosition() + move;
//
//	//CLAMP����
//	move = p_Enemy->getWorld()->GetMap().PushForPlayer(p_Enemy->getPosition(), move);
//
//	//�{�̂ɍ��W��ݒ�
//	p_Enemy->setPosition(move);
//}

//�ړ��x�N�g���Z�o
GSvector2 EnemyStateBase::GetVelocity(float deltaTime, float speed) {
	//�ڕW�n�_�܂ł̃x�N�g��
	GSvector2 toTarget = p_Enemy->GetCommandManager()->GetCommandVector();

	//���͂��Ȃ��ꍇ��return
	if (toTarget.length() <= FLOAT_EPSILON)
		return GSVECTOR2_ZERO;

	//�ړ��x�N�g�����Z�o
	GSvector2 move = toTarget.getNormalized() * speed * deltaTime;
	if (move.length() > toTarget.length())
		move = toTarget;

	return move;
}

////��]����
//void EnemyStateBase::Rotate(float deltaTime, float speed) {
//	//�ڕW��]�p�x
//	float targetRotateAngle = p_Enemy->GetCommandManager()->GetCommandRotateAngle();
//
//	//���͂��Ȃ��ꍇ��return
//	if (abs(targetRotateAngle) <= FLOAT_EPSILON)
//		return;
//
//	//��]�p�x���Z�o
//	float rotate = targetRotateAngle = CLAMP(targetRotateAngle, -speed*deltaTime, speed*deltaTime);
//
//	//�{�̂ɉ�]��ݒ�
//	p_Enemy->setAngle(p_Enemy->SetDirection())
//}