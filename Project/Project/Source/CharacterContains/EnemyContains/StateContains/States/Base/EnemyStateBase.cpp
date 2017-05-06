#include "EnemyStateBase.h"
#include "../../../Enemys/Base/EnemyBase.h"
#include "../../../../../Utility/MathSupport/MathSupport.h"

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
	//���͂��Ȃ��ꍇ��return
	if (p_Enemy->GetCommandManager()->GetCommandVector() != GSvector2(0.0f, 0.0f))
		return;

	//�ړ��x�N�g�����Z�o
	GSvector2 move = p_Enemy->GetCommandManager()->GetCommandVector().getNormalized() * speed;

	//�ړ��x�N�g�������Ɍ�����ϊ�,�{�̂ɐݒ�
	p_Enemy->getMatrix().setRotationZ(MathSupport::GetAngle(move));

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