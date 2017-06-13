#include "FrontChipList.h"
#include "../Map/Map.h"
#include <iostream>
#include "../Define/Def_Nakayama.h"
#include "../Utility/CsvConvertTwoDVector/CsvConvertTwoDVector.h"
#include "../Utility/CsvConvertTwoDVector/CsvCellData.h"

//�R���X�g���N�^
FrontChipList::FrontChipList(
	const MapPtr& map,
	const GSvector2 pos,
	const FourDirection front,
	const MapType type)
	: p_Map(map)
	, m_Type(type)
	, m_FrontDirection(front) {
	SetFrontChipList(pos, front);
}

//�f�X�g���N�^
FrontChipList::~FrontChipList() {
}

//�O���}�X�̐ݒ�
void FrontChipList::SetFrontChipList(
	const GSvector2 pos,
	const FourDirection front)
{
	//�����ݒ�
	m_FrontDirection = front;

	//����+�w�ʂ̃}�X��
	int backChipNum = 0;

	switch (front.name)
	{
	case FourDirectionName::Up:
		//�c��Map�z��
		m_List = p_Map.lock()->GetRow(pos, m_Type);
		//�t���ɐ���
		std::reverse(begin(m_List), end(m_List));
		//�������܂߂Ȃ��ォ��̃}�X��
		backChipNum = pos.y / (CHIP_SIZE* ((int)m_Type + 1));
		//�������܂߂��w�ʂ̃}�X��
		backChipNum = p_Map.lock()->GetHeight(m_Type) - backChipNum;
		break;

	case FourDirectionName::Down:
		//�c��Map�z��
		m_List = p_Map.lock()->GetRow(pos, m_Type);
		//�������܂߂��ォ��̃}�X��
		backChipNum = pos.y / (CHIP_SIZE* ((int)m_Type + 1)) + 1;
		break;

	case FourDirectionName::Left:
		//����Map�z��
		m_List = p_Map.lock()->GetColumn(pos, m_Type);
		//�t���ɐ���
		std::reverse(begin(m_List), end(m_List));
		//�������܂߂Ȃ�������̃}�X��
		backChipNum = pos.x / (CHIP_SIZE* ((int)m_Type + 1));
		//�������܂߂��w�ʂ̃}�X��
		backChipNum = p_Map.lock()->GetWidth(m_Type) - backChipNum;
		break;

	case FourDirectionName::Right:
		//����Map�z��
		m_List = p_Map.lock()->GetColumn(pos, m_Type);
		//�������܂߂�������̃}�X��
		backChipNum = pos.x / (CHIP_SIZE* ((int)m_Type + 1)) + 1;
		break;

	default:
		break;
	}

	//�w�ʃ}�X�̍폜
	for (int i = 0; i < backChipNum; i++)
		m_List.erase(m_List.begin());
}

//�󂫃}�X�̗L��
bool FrontChipList::GetSpeaceExist()
{
	for (auto itr = m_List.cbegin(); itr != m_List.cend(); ++itr)
		if (*itr == 0)
			return true;

	return false;
}

//�ǃ}�X�܂ł̐�
int FrontChipList::GetSpeaceNum()
{
	//���ʕϐ�
	int result = 0;
	for (auto itr = m_List.cbegin(); itr != m_List.cend(); ++itr)
	{
		if (*itr == 1)
			break;

		else
			result++;
	}
	return result;
}

//�ǂ̌��������̋󂫃}�X�܂ł̐�
int FrontChipList::GeTheOffSideOfTheWallChipNum()
{
	//���ʕϐ�
	int result = 0;
	//�ǂ���������
	bool flag_1 = false;
	//�ǉz���̋󂫂���������
	bool flag_2 = false;
	for (auto itr = m_List.cbegin(); itr != m_List.cend(); ++itr)
	{
		//�}�X���Z
		result++;
		//�ǂ�
		if (*itr == 1)
			flag_1 = true;
		//�ǉz���̋󂫃}�X��
		else
			if (flag_1 == true) {
				flag_2 = true;
				break;
			}
	}
	//������Ȃ������ꍇ
	if (flag_2 == false)
		result = 0;

	return result;
}

//�ǂɒ��ڐG���܂ł̋����̒���
float FrontChipList::GetToWallLength(const GSvector2 pos, const FourDirection direction, const float width) {
	//�ǂ܂ł̋󂫃}�X�̐�
	int speaceNum = GetSpeaceNum();
	//�����̃}�X�������W
	CsvCellData cellData = CsvConvertTwoDVector::Vector2CnvCsvPos(pos, m_Type);
	GSvector2 cellDataVector2 = GSvector2(cellData.x, cellData.y);
	//�ǎ�O�̋󂫃}�X��csv���W
	GSvector2 speaceCellPos = cellDataVector2 + direction.GetVector2() * speaceNum;
	//�ǎ�O�̋󂫃}�X�̍��W
	GSvector2 position = CsvConvertTwoDVector::CsvPosCnvVector2(speaceCellPos.x*2, speaceCellPos.y*2, m_Type);
	//�P�}�X�̔����̒���
	float half = (CHIP_SIZE * ((int)m_Type + 1)) / 2;
	//�ǂɓ�������W�Z�o
	position = position + (direction.GetVector2() * half) - (direction.GetVector2() * width);
	//�����x�N�g��
	GSvector2 dis = position - pos;
	//4�����ɕ␳
	dis = dis * direction.GetVector2();

	return dis.length();
}