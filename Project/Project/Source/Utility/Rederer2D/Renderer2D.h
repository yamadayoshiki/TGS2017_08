#ifndef RENDERER2D_H_
#define RENDERER2D_H_
#include <gslib.h>
#include <iostream>
#include <map>

#include"../../ActorContains/ActorName.h"

class Renderer2D
{
public:
	//�R���X�g���N�^
	Renderer2D();

	//������
	void Initialize();

	//�e�N�X�`���ǂݍ���
	void LoadTexture(const std::string& fileName);

	//�e�N�X�`���ǂݍ���(fileName�ʓo�^)
	void LoadTexture
		(
			const std::string& texName,			//�o�^��
			const std::string& fileName			//�t�@�C���p�X
			);

	//�e�N�X�`���`��
	void DrawTexture
		(
			const std::string& texName,		//�o�^��
			const GSrect& rect,				//�`��͈�
			const GSvector2& position		//�`����W
			);

	//�e�N�X�`���`��(�p�����[�^�ݒ�)...������
	//void DrawTexture
	//	(
	//		const std::string& texName,
	//		const TextureParameter2D& param
	//		);

	//�G���[�o��
	void ErrorPush(bool flag, const std::string& name);

	//�R�s�[�֎~
	Renderer2D& operator = (const Renderer2D& other) = delete;
	Renderer2D(const Renderer2D& other) = delete;

private:
	//�w�肵�������ڂ�rect���v�Z(�A�j���[�V�����̕⏕)
	//GSrect CalculateAnimationRect
	//	(
	//		const GSrect& rect,		//�؂���e�N�X�`����rect
	//		int texWidth,			//�e�N�X�`���̉���
	//		int texNum				//�w�肷�閇����
	//		);

private:
	std::map<std::string, unsigned int> m_TextureDic;
	unsigned int m_TextureID;
};

#endif