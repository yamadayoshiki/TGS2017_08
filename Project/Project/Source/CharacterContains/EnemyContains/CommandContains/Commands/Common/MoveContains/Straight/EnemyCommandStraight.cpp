#include "EnemyCommandStraight.h"
#include "../../../../../../../Utility/FourDirection/FourDirection.h"
#include "../../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../../../WorldContains/IWorld.h"
#include "../../../../../../../Define/Def_GSvector2.h"
#include "../../../../../../../Define/Def_Nakayama.h"	//for CHIP_SIZE
#include "../../../../../../../Define/Def_Float.h"		//for FLOAT_EPSILON
#include "../../../../../../../FrontChipList/FrontChipList.h"
#include "../../../../../../../Map/Map.h"

//�R���X�g���N�^
EnemyCommandStraight::EnemyCommandStraight(
	const EnemyBasePtr& enemy,
	const MapType type)
	: EnemyCommandMoveBase(
		enemy,
		type){
}

//�ڕW�n�_�ɓ����������A�N�V����
void EnemyCommandStraight::ArriveReaction() {
	//���ʂɕǂ��������ꍇ�̃��A�N�V����
	HitWallReaction();
}

//���̖ڕW�n�_��ݒ肷��
void EnemyCommandStraight::SetNextTargetPos() {
	//���ʂ̃}�b�v�z��
	FrontChipList list = FrontChipList(p_Enemy.lock()->getWorld()->GetMap(), p_Enemy.lock()->getPosition(), p_Enemy.lock()->GetDirection(), m_Type);
	//�i�s�x�N�g��
	GSvector2 frontVector = p_Enemy.lock()->GetDirection().GetVector2();
	frontVector = frontVector * (CHIP_SIZE* ((int)m_Type + 1)) * list.GetSpeaceNum();
	//���̖ڕW�n�_�̐ݒ�
	m_NextTargetPos = p_Enemy.lock()->getWorld()->GetMap()->GetTilePos(p_Enemy.lock()->getPosition(), m_Type) + frontVector;
}

//���ʂɕǂ��������ꍇ�̃��A�N�V����
void EnemyCommandStraight::HitWallReaction() {
	//�����𔽓]
	p_Enemy.lock()->SetDirection(p_Enemy.lock()->GetDirection().GetTurnOver());
	//���̖ڕW�n�_��ݒ�
	SetNextTargetPos();
}