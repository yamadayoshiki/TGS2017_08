#include "EnemyCommandEnemy01Straight.h"
#include "../../../../../../FrontChipList/FrontChipList.h"
#include "../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../../WorldContains/IWorld.h"
#include "../../../../PlayerWatch/PlayerWatch.h"
#include "../../../../../../Define/Def_Float.h"
#include "../../../../../../Map/Map.h"

//�R���X�g���N�^
EnemyCommandEnemy01Straight::EnemyCommandEnemy01Straight(
	const EnemyBasePtr & enemy)
	: EnemyCommandStraight(enemy, MapType::Double)
	, m_AxisChangeFlag(false) {
}

//�e��ŗL�̏�����
void EnemyCommandEnemy01Straight::OnInitialize() {
	//�ړ����ύX�t���O
	m_AxisChangeFlag = false;
	//�v���C���[�Ƃ̋����x�N�g��
	GSvector2 dis = p_Enemy.lock()->GetPlayerWatch()->GetToPlayerChipDis(MapType::Double);
	//�v���C���[���������
	p_Enemy.lock()->SetDirection(FourDirection(dis));
	//�ړI�n�ݒ�
	SetNextTargetPos();
}

//�e��ŗL�̍X�V
void EnemyCommandEnemy01Straight::OnUpdate(float deltaTime) {
	//�v���C���[�ƍ��W������v���Ă��邩
	if (m_AxisChangeFlag == false)
		CheckAxisEnemyToPlayer();

	//�e�N���X�̍X�V
	EnemyCommandStraight::OnUpdate(deltaTime);
}

//�ڕW�n�_�ɓ����������A�N�V����
void EnemyCommandEnemy01Straight::ArriveReaction() {
	//�v���C���[�Ƃ̎�����v�����ꍇ
	if (m_AxisChangeFlag == true)
	{
		Change(EnemyCommandName::Straight);
		return;
	}

	else
		HitWallReaction();
}

//���ʂɕǂ��������ꍇ�̃��A�N�V����
void EnemyCommandEnemy01Straight::HitWallReaction() {
	//���ʂ̃}�b�v�z��
	FrontChipList list
		= FrontChipList(
			p_Enemy.lock()->getWorld()->GetMap(),
			p_Enemy.lock()->getPosition(),
			p_Enemy.lock()->GetDirection(),
			m_Type);

	//���ʃ}�b�v�̋󂫃}�X���Ȃ������ꍇ�t����������
	if (list.GetSpeaceExist() == false)
		EnemyCommandStraight::HitWallReaction();
	//�I��R�}���h�ɕύX
	else
		Change(EnemyCommandName::AlongWallMoveShoest);
}

//�v���C���[�ƍ��W������v���Ă��邩
void EnemyCommandEnemy01Straight::CheckAxisEnemyToPlayer() {
	//�}�X�����œ����ɂ��邩
	GSvector2 dis
		= p_Enemy.lock()->GetPlayerWatch()->GetToPlayerChipDis(MapType::Double);
	if (p_Enemy.lock()->GetDirection().GetVector2().x == 0)
		if (abs(dis.y) <= FLOAT_EPSILON)
			m_AxisChangeFlag = true;

	if (p_Enemy.lock()->GetDirection().GetVector2().y == 0)
		if (abs(dis.x) <= FLOAT_EPSILON)
			m_AxisChangeFlag = true;

	if (m_AxisChangeFlag == true)
		m_NextTargetPos
		= p_Enemy.lock()->getWorld()->
		GetMap().GetTilePos(p_Enemy.lock()->getPosition(), MapType::Double);
}