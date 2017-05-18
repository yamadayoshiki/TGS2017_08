#include"Map.h"
#include "../Utility/PathFinder/Point2.h"
#include"../Define/Def_Nakayama.h"
#include"../Base/GameManagerContains/GameManager/GameManager.h"
#include"../Utility/Rederer2D/Renderer2D.h"
#include <algorithm>
//�R���X�g���N�^
Map::Map(const IGameManagerPtr& gameManager) :
	p_GameManager(gameManager){
	p_GameManager->GetRenderer2D()->LoadTexture("chip", "Resource/Texture/wall.png");
}

//�`��
void Map::draw(const MapType& type)
{
	// �s�̃��[�v
	for (int i = 0; i < m_Maps[type].size(); i++)
	{
		// ��̃��[�v
		for (int j = 0; j < m_Maps[type][i].size(); j++)
		{
			if (m_Maps[type][i][j] == 1)
			{
				//gsTextPos(j * CHIP_SIZE, i * CHIP_SIZE);
				p_GameManager->GetRenderer2D()->DrawTexture("chip", GSvector2(j, i)* CHIP_SIZE);
			}
		}
	}
}

//�}�b�v�̎擾
MapData& Map::getmap(const MapType& type){
	return m_Maps[type];
}

void Map::regist(const MapData& data, const MapType& type){
	// �s�̃��[�v
	for (int i = 0; i < data.size(); i += ((int)type + 1)) {
		std::vector<int> tmp;
		// ��̃��[�v
		for (int j = 0; j < data[i].size(); j += ((int)type + 1)) {
			tmp.push_back(data[i][j] != 1 ? 0 : 1);
		}
		m_Maps[type].push_back(tmp);
	}
}

//����̃^�C���f�[�^�̎擾
std::unordered_map<FourDirection, TileData> Map::GetAroundTile(const GSvector2& position, const MapType& type)
{
	int x = position.x / (CHIP_SIZE * ((int)type + 1));
	int y = position.y / (CHIP_SIZE * ((int)type + 1));

	TileData left = GetTileData(x - 1, y, type);
	TileData right = GetTileData(x + 1, y, type);
	TileData top = GetTileData(x, y - 1, type);
	TileData down = GetTileData(x, y + 1, type);

	std::unordered_map<FourDirection, TileData> datas;

	datas[FourDirection(FourDirectionName::Left)] = left;
	datas[FourDirection(FourDirectionName::Right)] = right;
	datas[FourDirection(FourDirectionName::Up)] = top;
	datas[FourDirection(FourDirectionName::Down)] = down;

	return datas;
}

//�w�肳�ꂽ���W�̏c���̃u���b�N�̎擾
std::vector<int> Map::GetRow(const GSvector2 & position) {
	int x = position.x / CHIP_SIZE;

	std::vector<int> tmp;

	for (int i = 0; i < m_Maps[MapType::Default].size(); i++) {
		tmp.push_back(m_Maps[MapType::Default][i][x]);
	}

	return tmp;
}

//�w�肳�ꂽ���W�̉����̃u���b�N�̎擾
std::vector<int> Map::GetColumn(const GSvector2 & position) {
	int y = position.y / CHIP_SIZE;

	return m_Maps[MapType::Default][y];
}

//�^�C���f�[�^�̎擾
TileData Map::GetTileData(int column, int row, const MapType& type){
	int size = CHIP_SIZE * ((int)type + 1);
	int x = CLAMP(column, 0, 100000);
	int y = CLAMP(row, 0, 100000);

	TileData result;

	result.position = GSvector2(x, y) * size + GSvector2(1, 1) * size / 2;
	result.rectangle = GSrect(0, 0, size, size);
	result.flag = m_Maps[type][y][x];

	return result;
}

bool Map::IsInFrontOfTheWall(const GSvector2 & pos, FourDirection direction, const MapType& type)
{
	auto tile_deta = GetAroundTile(pos, type);
	if (tile_deta[direction].Flag() == 1) {
		return true;
	}
	return false;
}

GSvector2 Map::PushForPlayer(const GSvector2 & current_pos, const GSvector2& target_pos){
	GSvector2 result = target_pos;

	auto deta = GetAroundTile(current_pos, MapType::Double);

	if (deta[FourDirection(FourDirectionName::Up)].Flag() == 1) {
		result.y = std::max<float>(deta[FourDirection(FourDirectionName::Up)].Position().y + CHIP_SIZE * 2, result.y);
	}
	if (deta[FourDirection(FourDirectionName::Down)].Flag() == 1) {
		result.y = std::min<float>(deta[FourDirection(FourDirectionName::Down)].Position().y - CHIP_SIZE * 2, result.y);
	}
	if (deta[FourDirection(FourDirectionName::Left)].Flag() == 1) {
		result.x = std::max<float>(deta[FourDirection(FourDirectionName::Left)].Position().x + CHIP_SIZE * 2, result.x);
	}
	if (deta[FourDirection(FourDirectionName::Right)].Flag() == 1) {
		result.x = std::min<float>(deta[FourDirection(FourDirectionName::Right)].Position().x - CHIP_SIZE * 2, result.x);
	}

	return result;
}

//�_��
// �f�[�^�̎擾
int Map::operator [] (const Point2& position) const {
	return m_Maps.at(MapType::Default)[position.y][position.x];
}
// ���̎擾
int Map::GetWidth(const MapType& type) const {
	return m_Maps.at(type)[0].size();
}

// �����̎擾
int Map::GetHeight(const MapType& type) const {
	return m_Maps.at(type).size();
}