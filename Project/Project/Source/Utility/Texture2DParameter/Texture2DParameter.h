#ifndef TEXTURE2DPARAMETER_H_
#define TEXTURE2DPARAMETER_H_
#include <GStype.h>
//�e�N�X�`���`��p�����[�^�[�\����
struct Texture2DParameter {
	//�R���X�g���N�^
	Texture2DParameter();
	~Texture2DParameter() {}
	struct {
		GSrect m_Rect;			//�\��t����l�p�`
		GSvector2 m_Position;	//�X�N���[�����W
		GSvector2 m_Center;		//�e�N�X�`���̒��S���W
		GScolor m_Color;		//�e�N�X�`���̐F
		GSvector2 m_Scale;		//�g��k��
		float m_Rotate;			//��]
	};
};

#endif