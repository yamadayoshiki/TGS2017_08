#include "EnemyCommandStraight.h"
#include "../../../../../Utility/FourDirection/FourDirection.h"
#include "../../../Enemys/Base/EnemyBase.h"
#include "../../../../../WorldContains/IWorld.h"
#include "../../../../../Map/Map.h"
#include "../../../../../Define/Def_GSvector2.h"
#include"../../../../../Define/Def_Nakayama.h"	//for CHIP_SIZE
#include "../../../../../Define/Def_Float.h"	//for FLOAT_EPSILON

//�R���X�g���N�^
EnemyCommandStraight::EnemyCommandStraight(const EnemyBasePtr& enemy, const FourDirection front)
	: EnemyCommandBase(enemy)
	, m_NextTargetPos(GSVECTOR2_ZERO)
	, m_CurFront(front) {
	SetNextTargetPos();
}

//�X�V
void EnemyCommandStraight::Update(float deltaTime) {
	//�ڕW�n�_�܂ł̋���
	m_Velocity = m_NextTargetPos - p_Enemy->getPosition();
	//�ڕW�n�_�ɂ��ǂ蒅���Ă��邩
	if (m_Velocity.length() <= FLOAT_EPSILON) {
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
	//�G�l�~�[�{�̂̍��W
	GSvector2 pos = p_Enemy->getPosition();
	//�}�b�v
	Map& map = p_Enemy->getWorld()->GetMap();
	//����+�w�ʂ̃}�X��
	int backChipNum;
	//���ʐi�s�����̔z��̍쐬
	std::vector<int> line;
	switch (m_CurFront.name)
	{
	case FourDirectionName::Up:
		//�c��Map�z��
		line = map.GetRow(pos);
		//�t���ɐ���
		std::reverse(begin(line), end(line));
		//�������܂߂Ȃ��ォ��̃}�X��
		backChipNum = pos.y / CHIP_SIZE;
		//�������܂߂��w�ʂ̃}�X��
		backChipNum = map.GetHeight() - backChipNum;
		break;

	case FourDirectionName::Down:
		//�c��Map�z��
		line = map.GetRow(pos);
		//�������܂߂��ォ��̃}�X��
		backChipNum = pos.y / CHIP_SIZE + 1;
		break;

	case FourDirectionName::Left:
		//����Map�z��
		line = map.GetColumn(pos);
		//�t���ɐ���
		std::reverse(begin(line), end(line));
		//�������܂߂Ȃ�������̃}�X��
		backChipNum = pos.x / CHIP_SIZE;
		//�������܂߂��w�ʂ̃}�X��
		backChipNum = map.GetWidth() - backChipNum;
		break;

	case FourDirectionName::Right:
		//����Map�z��
		line = map.GetColumn(pos);
		//�������܂߂�������̃}�X��
		backChipNum = pos.x / CHIP_SIZE + 1;
		break;

	default:
		return;
	}

	//�i�s�\�}�X��
	int chipNum = 0;

	//���ʉ��}�X�ڂ܂Ői�߂邩
	for (int i = 0; i < line.size(); i++)
	{
		//�w�ʂ̃}�X�͖���
		if (backChipNum > i)
			continue;

		//�ǃ}�X��
		if (line[i] == 1)
			break;

		else
			chipNum++;
	}

	//�i�s�x�N�g��
	GSvector2 frontVector = m_CurFront.GetVector2()*CHIP_SIZE*chipNum;
	//���̖ڕW�n�_�̐ݒ�
	m_NextTargetPos = pos + frontVector;
}