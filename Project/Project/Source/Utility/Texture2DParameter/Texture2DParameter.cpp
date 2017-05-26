#include "Texture2DParameter.h"

Texture2DParameter::Texture2DParameter()
	: m_Rect(0, 0, 0, 0)				//�\��t����l�p�`
	, m_Position(0.0f, 0.f)				//�X�N���[�����W
	, m_Center(0.0f, 0.0f)				//�e�N�X�`���̒��S���W
	, m_Color(1.0f, 1.0f, 1.0f, 1.0f)	//�e�N�X�`���̐F
	, m_Scale(1.0f, 1.0f)				//�g��k��
	, m_Rotate(0.0f)					//��]
{
}


//�\��t����l�p�`�̐ݒ�
void Texture2DParameter::SetRect(const GSrect& rect)
{
	m_Rect = rect;
}

//�\��t����l�p�`�̎擾
GSrect Texture2DParameter::GetRect() const
{
	return m_Rect;
}

//�X�N���[�����W�̐ݒ�
void Texture2DParameter::SetPosition(const GSvector2 position)
{
	m_Position = position;
}

//�X�N���[�����W�̎擾
GSvector2 Texture2DParameter::GetPosition() const
{
	return m_Position;
}

//�e�N�X�`���̒��S���W�̐ݒ�
void Texture2DParameter::SetCenter(const GSvector2 center)
{
	m_Center = center;
}

//�e�N�X�`���̒��S���W�̎擾
GSvector2 Texture2DParameter::GetCenter() const
{
	return m_Center;
}


//�e�N�X�`���̐F�̐ݒ�
void Texture2DParameter::SetColor(const GScolor& color)
{
	m_Color = color;
}

//�e�N�X�`���̐F�̎擾
GScolor Texture2DParameter::GetColor() const
{
	return m_Color;
}

//�g��k���̐ݒ�
void Texture2DParameter::SetScale(const GSvector2 scale)
{
	m_Scale = scale;
}

//�g��k���̎擾
GSvector2 Texture2DParameter::GetScale() const
{
	return m_Scale;
}

//��]�̐ݒ�
void Texture2DParameter::SetRotate(const float rotate)
{
	m_Rotate = rotate;
}

//��]�̎擾
float Texture2DParameter::GetRotate() const
{
	return m_Rotate;
}