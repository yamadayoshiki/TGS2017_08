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