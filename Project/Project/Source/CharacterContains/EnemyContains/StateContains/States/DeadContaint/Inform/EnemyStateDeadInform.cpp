#include "EnemyStateDeadInform.h"
#include "../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../../WorldContains/IWorld.h"
#include "../../../../../../WorldContains/EventMessage/EventMessage.h"

// �R���X�g���N�^
EnemyStateDeadInform::EnemyStateDeadInform(
	const EnemyBasePtr & enemy,
	const ActorName name)
	: EnemyStateDeadStandard(enemy)
	, m_Name(name)
{
}

// �e��ŗL�̏�����
void EnemyStateDeadInform::unique_init() {
	switch (m_Name)
	{
	case ActorName::Enemy_02:
		p_Enemy.lock()->getWorld()->sendMessage(EventMessage::ENEMY02_DEAD);
		break;
	}
}