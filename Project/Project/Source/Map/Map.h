#ifndef MAP_H_
#define MAP_H_

#include"../Utility/Rederer2D/Renderer2DPtr.h"

#include<iostream>
#include <vector>

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
	std::vector<std::vector<int>> getmap();

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