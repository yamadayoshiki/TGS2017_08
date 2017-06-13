#include "EnemyCommandStraightTouchWall.h"
#include "../../../../../../../FrontChipList/FrontChipList.h"
#include "../../../../../../../Define/Def_Nakayama.h"	//for CHIP_SIZE
#include "../../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../../../WorldContains/IWorld.h"

//�R���X�g���N�^
EnemyCommandStraightTouchWall::EnemyCommandStraightTouchWall(
	const EnemyBasePtr & enemy,
	const MapType type)
	: EnemyCommandStraight(enemy, type) {
}

//���̖ڕW�n�_��ݒ肷��
void EnemyCommandStraightTouchWall::SetNextTargetPos(){
	//���ʂ̃}�b�v�z��
	FrontChipList list = FrontChipList(p_Enemy.lock()->getWorld()->GetMap(), p_Enemy.lock()->getPosition(), p_Enemy.lock()->GetDirection(), m_Type);
	//���̖ڕW�n�_�̐ݒ�
	m_NextTargetPos = p_Enemy.lock()->getPosition() + (p_Enemy.lock()->GetDirection().GetVector2() * list.GetToWallLength(p_Enemy.lock()->getPosition(),p_Enemy.lock()->GetDirection(),16.0f));
}