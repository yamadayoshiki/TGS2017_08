#include "Renderer2D.h"
#include <cassert>
#include <gslib.h>
#include "../Texture2DParameter/Texture2DParameter.h"

//�R���X�g���N�^
Renderer2D::Renderer2D()
	:m_TextureID(0) {
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
void Renderer2D::LoadTexture(const std::string& fileName) {
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
void Renderer2D::UnLoadTexture() {
	for (auto texture = m_TextureDic.begin(); texture != m_TextureDic.end(); texture++)
		gsDeleteTexture((*texture).second);

	m_TextureDic.clear();
}

//�e�N�X�`���j��
void Renderer2D::UnLoadTexture(const std::string & texName) {
	//�o�^����Ă��邩
	auto itr = m_TextureDic.find(texName);
	if (itr == m_TextureDic.end())
		return;

	//�j��
	gsDeleteTexture((*itr).second);
	m_TextureDic.erase(itr);
}

void Renderer2D::DrawTexture(const std::string & texName, const GSvector2 & pos) {
	gsDrawSprite2D(
		m_TextureDic[texName],
		&pos,
		&GSrect(0, 0, GetTextureSize(texName).x, GetTextureSize(texName).y),
		&GSvector2(0.0f, 0.0f),
		&GScolor(1.0f, 1.0f, 1.0f, 1.0f),
		&GSvector2(1.0f, 1.0f),
		0);
}

//�e�N�X�`���`��(�p�����[�^�ݒ�)
void Renderer2D::DrawTexture(
	const std::string& texName,				//�o�^��
	const Texture2DParameter& parameter) {	//�p�����[�^�[
	gsDrawSprite2D(
		m_TextureDic[texName],
		&parameter.m_Position,
		&parameter.m_Rect,
		&parameter.m_Center,
		&parameter.m_Color,
		&parameter.m_Scale,
		parameter.m_Rotate);
}

//�e�N�X�`���`��(�p�����[�^�ݒ�)
void Renderer2D::DrawTexture(
	const std::string & texName,
	const Texture2DParameterSPtr & parameter) {
	DrawTexture(texName, *parameter.get());
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
