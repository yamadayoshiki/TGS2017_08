#include "EnemyCommandPatrol.h"
#include "../../../../../../../WorldContains/EventMessage/EventMessage.h"
#include "../../../../../../../WorldContains/IWorld.h"
#include "../../../../../../../Map/Map.h"
#include "../../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../StateContains/StateManager/EnemyStateManager.h"
#include "../../../../../Entity/Enemys/Base/EnemyBase.h"
#include <iterator>
#include <forward_list>

//�R���X�g���N�^
EnemyCommandPatrol::EnemyCommandPatrol(
	const EnemyBasePtr & enemy,
	const MapType type)
	: EnemyCommandMoveBase(enemy, type)
	, m_CurListNum(0) {
}

//�ړI�n��ݒ�
void EnemyCommandPatrol::SetPatrolPos(const std::vector<GSvector2>& posList) {
	m_TargetPosList = std::vector<GSvector2>(posList);
}

//���b�Z�[�W����
void EnemyCommandPatrol::handleMessage(EventMessage message, void * param){
	switch (message)
	{
	case EventMessage::ENEMY_SPIN:
		Change(EnemyCommandName::SpinMove);
		break;
	default:
		break;
	}
}

//�ڕW�n�_�ɓ����������A�N�V����
void EnemyCommandPatrol::ArriveReaction() {
	SetNextTargetPos();
}

//���̖ړI�n��ݒ肷��
void EnemyCommandPatrol::SetNextTargetPos() {
	m_CurListNum++;
	if (m_CurListNum >= m_TargetPosList.size())
		m_CurListNum = 0;

	m_NextTargetPos = m_TargetPosList[m_CurListNum];
}