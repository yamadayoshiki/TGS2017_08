#include"Map.h"
#include"../Define/Def_Nakayama.h"
#include"../Base/GameManagerContains/GameManager/GameManager.h"
#include"../Utility/Rederer2D/Renderer2D.h"
#include"../WorldContains/EventMessage/EventMessage.h"
#include"TerrainName.h"
#include "../CsvConvertTDV/CsvConvertTDV.h"
#include "CombinationTexture\CombinationTexture.h"
#include "../DrawManager/DrawManager.h"
#include "../Utility/Texture2DParameter/Texture2DParameter.h"
#include <algorithm>
#include <chrono>

//�R���X�g���N�^
Map::Map(const IGameManagerPtr& gameManager) :
	p_GameManager(gameManager) {
	p_GameManager->LoadTexture("chip", "Resource/Texture/wall.png");
}

Map::~Map() {
	p_GameManager->GetDrawManager()->Remove(m_MapDrawID);
}



//�}�b�v�̎擾
CsvTwoDVectorTerrainData& Map::getmap(const MapType& type) {
	return m_Maps[type];
}

void Map::regist(const MapData& data, const MapType& type) {
	/*MaoTypeDouble�ȏ�̏ꍇ����̂ݎ��o��*/
	// �s�̃��[�v
	for (int i = 0; i < data.size(); i += ((int)type + 1)) {
		std::vector<TerrainName> tmp;
		// ��̃��[�v
		for (int j = 0; j < data[i].size(); j += ((int)type + 1)) {
			tmp.push_back(data[i][j] != 1 ? TerrainName::Speace : TerrainName::Wall);
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
std::vector<TerrainName> Map::GetRow(const GSvector2 & position, const MapType& type) {
	int x = position.x / (CHIP_SIZE* ((int)type + 1));

	std::vector<TerrainName> tmp;

	for (int i = 0; i < m_Maps[type].size(); i++) {
		tmp.push_back(m_Maps[type][i][x]);
	}

	return tmp;
}

//�w�肳�ꂽ���W�̉����̃u���b�N�̎擾
std::vector<TerrainName> Map::GetColumn(const GSvector2 & position, const MapType& type) {
	int y = position.y / (CHIP_SIZE* ((int)type + 1));

	return m_Maps[type][y];
}

//�^�C���f�[�^�̎擾
TileData Map::GetTileData(int column, int row, const MapType& type) {
	int size = CHIP_SIZE * ((int)type + 1);
	int x = CLAMP(column, 0, 100000);
	int y = CLAMP(row, 0, 100000);

	TileData result;

	result.position = GSvector2(x, y) * size + GSvector2(1, 1) * size / 2;
	result.rectangle = GSrect(0, 0, size, size);
	result.terrainName = (TerrainName)m_Maps[type][y][x];

	return result;
}

bool Map::IsInFrontOfTheWall(const GSvector2 & pos, FourDirection direction, const MapType& type)
{
	auto tile_deta = GetAroundTile(pos, type);
	if (tile_deta[direction].GetTerrainName() == TerrainName::Wall) {
		return true;
	}
	return false;
}

ResultPushDirection Map::PushForPlayer(
	const GSvector2 & current_pos,
	const GSvector2& target_pos,
	const MapType & charaSize,
	const TerrainName tileNumber) {
	//���ʕϐ�
	ResultPushDirection result;
	result.position = target_pos;
	//���ӂ̃^�C���f�[�^�擾
	auto deta = GetAroundTile(current_pos, charaSize);

	if (deta[FourDirection(FourDirectionName::Up)].GetTerrainName() == tileNumber) {
		result.position.y = std::max<float>(deta[FourDirection(FourDirectionName::Up)].Position().y + CHIP_SIZE * (((int)charaSize) + 1) + 1, result.position.y);
	}
	if (deta[FourDirection(FourDirectionName::Down)].GetTerrainName() == tileNumber) {
		result.position.y = std::min<float>(deta[FourDirection(FourDirectionName::Down)].Position().y - CHIP_SIZE * (((int)charaSize) + 1) - 1, result.position.y);
	}
	if (deta[FourDirection(FourDirectionName::Left)].GetTerrainName() == tileNumber) {
		result.position.x = std::max<float>(deta[FourDirection(FourDirectionName::Left)].Position().x + CHIP_SIZE * (((int)charaSize) + 1) + 1, result.position.x);
	}
	if (deta[FourDirection(FourDirectionName::Right)].GetTerrainName() == tileNumber) {
		result.position.x = std::min<float>(deta[FourDirection(FourDirectionName::Right)].Position().x - CHIP_SIZE * (((int)charaSize) + 1) - 1, result.position.x);
	}

	return result;
}


// �����o������(�}�X����)
ResultPushDirection Map::PushForChara(const GSvector2 & current_pos, const GSvector2 & target_pos, const MapType & charaSize)
{
	//���ʕϐ�
	ResultPushDirection result;
	result.position = target_pos;
	//���ӂ̃^�C���f�[�^�擾
	auto deta = GetAroundTile(current_pos, charaSize);

	if (deta[FourDirection(FourDirectionName::Up)].GetTerrainName() == TerrainName::Wall) {
		result.position.y = std::max<float>(deta[FourDirection(FourDirectionName::Up)].Position().y + CHIP_SIZE * (((int)charaSize) + 1), result.position.y);
	}
	if (deta[FourDirection(FourDirectionName::Down)].GetTerrainName() == TerrainName::Wall) {
		result.position.y = std::min<float>(deta[FourDirection(FourDirectionName::Down)].Position().y - CHIP_SIZE * (((int)charaSize) + 1), result.position.y);
	}
	if (deta[FourDirection(FourDirectionName::Left)].GetTerrainName() == TerrainName::Wall) {
		result.position.x = std::max<float>(deta[FourDirection(FourDirectionName::Left)].Position().x + CHIP_SIZE * (((int)charaSize) + 1), result.position.x);
	}
	if (deta[FourDirection(FourDirectionName::Right)].GetTerrainName() == TerrainName::Wall) {
		result.position.x = std::min<float>(deta[FourDirection(FourDirectionName::Right)].Position().x - CHIP_SIZE * (((int)charaSize) + 1), result.position.x);
	}

	return result;
}

// �w�肳�ꂽ���W���^�C���̒��S���W�ɕ␳
GSvector2 Map::GetTilePos(const GSvector2& pos, const MapType type) {
	//1�}�X�̕�
	int chipSize = CHIP_SIZE* ((int)type + 1);
	//���ʕϐ�
	int x = pos.x / chipSize;
	int y = pos.y / chipSize;

	x = x * chipSize + chipSize / 2;
	y = y * chipSize + chipSize / 2;

	return GSvector2(x, y);
}

//�w�肳�ꂽ���W�̏��X�V
void Map::SetcsvParameter(const GSvector2 position, const TerrainName name, IWorld* world) {
	GSvector2 cellPos = CsvConvertTDV::Vector2CnvCsvPos(position, MapType::Double);

	m_Maps[MapType::Double][cellPos.y][cellPos.x] = name;

	m_Maps[MapType::Default][cellPos.y * 2 + 1][cellPos.x * 2 + 1] = name;
	m_Maps[MapType::Default][cellPos.y * 2 + 1][cellPos.x * 2] = name;
	m_Maps[MapType::Default][cellPos.y * 2][cellPos.x * 2 + 1] = name;
	m_Maps[MapType::Default][cellPos.y * 2][cellPos.x * 2] = name;

	world->sendMessage(EventMessage::MapDataUpdate);
}

void Map::Debug(const MapType type) {
	std::cout << "\n";
	// �s�̃��[�v
	for (int i = 0; i < m_Maps[type].size(); i++) {
		// ��̃��[�v
		for (int j = 0; j < m_Maps[type][i].size(); j++) {
			std::cout << (int)m_Maps[type][i][j];
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

// ���̎擾
int Map::GetWidth(const MapType& type) const {
	return m_Maps.at(type)[0].size();
}

// �����̎擾
int Map::GetHeight(const MapType& type) const {
	return m_Maps.at(type).size();
}

// csv���W��GSvector2�ɕϊ�(���S���W)
GSvector2 Map::CsvPosCnvVector2(const int x, const int y, const MapType type) {
	//���ʕϐ�
	GSvector2 result;
	//1�}�X�̒���
	int chipSize = CHIP_SIZE*((int)type + 1);

	result.x = chipSize * (x / ((int)type + 1)) + chipSize / 2;
	result.y = chipSize * (y / ((int)type + 1)) + chipSize / 2;

	return result;
}

//�����摜�쐬
void Map::CombineMapTexture() {
	//�A�����[�h
	p_GameManager->UnLoadTexture("Stage");
	//�摜����
	CombinationTexture::CreateMapImg(m_Maps[MapType::Default], "Resource/Texture/wall.png");
	//���[�h
	p_GameManager->LoadTexture("Stage", "Resource/Texture/Stage.png");
	//�`��o�^
	m_MapDrawID = p_GameManager->GetDrawManager()->RegisterDefaultParam("Stage", p_MapTextureParam, DrawOrder::Map);
	p_MapTextureParam->m_Center = { 0.0f,0.0f };
	p_MapTextureParam->m_Position = { 0.0f,0.0f };
}

void Map::RemoveTexture() {
	p_GameManager->GetDrawManager()->Remove(m_MapDrawID);
}
