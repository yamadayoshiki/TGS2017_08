#ifndef TEXTURE2DPARAMETER_H_
#define TEXTURE2DPARAMETER_H_
#include "Texture2DParameterPtr.h"
#include <GStype.h>
//�e�N�X�`���`��p�����[�^�[�\����
struct Texture2DParameter {
	//�R���X�g���N�^
	Texture2DParameter();
	~Texture2DParameter();
	struct {
		GSrect		m_Rect;			//�\��t����l�p�`
		GSvector2	m_Position;		//�X�N���[�����W
		GSvector2	m_Center;		//�e�N�X�`���̒��S���W
		GScolor		m_Color;		//�e�N�X�`���̐F
		GSvector2	m_Scale;		//�g��k��
		float		m_Rotate;		//��]
	};

	Texture2DParameterSPtr Clone() {
		Texture2DParameterSPtr result = std::make_shared<Texture2DParameter>();
		result->m_Rect = m_Rect;
		result->m_Position = m_Position;
		result->m_Center = m_Center;
		result->m_Color = m_Color;
		result->m_Scale = m_Scale;
		result->m_Rotate = m_Rotate;
		return result;
	}

	void Copy(const Texture2DParameterSPtr& source) {
		m_Rect = source->m_Rect;
		m_Position = source->m_Position;
		m_Center = source->m_Center;
		m_Color = source->m_Color;
		m_Scale = source->m_Scale;
		m_Rotate = source->m_Rotate;
	}
};

#endif