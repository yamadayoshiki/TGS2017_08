#include "EnemyCommandPatrol.h"
#include "../../../../../../../WorldContains/EventMessage/EventMessage.h"
#include "../../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../StateContains/StateManager/EnemyStateManager.h"

//�R���X�g���N�^
EnemyCommandPatrol::EnemyCommandPatrol(
	const EnemyBasePtr & enemy,
	const MapType type)
	:EnemyCommandMoveBase(enemy, type) {
}

//�ڕW�n�_�ɓ����������A�N�V����
void EnemyCommandPatrol::ArriveReaction()
{
}

//���̖ړI�n��ݒ肷��
void EnemyCommandPatrol::SetNextTargetPos()
{
}