#ifndef MAP_H_
#define MAP_H_

#include "../Utility/Rederer2D/Renderer2DPtr.h"
#include "../Utility/FourDirection/FourDirection.h"
#include "../Tile/TileData.h"
#include "../ActorContains/ActorPtr.h"
#include "../Base/GameManagerContains/IGameManagerPtr.h"
#include"../WorldContains/IWorld.h"

#include "CsvTwoDVectorTerrainData.h"
#include "MapData.h"
#include "MapType.h"

#include <iostream>
#include <unordered_map>

//�O���b�h���W
class Point2;

//�����o�����ʍ\����
struct ResultPushDirection
{
	bool flag;						//�����o���ꂽ��
	GSvector2 position;				//���ʍ��W
	FourDirection pushDirection;	//�����o���ꂽ����
};

class Map {
public:
	//�R���X�g���N�^
	Map(const IGameManagerPtr& gameManager);
	//�`��
	void draw(const MapType& type = MapType::Default);
	//�}�b�v�̎擾
	CsvTwoDVectorTerrainData& getmap(const MapType& type = MapType::Default);
	// �}�b�v�̓o�^
	void regist(const MapData& data, const MapType& type = MapType::Default);
	//����̃^�C���f�[�^�̎擾
	std::unordered_map<FourDirection, TileData>GetAroundTile(const GSvector2& position, const MapType& type = MapType::Default);
	//�w�肳�ꂽ���W�̏c���̃u���b�N�̎擾
	std::vector<TerrainName>GetRow(const GSvector2& position, const MapType& type = MapType::Default);
	//�w�肳�ꂽ���W�̉����̃u���b�N�̎擾
	std::vector<TerrainName>GetColumn(const GSvector2& position, const MapType& type = MapType::Default);
	//�^�C���f�[�^�̎擾
	TileData GetTileData(int column, int row, const MapType& type = MapType::Default);
	// ���ʂɕǂ����邩������
	bool IsInFrontOfTheWall(const GSvector2& pos, FourDirection direction, const MapType& type = MapType::Default);

	// �����o������
	ResultPushDirection PushForPlayer(const GSvector2& current_pos, const GSvector2& target_pos, const MapType & charaSize, const TerrainName tileNumber);
	// �����o������(�}�X����)
	ResultPushDirection PushForChara(const GSvector2& current_pos, const GSvector2& target_pos, const MapType& charaSize);
	// �w�肳�ꂽ���W���^�C���̒��S���W�ɕ␳
	GSvector2 GetTilePos(const GSvector2& pos, const MapType type = MapType::Default);
	//�w�肳�ꂽ���W�̏��X�V
	void SetcsvParameter(const GSvector2 position, const TerrainName name, IWorld* world);

	// �f�o�b�O�\��
	void Debug(const MapType type = MapType::Default);

private:
	//�w�肳�ꂽ���W�̏��X�V(MapType��������)
	void SetcsvParameter(const GSvector2 position, const TerrainName name, const MapType type);

public:
	// ���̎擾
	int GetWidth(const MapType& type = MapType::Default) const;
	// �����̎擾
	int GetHeight(const MapType& type = MapType::Default) const;
	// csv���W��GSvector2�ɕϊ�(���S���W)
	GSvector2 CsvPosCnvVector2(const int x, const int y, const MapType type);
	//�����摜�쐬
	void CombineMapTexture();

private:
	// �}�b�v�̊i�[
	std::unordered_map<MapType, CsvTwoDVectorTerrainData> m_Maps;
	//�Q�[���}�l�[�W���[�|�C���^
	IGameManagerPtr p_GameManager;
};

#endif // !MAP_H_