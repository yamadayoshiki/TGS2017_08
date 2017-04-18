#ifndef MAP_H_
#define MAP_H_

#include"../Utility/Rederer2D/Renderer2D.h"

#include<iostream>
#include <vector>

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
	void Update();
	//�`��
	void Draw() const;
	//�Փ˔���
	void Collide();
	//�}�b�v�̎擾
	std::vector<std::vector<int>> getmap();
	
private:
	Renderer2D m_Renderer2D;
	std::vector<std::vector<int>> m_Map;
};

#endif // !MAP_H_