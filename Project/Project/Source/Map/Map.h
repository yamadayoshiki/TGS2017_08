#ifndef MAP_H_
#define MAP_H_

#include"../Utility/Rederer2D/Renderer2DPtr.h"
#include"../Utility/FourDirection/FourDirection.h"
#include"../Tile/TileData.h"
#include "../ActorContains/ActorPtr.h"
#include "../Base/GameManagerContains/IGameManagerPtr.h"

#include<iostream>
#include <vector>
#include<unordered_map>

//�O���b�h���W
class Point2;

class Map
{
public:

	//�R���X�g���N�^
	Map(const IGameManagerPtr& gameManager);
	//�`��
	void draw();
	//�}�b�v�̎擾
	std::vector<std::vector<int>>& getmap();
	//����̃^�C���f�[�^�̎擾
	std::unordered_map<FourDirection, TileData>GetAroundTile(const GSvector2& position);
	//�w�肳�ꂽ���W�̏c���̃u���b�N�̎擾
	std::vector<int>GetRow(const GSvector2& position);
	//�w�肳�ꂽ���W�̉����̃u���b�N�̎擾
	std::vector<int>GetColumn(const GSvector2& position);
	//�^�C���f�[�^�̎擾
	TileData GetTileData(int x, int y);
	// ���ʂɕǂ����邩������
	bool IsInFrontOfTheWall(const GSvector2& pos, FourDirection direction);
	//�_��
public:
	// �f�[�^�̎擾
	int operator [] (const Point2& position) const;
	// ���̎擾
	int GetWidth() const;
	// �����̎擾
	int GetHeight() const;

private:
	Renderer2DPtr p_Renderer2D;
	std::vector<std::vector<int>> m_Map;
	//�Q�[���}�l�[�W���[�|�C���^
	IGameManagerPtr p_GameManager;
};

#endif // !MAP_H_