#include "EnemyCommandAlongWallMove.h"
#include "../../../../../../../Define/Def_GSvector2.h"
#include "../../../../../../../WorldContains/IWorld.h"
#include "../../../../../../../Define/Def_Float.h"
#include "../../../../../../../TargetPosition/TargetPosition.h"
#include "../../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../../../ActorContains/Transform/Transform.h"

//�R���X�g���N�^
EnemyCommandAlongWallMove::EnemyCommandAlongWallMove(
	const EnemyBasePtr& enemy,
	const MapType type,
	const TurnDirection turnDirection)
	: EnemyCommandMoveBase(enemy, type)
	, m_TurnDirection(turnDirection)
	, p_TargetPosition(nullptr) {
	p_TargetPosition = new TargetPosition(p_Enemy.lock()->getWorld()->GetMap(), turnDirection, type);
}

//�f�X�g���N�^
EnemyCommandAlongWallMove::~EnemyCommandAlongWallMove() {
	delete p_TargetPosition;
}

//�I��
void EnemyCommandAlongWallMove::Finalize() {
	p_TargetPosition->Clear();
}

//�e��ŗL�̏�����
void EnemyCommandAlongWallMove::OnInitialize() {
	Finalize();
	p_TargetPosition->AlongWall(p_Enemy.lock()->getPosition(), FourDirection(p_Enemy.lock()->getTransform()->m_Angle));
	m_NextTargetPos = p_TargetPosition->GetNextPos();
}

//�e��ŗL�̍X�V
void EnemyCommandAlongWallMove::OnUpdate(float deltaTime) {
	//�ڕW�n�_�܂ł̋���
	m_Velocity = m_NextTargetPos - p_Enemy.lock()->getPosition();
	//�ڕW�n�_�ɂ��ǂ蒅���Ă��邩
	if (m_Velocity.length() <= FLOAT_EPSILON) {
		ArriveReaction();
	}
}

//�ڕW�n�_�ɓ����������A�N�V����
void EnemyCommandAlongWallMove::ArriveReaction() {
	//�ڕW�n�_�̍X�V
	SetTargetPos();
}

//�ڕW�n�_�̐ݒ�
void EnemyCommandAlongWallMove::SetTargetPos() {
	p_TargetPosition->AlongWall();
	p_TargetPosition->Arrival();
	m_NextTargetPos = p_TargetPosition->GetNextPos();
	m_Velocity = m_NextTargetPos - p_Enemy.lock()->getPosition();
}