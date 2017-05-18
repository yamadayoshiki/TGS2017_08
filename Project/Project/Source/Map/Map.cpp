#include"Map.h"
#include "../Utility/PathFinder/Point2.h"
#include"../Define/Def_Nakayama.h"
#include"../Base/GameManagerContains/GameManager/GameManager.h"
#include"../Utility/Rederer2D/Renderer2D.h"
#include <algorithm>
//�R���X�g���N�^
Map::Map(const IGameManagerPtr& gameManager) :
	p_GameManager(gameManager)
{
	p_GameManager->GetRenderer2D()->LoadTexture("chip", "Resource/Texture/wall.png");
}
//�`��
void Map::draw()
{
	// �s�̃��[�v
	for (int i = 0; i < m_Map.size(); i++)
	{
		// ��̃��[�v
		for (int j = 0; j < m_Map[i].size(); j++)
		{
			if (m_Map[i][j] == 1)
			{
				//gsTextPos(j * CHIP_SIZE, i * CHIP_SIZE);
				p_GameManager->GetRenderer2D()->DrawTexture("chip", GSvector2(j, i)* CHIP_SIZE);
			}
		}
	}
}

//�}�b�v�̎擾
std::vector<std::vector<int>>& Map::getmap()
{
	return m_Map;
}

void Map::registMapForPlayer(){
	// �s�̃��[�v
	for (int i = 0; i < m_Map.size(); i += 2)
	{
		std::vector<int> tmp;
		// ��̃��[�v
		for (int j = 0; j < m_Map[i].size(); j += 2)
		{
			tmp.push_back(m_Map[i][j]);
		}
		m_MapForPlayer.push_back(tmp);
	}
}

//����̃^�C���f�[�^�̎擾
std::unordered_map<FourDirection, TileData> Map::GetAroundTile(const GSvector2& position)
{
	int x = position.x / CHIP_SIZE;
	int y = position.y / CHIP_SIZE;

	TileData left = GetTileData(x - 1, y);
	TileData right = GetTileData(x + 1, y);
	TileData top = GetTileData(x, y - 1);
	TileData down = GetTileData(x, y + 1);

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

	for (int i = 0; i < m_Map.size(); i++) {
		tmp.push_back(m_Map[i][x]);
	}

	return tmp;
}

//�w�肳�ꂽ���W�̉����̃u���b�N�̎擾
std::vector<int> Map::GetColumn(const GSvector2 & position) {
	int y = position.y / CHIP_SIZE;

	return m_Map[y];
}

//�^�C���f�[�^�̎擾
TileData Map::GetTileData(int x, int y)
{
	TileData result;

	result.position = GSvector2(x, y) * CHIP_SIZE + GSvector2(CHIP_SIZE / 2, CHIP_SIZE / 2);
	result.rectangle = GSrect(0, 0, CHIP_SIZE, CHIP_SIZE);
	result.flag = m_Map[y][x];

	return result;
}

bool Map::IsInFrontOfTheWall(const GSvector2 & pos, FourDirection direction)
{
	auto tile_deta = GetAroundTile(pos);
	if (tile_deta[direction].Flag() == 1) {
		return true;
	}
	return false;
}

std::unordered_map<FourDirection, TileData> Map::GetAroundTileForPlayer(const GSvector2 & position)
{
	int x = position.x / (CHIP_SIZE * 2);
	int y = position.y / (CHIP_SIZE * 2);

	TileData left = GetTileDataForPlayer(std::max<int>(0, x - 1), y);
	TileData right = GetTileDataForPlayer(std::min<int>(1000, x + 1), y);
	TileData top = GetTileDataForPlayer(x, std::max<int>(0, y - 1));
	TileData down = GetTileDataForPlayer(x, std::min<int>(1000, y + 1));

	std::unordered_map<FourDirection, TileData> datas;

	datas[FourDirection(FourDirectionName::Left)] = left;
	datas[FourDirection(FourDirectionName::Right)] = right;
	datas[FourDirection(FourDirectionName::Up)] = top;
	datas[FourDirection(FourDirectionName::Down)] = down;

	return datas;
}

TileData Map::GetTileDataForPlayer(int x, int y){
	TileData result;

	result.position = GSvector2(x, y) * CHIP_SIZE * 2 + GSvector2(CHIP_SIZE, CHIP_SIZE);
	result.rectangle = GSrect(0, 0, CHIP_SIZE * 2, CHIP_SIZE * 2);
	result.flag = m_MapForPlayer[y][x];

	return result;
}

bool Map::IsInFrontOfTheWallForPlayer(const GSvector2 & pos, FourDirection direction)
{
	auto tile_deta = GetAroundTileForPlayer(pos);
	if (tile_deta[direction].Flag() == 1) {
		return true;
	}
	return false;
}

GSvector2 Map::PushForPlayer(const GSvector2 & current_pos, const GSvector2& target_pos){
	GSvector2 result = target_pos;

	auto deta = GetAroundTileForPlayer(current_pos);

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
	return m_Map[position.y][position.x];
}
// ���̎擾
int Map::GetWidth() const {
	return m_Map[0].size();
}

// �����̎擾
int Map::GetHeight() const {
	return m_Map.size();
}