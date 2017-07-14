#ifndef RENDERER2D_H_
#define RENDERER2D_H_
#include <gslib.h>
#include <iostream>
#include <map>

#include "../../ActorContains/ActorName.h"
#include "../Texture2DParameter/Texture2DParameterPtr.h"

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

	//�e�N�X�`���j��
	void UnLoadTexture();

	//�e�N�X�`���j��
	void UnLoadTexture(const std::string& texName);

	//�e�N�X�`���`��
	void DrawTexture(
		const std::string& texName,				//�o�^��
		const GSvector2& pos);

	//�e�N�X�`���`��(�p�����[�^�ݒ�)
	void DrawTexture(
		const std::string& texName,				//�o�^��
		const Texture2DParameter& parameter);	//�p�����[�^�[


	//�e�N�X�`���`��(�p�����[�^�ݒ�)
	void DrawTexture(
		const std::string& texName,					//�o�^��
		const Texture2DParameterSPtr& parameter);	//�p�����[�^�[

	//�w��̃e�N�X�`��ID�̎擾
	unsigned int GetTextureID(
		const std::string& texName);	//�o�^��

	//�w��̃e�N�X�`���T�C�Y�̎擾(�o�^��)
	GSrect* GetTextureRect(const std::string& texName);

	//�G���[�o��
	void ErrorPush(bool flag, const std::string& name);

	//�R�s�[�֎~
	Renderer2D& operator = (const Renderer2D& other) = delete;
	Renderer2D(const Renderer2D& other) = delete;

private:
	//�e�N�X�`���T�C�Y�̎擾(�o�^��)
	GSvector2 GetTextureSize(const std::string& texName);

	//�e�N�X�`���T�C�Y�̎擾(ID)
	GSvector2 GetTextureSize(const unsigned int textureID);

	//�e�N�X�`���T�C�Y�̓o�^
	void RecordTextureSize(const std::string& texName);

private:
	//�o�^���EID
	std::map<std::string, unsigned int> m_TextureDic;
	unsigned int m_TextureID;

	//�o�^���E�T�C�Y
	std::map<std::string, GSrect> m_TextureSizeDic;
};

#endif