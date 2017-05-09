#ifndef MAP_H_
#define MAP_H_

#include"../Utility/Rederer2D/Renderer2DPtr.h"
#include"../Tile/Tile.h"
#include"../Tile/TileData.h"

#include<iostream>
#include <vector>
#include<unordered_map>

//�O���b�h���W
class Point2;

class Map
{
public:
	
	//�}�b�v�̎擾
	std::vector<std::vector<int>>& getmap();
	//����̃^�C���f�[�^�̎擾
	std::unordered_map<Tile, TileData>GetAroundTile (const GSvector2& position);
	//�^�C���f�[�^�̎擾
	TileData GetTileData(int x, int y);

	//�_��
public:
	// �f�[�^�̎擾
	int operator [] (const Point2& position) const;
	// ���̎擾
	int Width() const;
	// �����̎擾
	int Height() const;
	
private:
	Renderer2DPtr p_Renderer2D;
	std::vector<std::vector<int>> m_Map;
};

#endif // !MAP_H_