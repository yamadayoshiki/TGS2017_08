#include "EnemyCommandStraight.h"
#include "../../../../../Utility/FourDirection/FourDirection.h"
#include "../../../Enemys/Base/EnemyBase.h"
#include "../../../../../WorldContains/IWorld.h"
#include "../../../../../Define/Def_GSvector2.h"
#include"../../../../../Define/Def_Nakayama.h"	//for CHIP_SIZE
#include "../../../../../Define/Def_Float.h"	//for FLOAT_EPSILON
#include "../../../../../FrontChipList/FrontChipList.h"
#include "../../../../../Map/Map.h"

//�R���X�g���N�^
EnemyCommandStraight::EnemyCommandStraight(
	const EnemyBasePtr& enemy,
	const MapType type)
	: EnemyCommandBase(enemy)
	, m_NextTargetPos(GSVECTOR2_ZERO)
	, m_Type(type) {
}

//�I��
void EnemyCommandStraight::Finalize() {

}

//�e��ŗL�̏�����
void EnemyCommandStraight::OnInitialize() {
	//�ړI�n�ݒ�
	SetNextTargetPos();
}

//�e��ŗL�̍X�V
void EnemyCommandStraight::OnUpdate(float deltaTime) {
	//�ڕW�n�_�܂ł̋���
	m_Velocity = m_NextTargetPos - p_Enemy->getPosition();
	//�ڕW�n�_�ɂ��ǂ蒅���Ă��邩
	if (m_Velocity.length() <= FLOAT_EPSILON)
		//�ڕW�n�_�ɓ����������A�N�V����
		ArriveReaction();
}

//�ڕW�n�_�ɓ����������A�N�V����
void EnemyCommandStraight::ArriveReaction() {
	//���ʂɕǂ��������ꍇ�̃��A�N�V����
	HitWallReaction();
}

//���ʂɕǂ��������ꍇ�̃��A�N�V����
void EnemyCommandStraight::HitWallReaction() {
	p_Enemy->SetDirection(p_Enemy->GetDirection().GetTurnOver());
	SetNextTargetPos();
}

//���̖ڕW�n�_��ݒ肷��
void EnemyCommandStraight::SetNextTargetPos() {
	//���ʂ̃}�b�v�z��
	FrontChipList list = FrontChipList(p_Enemy->getWorld()->GetMap(), p_Enemy->getPosition(), p_Enemy->GetDirection(), m_Type);
	//�i�s�x�N�g��
	GSvector2 frontVector = p_Enemy->GetDirection().GetVector2();
	frontVector = frontVector * (CHIP_SIZE* ((int)m_Type + 1)) * list.GetSpeaceNum();
	//���̖ڕW�n�_�̐ݒ�
	m_NextTargetPos = p_Enemy->getWorld()->GetMap().GetTilePos(p_Enemy->getPosition(), m_Type) + frontVector;
}