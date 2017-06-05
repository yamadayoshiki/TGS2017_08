#include "EnemyCommandMoveBase.h"
#include "../../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../../../Define/Def_Float.h"
#include "../../../../../../../Define/Def_GSvector2.h"
#include "../../../../../../../Map/Map.h"

//�R���X�g���N�^
EnemyCommandMoveBase::EnemyCommandMoveBase(
	const EnemyBasePtr & enemy,
	const MapType type)
	: EnemyCommandBase(enemy)
	, m_Type(type)
	, m_NextTargetPos(GSVECTOR2_ZERO){
}

//�e��ŗL�̏�����
void EnemyCommandMoveBase::OnInitialize(){
	//�ړI�n�ݒ�
	SetNextTargetPos();
}

//�e��ŗL�̍X�V
void EnemyCommandMoveBase::OnUpdate(float deltaTime){
	//�ڕW�n�_�܂ł̋���
	m_Velocity = m_NextTargetPos - p_Enemy.lock()->getPosition();
	//�ڕW�n�_�ɂ��ǂ蒅���Ă��邩
	if (m_Velocity.length() <= FLOAT_EPSILON)
		//�ڕW�n�_�ɓ����������A�N�V����
		ArriveReaction();
}