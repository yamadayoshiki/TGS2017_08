#include "EnemyStateMoveStandard.h"
#include "../../../../../CommandContains/CommandManagers/Interface/IEnemyCommandManager.h"
#include "../../../../../Entity/Enemys/Base/EnemyBase.h"

//�R���X�g���N�^
EnemyStateMoveStandard::EnemyStateMoveStandard(const EnemyBasePtr& enemy, const float speed)
	: EnemyStateBase(enemy)
	, EnemyStateMoveBaseStandard(enemy)
	, m_Speed(speed) {
}

//�e��ԌŗL�̏�����
void EnemyStateMoveStandard::onUniqueInit() {
}

// �X�V����
void EnemyStateMoveStandard::onUpdate(float deltaTime) {
	//�����Ȃ��ړ�
	if (p_Enemy.lock()->GetCommandManager()->IsRegard() == false)
		ForwardMove(deltaTime, m_Speed);

	//��������ړ�
	else
		RegardMove(p_Enemy.lock()->GetDirection(), deltaTime, m_Speed);
}