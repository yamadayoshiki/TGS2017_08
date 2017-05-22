#include "EnemyCommandStraight.h"
#include "../../../../../Utility/FourDirection/FourDirection.h"
#include "../../../Enemys/Base/EnemyBase.h"
#include "../../../../../WorldContains/IWorld.h"
#include "../../../../../Map/Map.h"
#include "../../../../../Define/Def_GSvector2.h"
#include"../../../../../Define/Def_Nakayama.h"	//for CHIP_SIZE
#include "../../../../../Define/Def_Float.h"	//for FLOAT_EPSILON
#include "../../../../../Map/MapType.h"

//�R���X�g���N�^
EnemyCommandStraight::EnemyCommandStraight(const EnemyBasePtr& enemy, const FourDirection front, const MapType type)
	: EnemyCommandBase(enemy)
	, m_NextTargetPos(GSVECTOR2_ZERO)
	, m_CurFront(front)
	, m_Type(type) {
	//SetNextTargetPos();
}

void EnemyCommandStraight::Initialize()
{
	SetNextTargetPos();

}

//�X�V
void EnemyCommandStraight::Update(float deltaTime) {
	//�ڕW�n�_�܂ł̋���
	m_Velocity = m_NextTargetPos - p_Enemy->getPosition();
	//�ڕW�n�_�ɂ��ǂ蒅���Ă��邩
	if (m_Velocity.length() <= FLOAT_EPSILON)
	{
		HitWallReaction();
		SetNextTargetPos();
	}
}

//�I��
void EnemyCommandStraight::Finalize() {

}

//�e��ŗL�̏�����
void EnemyCommandStraight::OnInitialize() {

}

//���ʂɕǂ��������ꍇ�̃��A�N�V����
void EnemyCommandStraight::HitWallReaction() {
	TurnBack();
}

//�܂�Ԃ�
void EnemyCommandStraight::TurnBack() {
	//���ʂ𔽓]
	m_CurFront.TurnOver();
}

//���ʂɕǂ����邩
bool EnemyCommandStraight::CheckFrontWall() {
	//���ʂ̌�����FourDirection	�ɒu������
	FourDirection front = FourDirection(p_Enemy->getTransform().m_Angle);
	//�����̎��ӂ̃^�C���f�[�^�z��
	std::unordered_map<FourDirection, TileData> mapDate
		= p_Enemy->getWorld()->GetMap().GetAroundTile(p_Enemy->getPosition());
	//���ʂɕǂ����邩
	if (mapDate[front].Flag() == 1)
		return true;
	else
		return false;
}

//���̖ڕW�n�_��ݒ肷��
void EnemyCommandStraight::SetNextTargetPos() {
	//���ʂ̃}�b�v�z��
	std::vector<int> line = GetFrontMapData(m_CurFront.name, m_Type);

	//�i�s�\�}�X��
	int chipNum = 0;

	//���ʉ��}�X�ڂ܂Ői�߂邩
	for (int i = 0; i < line.size(); i++)
	{
		//�ǃ}�X��
		if (line[i] == 1)
			break;

		else
			chipNum++;
	}

	//�i�s�x�N�g��
	GSvector2 frontVector = m_CurFront.GetVector2();
	frontVector = frontVector * (CHIP_SIZE* ((int)m_Type + 1)) * chipNum;
	//���̖ڕW�n�_�̐ݒ�
	m_NextTargetPos = p_Enemy->getPosition() + frontVector;
}