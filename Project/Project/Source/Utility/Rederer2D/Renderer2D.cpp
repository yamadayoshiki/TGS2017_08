#include "Renderer2D.h"
#include <cassert>
#include <gslib.h>

//�R���X�g���N�^
Renderer2D::Renderer2D()
	:m_TextureID(0)
{
	m_TextureDic.clear();
}

//������
void Renderer2D::Initialize()
{
	m_TextureID = 0;
	m_TextureDic.clear();
}

//�e�N�X�`���ǂݍ���
void Renderer2D::LoadTexture(const std::string& fileName)
{
	LoadTexture(fileName, fileName);
}

//�e�N�X�`���ǂݍ���(fileName�ʓo�^)
void Renderer2D::LoadTexture
(
	const std::string& texName,			//�o�^��
	const std::string& fileName			//�t�@�C���p�X
	)
{
	//�e�N�X�`���[�ǂݍ���
	m_TextureDic[texName] = m_TextureID;
	bool flag = (gsLoadTexture(m_TextureDic[texName], fileName.c_str()) == GS_TRUE);
	m_TextureID++;

	ErrorPush(flag, texName);
}

//�e�N�X�`���`��
void Renderer2D::DrawTexture
(
	const std::string& texName,		//�o�^��
	const GSrect& rect,				//�`��͈�
	const GSvector2& position		//�`����W
	)
{
	gsDrawSprite2D
		(
			m_TextureDic[texName],
			&position,
			&rect,
			NULL,
			NULL,
			NULL,
			0.0f
			);
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