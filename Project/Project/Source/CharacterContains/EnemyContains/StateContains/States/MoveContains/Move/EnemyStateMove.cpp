#include "EnemyStateMove.h"
#include "../../../../CommandContains/CommandManagers/Interface/IEnemyCommandManager.h"
#include "../../../../Entity/Enemys/Base/EnemyBase.h"

//�R���X�g���N�^
EnemyStateMove::EnemyStateMove(const EnemyBasePtr& enemy, const float speed)
	: EnemyStateBase(enemy)
	, EnemyStateMoveBase(enemy)
	, m_Speed(speed) {
}

//�e��ԌŗL�̏�����
void EnemyStateMove::onUniqueInit() {
}

// �X�V����
void EnemyStateMove::onUpdate(float deltaTime) {
	//�����Ȃ��ړ�
	if (p_Enemy.lock()->GetCommandManager()->IsRegard() == false)
		ForwardMove(deltaTime, m_Speed);

	//��������ړ�
	else
		RegardMove(p_Enemy.lock()->GetDirection(), deltaTime, m_Speed);
}