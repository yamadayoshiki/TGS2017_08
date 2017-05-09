#include"Map.h"
#include "../Utility/PathFinder/Point2.h"
#include"../Define/Def_Nakayama.h"

//�}�b�v�̎擾
std::vector<std::vector<int>>& Map::getmap()
{
	return m_Map;
}
//����̃^�C���f�[�^�̎擾
std::unordered_map<Tile, TileData> Map::GetAroundTile(const GSvector2& position)
{
	int x = position.x / CHIP_SIZE;
	int y = position.y / CHIP_SIZE;

	TileData left = GetTileData(x -1,y);
	TileData right = GetTileData(x + 1,y);
	TileData top = GetTileData(x,y -1);
	TileData down = GetTileData(x,y +1);
	
	std::unordered_map<Tile, TileData> datas;

	datas[Tile::Left] = left;
	datas[Tile::Right] = right;
	datas[Tile::Top] = top;
	datas[Tile::Down] = down;

	return datas;
}
//�^�C���f�[�^�̎擾
TileData Map::GetTileData(int x, int y)
{
	TileData result;

	result.position = GSvector2(x, y) * CHIP_SIZE;
	result.rectangle = GSrect(0, 0, CHIP_SIZE, CHIP_SIZE);
	result.flag = m_Map[y][x];

	return result;
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