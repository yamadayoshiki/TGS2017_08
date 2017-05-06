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
	//�R���X�g���N�^
	Map();
	//���[�h
	void Load();
	//�A�����[�h
	void Unload();
	//�X�V
	void Update(float deltaTime);
	//�`��
	void Draw() const;
	//�Փ˔���
	void Collide();
	//�}�b�v�̎擾
	std::vector<std::vector<int>>& getmap();
	//
	std::unordered_map<Tile, TileData>GetAroundTile (const GSvector2& position);
	//
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