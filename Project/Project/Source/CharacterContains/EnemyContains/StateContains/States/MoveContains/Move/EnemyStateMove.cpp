#include "EnemyStateMove.h"
#include "../../../../CommandContains/CommandManagers/Interface/IEnemyCommandManager.h"
#include "../../../../Enemys/Base/EnemyBase.h"

//�R���X�g���N�^
EnemyStateMove::EnemyStateMove(const EnemyBasePtr& enemy, const float speed)
	: EnemyStateMoveBase(enemy)
	, m_Speed(speed) {
}

//�e��ԌŗL�̏�����
void EnemyStateMove::onUniqueInit() {
	//�A�j���[�V�����̕ύX

}

// �X�V����
void EnemyStateMove::onUpdate(float deltaTime) {
	if (p_Enemy.lock()->GetCommandManager()->IsRegard() == false)
		ForwardMove(deltaTime, m_Speed);

	else
		RegardMove(p_Enemy.lock()->GetDirection(), deltaTime, m_Speed);
}