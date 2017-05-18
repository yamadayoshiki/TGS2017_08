#include "EnemyStateBase.h"
#include "../../../Enemys/Base/EnemyBase.h"
#include "../../../../../Utility/MathSupport/MathSupport.h"
#include "../../../CommandContains/CommandManagers/Interface/IEnemyCommandManager.h"

//�R���X�g���N�^
EnemyStateBase::EnemyStateBase(const EnemyBasePtr& enemy)
	: p_Enemy(enemy) {
}

// ���͏���
void EnemyStateBase::input() {
}

//�ړ�����
void EnemyStateBase::Move(float deltaTime, float speed)
{
	//�ړI�n�܂ł̃x�N�g��
	GSvector2 targetVector = p_Enemy->GetCommandManager()->GetCommandVector();

	//���͂��Ȃ��ꍇ��return
	if (targetVector == GSvector2(0.0f, 0.0f))
		return;

	//�ړ��x�N�g�����Z�o
	GSvector2 move = targetVector.getNormalized() * speed * deltaTime;
	if (move.length() > targetVector.length())
		move = targetVector;

	//�ړ��x�N�g�������Ɍ�����ϊ�,�{�̂ɐݒ�
	p_Enemy->setAngle(MathSupport::GetVec2ToVec2Angle(move));

	//�ړ�����W�v�Z
	move = p_Enemy->getPosition() + move;

	//�{�̂ɍ��W��ݒ�
	p_Enemy->setPosition(move);
}

//��]����
void EnemyStateBase::Rotate(float deltaTime)
{
	//���͂��Ȃ��ꍇ��return
	if (p_Enemy->GetCommandManager()->GetCommandRotateAngle() != 0)
		return;

	//��]
}