#include "TargetPosition.h"
#include "../Define/Def_GSvector2.h"
#include "../Map/Map.h"

//�R���X�g���N�^
TargetPosition::TargetPosition(
	const MapPtr& map,
	const TurnDirection turnDirection,
	const MapType type)
	: m_TurnDirection(turnDirection)
	, p_Map(map)
	, m_Type(type) {
	Clear();
}

//�f�X�g���N�^
TargetPosition::~TargetPosition() {
	Clear();
}

//���̖ړI�n�̎擾
GSvector2 TargetPosition::GetNextPos() {
	if (m_List.size() == 0)
		return GSVECTOR2_ZERO;
	return m_List.cbegin()->position;
}

//�Ō�̖ړI�n�̎擾
GSvector2 TargetPosition::GetLastPos() {
	if (m_List.size() == 0)
		return GSVECTOR2_ZERO;

	return m_List.back().position;
}

//�ڕW�n�_�z��̍ŏ��v�f�̍폜
void TargetPosition::Arrival() {
	m_List.erase(m_List.begin());
}

//�ړI�nList�̃N���A
void TargetPosition::Clear() {
	m_List.clear();
}

//�w��̉�]�������ɐi�߂�}�X������
void TargetPosition::AlongWall(const GSvector2 position, const FourDirection fourDirection) {
	//�����w�肪�Ȃ��ꍇreturn
	if (m_TurnDirection.name == TurnDirectionName::None)
		return;

	//���ʕϐ�
	Move result;
	//�����̎��ӂ̃^�C���f�[�^�z��
	std::unordered_map<FourDirection, TileData> mapDate
		= p_Map.lock()->GetAroundTile(position, m_Type);
	//�i�s�����̋t�����ɕύX
	FourDirection dir = fourDirection;
	dir.TurnOver();
	//�^�C���̃f�[�^
	TileData data;

	//�i�s���������肷��܂�
	while (true)
	{
		//90�x��]
		dir.Turn(m_TurnDirection.GetReversal());
		//�����ɉ������^�C���f�[�^�̎��o��
		data = mapDate[dir];
		//�^�C�����ǂł͂Ȃ���
		if (data.Flag() == 0)
			break;
	}
	result.direction = dir;
	result.position = data.Position();

	//�i�s�����^�C���̍��W��ݒ�
	m_List.push_back(result);
}

//�w��̉�]�������ɐi�߂�}�X������(�A��)
void TargetPosition::AlongWall() {
	AlongWall(m_List.back().position, m_List.back().direction);
}

//����
void TargetPosition::Clone(const TargetPosition& other) {
	m_TurnDirection = other.m_TurnDirection;
	m_List=other.m_List;
	p_Map = other.p_Map;
	m_Type = other.m_Type;
}