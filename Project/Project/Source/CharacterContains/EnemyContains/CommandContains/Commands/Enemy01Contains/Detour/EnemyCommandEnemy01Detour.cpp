#include "EnemyCommandEnemy01Detour.h"
#include "../../../../../../Define/Def_GSvector2.h"
#include "../../../../../../WorldContains/IWorld.h"
#include "../../../../../../ActorContains/Transform/Transform.h"
#include "../../../../../../TargetPosition/TargetPosition.h"
#include "../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../../FrontChipList/FrontChipList.h"
#include "../../../../../../Define/Def_Nakayama.h"
#include "../../../../../../Utility/TurnDirection/TurnDirection.h"
#include "../../../../PlayerWatch/PlayerWatch.h"
#include "../../../../../../Define/Def_Float.h"
#include "../../../../../../ActorContains/Body/Base/IBody.h"
#include "../../../../../../Define/Def_GSvector2.h"
#include "../../../../../../Map/Map.h"

//�R���X�g���N�^
EnemyCommandEnemy01Detour::EnemyCommandEnemy01Detour(
	const EnemyBasePtr & enemy)
	: EnemyCommandAlongWallMove(
		enemy,
		MapType::Double,
		TurnDirection(TurnDirectionName::None))
	, m_AxisChangeFlag(false) {
}

//�f�X�g���N�^
EnemyCommandEnemy01Detour::~EnemyCommandEnemy01Detour() {
}


//�e��ŗL�̏�����
void EnemyCommandEnemy01Detour::OnInitialize() {
	m_AxisChangeFlag = false;
	Finalize();
	p_TargetPosition->Clone(GetTargetPositionManager());
	m_NextTargetPos = p_TargetPosition->GetNextPos();
}

//�e��ŗL�̍X�V
void EnemyCommandEnemy01Detour::OnUpdate(float deltaTime) {
	//�v���C���[�ƍ��W������v���Ă��邩
	if (m_AxisChangeFlag == false)
		CheckAxisEnemyToPlayer();

	//�e�N���X�̍X�V
	EnemyCommandAlongWallMove::OnUpdate(deltaTime);
}

//�ڕW�n�_�ɓ����������A�N�V����
void EnemyCommandEnemy01Detour::ArriveReaction() {
	//�v���C���[�Ƃ̎�����v�����ꍇ
	if (m_AxisChangeFlag == true)
		Change(EnemyCommandName::Straight);

	else
		SetTargetPos();
}


//�ڕW�n�_�̐ݒ�
void EnemyCommandEnemy01Detour::SetTargetPos() {
	p_TargetPosition->Arrival();
	m_NextTargetPos = p_TargetPosition->GetNextPos();

	if (m_NextTargetPos == GSVECTOR2_ZERO)
		Change(EnemyCommandName::Straight);

	else
		m_Velocity = m_NextTargetPos - p_Enemy.lock()->getPosition();
}

//�ڕW�n�_�Ǘ��̐ݒ�
TargetPosition EnemyCommandEnemy01Detour::GetTargetPositionManager() {
	//���v���
	TargetPosition targetPositionClockwise = TargetPosition(p_Enemy.lock()->getWorld()->GetMap(), TurnDirection(TurnDirectionName::Clockwise), MapType::Double);
	targetPositionClockwise.AlongWall(p_Enemy.lock()->getPosition(), p_Enemy.lock()->GetDirection().GetTurnOver());
	//�����v������
	TargetPosition targetPositionAntiClockwise = TargetPosition(p_Enemy.lock()->getWorld()->GetMap(), TurnDirection(TurnDirectionName::AntiClockwise), MapType::Double);
	targetPositionAntiClockwise.AlongWall(p_Enemy.lock()->getPosition(), p_Enemy.lock()->GetDirection().GetTurnOver());
	//�O���}�X
	FrontChipList frontChipList = FrontChipList(p_Enemy.lock()->getWorld()->GetMap(), p_Enemy.lock()->getPosition(), p_Enemy.lock()->GetDirection(), MapType::Double);
	//�S�[���n�_�܂ł̋���
	float dis = frontChipList.GeTheOffSideOfTheWallChipNum() * ((int)MapType::Double + 1)*CHIP_SIZE;
	//�S�[���n�_
	GSvector2 goal = p_Enemy.lock()->getWorld()->GetMap()->GetTilePos(p_Enemy.lock()->getPosition(), MapType::Double) + p_Enemy.lock()->GetDirection().GetVector2() * dis;
	//�S�[���ɂ��ǂ蒅���܂�
	while (true)
	{
		targetPositionClockwise.AlongWall();
		targetPositionAntiClockwise.AlongWall();

		if (targetPositionClockwise.GetLastPos() == goal)
			return targetPositionClockwise;

		else if (targetPositionAntiClockwise.GetLastPos() == goal)
			return targetPositionAntiClockwise;
	}
}

//�v���C���[�ƍ��W������v���Ă��邩
void EnemyCommandEnemy01Detour::CheckAxisEnemyToPlayer() {
	//�}�X�����œ����ɂ��邩
	GSvector2 dis = p_Enemy.lock()->GetPlayerWatch()->GetToPlayerChipDis(MapType::Double);
	if (p_Enemy.lock()->GetDirection().GetVector2().x == 0)
		if (abs(dis.y) <= FLOAT_EPSILON)
			m_AxisChangeFlag = true;

	if (p_Enemy.lock()->GetDirection().GetVector2().y == 0)
		if (abs(dis.x) <= FLOAT_EPSILON)
			m_AxisChangeFlag = true;

	if (m_AxisChangeFlag == true)
		m_NextTargetPos = p_Enemy.lock()->getWorld()->GetMap()->GetTilePos(p_Enemy.lock()->getPosition(),MapType::Double);
}