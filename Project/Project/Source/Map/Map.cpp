#include"Map.h"
#include "../Utility/PathFinder/Point2.h"

//�R���X�g���N�^
Map::Map()
{

}
//���[�h
void Map::Load()
{
}
//�A�����[�h
void Map::Unload()
{
}
//�X�V
void Map::Update(float deltaTime)
{
}
//�`��
void Map::Draw() const
{
}
//�Փ˔���
void Map::Collide()
{
}

std::vector<std::vector<int>> Map::getmap()
{
	return m_Map;
}

//�_��
// �f�[�^�̎擾
int Map::operator [] (const Point2& position) const{
	return m_Map[position.y][position.x];
}
// ���̎擾
int Map::Width() const {
	return 17;
}

// �����̎擾
int Map::Height() const {
	return 13;
}