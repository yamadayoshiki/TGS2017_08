#include "Renderer2D.h"
#include <cassert>
#include <gslib.h>
#include "../Texture2DParameter/Texture2DParameter.h"

//�R���X�g���N�^
Renderer2D::Renderer2D()
	:m_TextureID(0)
{
	m_TextureDic.clear();
	m_TextureSizeDic.clear();
}

//������
void Renderer2D::Initialize()
{
	m_TextureID = 0;
	m_TextureDic.clear();
	m_TextureSizeDic.clear();
}

//�e�N�X�`���ǂݍ���
void Renderer2D::LoadTexture(const std::string& fileName)
{
	LoadTexture(fileName, fileName);
}

//�e�N�X�`���ǂݍ���(fileName�ʓo�^)
void Renderer2D::LoadTexture(
	const std::string& texName,			//�o�^��
	const std::string& fileName			//�t�@�C���p�X
	)
{
	//�e�N�X�`���[�ǂݍ���
	m_TextureDic[texName] = m_TextureID;
	bool flag = (gsLoadTexture(m_TextureDic[texName], fileName.c_str()) == GS_TRUE);
	RecordTextureSize(texName);
	m_TextureID++;

	ErrorPush(flag, texName);
}
//�e�N�X�`���j��
void Renderer2D::UnLoadTexture(){
	for (auto texture = m_TextureDic.begin(); texture != m_TextureDic.end(); texture++)
		gsDeleteTexture((*texture).second);
}

//�e�N�X�`���`��
void Renderer2D::DrawTexture(
	const std::string& texName,										//�o�^��
	const GSvector2& position)										//�`����W
{
	gsDrawSprite2D
		(
			m_TextureDic[texName],
			&position,
			&m_TextureSizeDic[texName],
			NULL,
			NULL,
			NULL,
			0.0f);
}

//�e�N�X�`���`��(�p�����[�^�ݒ�)
void Renderer2D::DrawTexture
(
	const std::string& texName,				//�o�^��
	const Texture2DParameter& parameter		//�p�����[�^�[
	)
{
	DrawTexture(m_TextureDic[texName], parameter);
}

//�e�N�X�`���`��(�p�����[�^�ݒ�)
void Renderer2D::DrawTexture(
	const unsigned int texID,						//�o�^�ԍ�
	const Texture2DParameter& parameter)	//�p�����[�^�[
{
	gsDrawSprite2D(
		texID,
		&parameter.GetPosition(),
		&parameter.GetRect(),
		&parameter.GetCenter(),
		&parameter.GetColor(),
		&parameter.GetScale(),
		parameter.GetRotate());
}

//�w��̃e�N�X�`��ID�̎擾
unsigned int Renderer2D::GetTextureID(
	const std::string& texName	//�o�^��
	)
{
	return m_TextureDic[texName];
}

//�w��̃e�N�X�`���T�C�Y�̎擾(�o�^��)
GSrect* Renderer2D::GetTextureRect(const std::string& texName)
{
	return &m_TextureSizeDic[texName];
}

//�G���[�o��
void Renderer2D::ErrorPush(bool flag, const std::string& name)
{
	//�t�@�C�������݂��Ȃ��ꍇ�ɃG���[���o��
	//GSLoad�����Bool�̖߂�l�𗘗p����
	if (flag == false)
	{
		//���݂��Ȃ������t�@�C����
		printf(name.c_str());
		printf("\n");
		//Assert���Ńv���O������~
		assert(!"No File Found");
	}
}

//�e�N�X�`���T�C�Y�̎擾(�o�^��)
GSvector2 Renderer2D::GetTextureSize(const std::string& texName)
{
	return GetTextureSize(m_TextureDic[texName]);
}

//�e�N�X�`���T�C�Y�̎擾(ID)
GSvector2 Renderer2D::GetTextureSize(const unsigned int textureID)
{
	GSvector2 result = GSvector2();
	result.x = gsTextureGetWidth(gsGetTexture(textureID));
	result.y = gsTextureGetHeight(gsGetTexture(textureID));

	return result;
}

//�e�N�X�`���T�C�Y�̓o�^
void Renderer2D::RecordTextureSize(const std::string& texName)
{
	GSvector2 size = GetTextureSize(texName);
	GSrect rectSize;
	rectSize.right = size.x;
	rectSize.bottom = size.y;
	m_TextureSizeDic[texName] = rectSize;
}