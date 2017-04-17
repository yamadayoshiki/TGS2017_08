#include "Renderer2D.h"
#include <cassert>
#include <gslib.h>
#include "../Texture2DParameter/Texture2DParameter.h"

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
	const std::string& texName,										//�o�^��
	const GSvector2& position,										//�`����W
	const GSrect& rect = GSrect(0.0f, 0.0f, 1.0f, 1.0f)				//�`��͈�
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

//�e�N�X�`���`��(�p�����[�^�ݒ�)
void Renderer2D::DrawTexture
(
	const std::string& texName,				//�o�^��
	const Texture2DParameter& parameter		//�p�����[�^�[
	)
{
	gsDrawSprite2D(
		m_TextureDic[texName],
		&parameter.GetPosition(),
		&parameter.GetRect(),
		&parameter.GetCenter(),
		&parameter.GetColor(),
		&parameter.GetScale(),
		parameter.GetRotate()
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

//�w�肵�������ڂ�rect���v�Z(�A�j���[�V�����̕⏕)
GSrect Renderer2D::CalculateAnimationRect(
	const GSrect& rect,		//�؂���e�N�X�`����rect
	int texWidth,			//�e�N�X�`���̉���
	int texNum				//�w�肷�閇����
	)
{
	//���������W�̌v�Z�ɒu���������
	texNum -= 1;

	//�e�N�X�`���̕��ƍ���
	const int texCutWidth = rect.right - rect.left;
	const int texCutHeight = rect.bottom - rect.top;

	//�e�N�X�`���̑傫�����牡�ɉ��������邩���߂�
	const int cutX = texWidth / rect.right;

	//�e�N�X�`���̍�����W
	const GSvector2 texCoord
		(
			(texNum % cutX) * texCutWidth,
			(texNum / cutX) * texCutHeight
			);

	//�e�N�X�`������؂���l�p�`
	const GSrect result = GSrect
		(
			texCoord.x,
			texCoord.y,
			texCoord.x + texCutWidth,
			texCoord.y + texCutHeight
			);

	return result;
}