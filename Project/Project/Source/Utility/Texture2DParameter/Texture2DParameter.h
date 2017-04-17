#ifndef TEXTURE2DPARAMETER_H_
#define TEXTURE2DPARAMETER_H_

#include <gslib.h>

//�e�N�X�`���`��p�����[�^�[�\����
class Texture2DParameter
{
public:
	//�R���X�g���N�^
	Texture2DParameter();

	//�\��t����l�p�`�̐ݒ�
	void SetRect(const GSrect& rect);

	//�\��t����l�p�`�̎擾
	GSrect GetRect() const;

	//�X�N���[�����W�̐ݒ�
	void SetPosition(const GSvector2 position);

	//�X�N���[�����W�̎擾
	GSvector2 GetPosition() const;

	//�e�N�X�`���̒��S���W�̐ݒ�
	void SetCenter(const GSvector2 center);

	//�e�N�X�`���̒��S���W�̎擾
	GSvector2 GetCenter() const;

	//�e�N�X�`���̐F�̐ݒ�
	void SetColor(const GScolor& color);

	//�e�N�X�`���̐F�̎擾
	GScolor GetColor() const;

	//�g��k���̐ݒ�
	void SetScale(const GSvector2 scale);

	//�g��k���̎擾
	GSvector2 GetScale() const;

	//��]�̐ݒ�
	void SetRotate(const float rotate);

	//��]�̎擾
	float GetRotate() const;

private:
	GSrect m_Rect;			//�\��t����l�p�`
	GSvector2 m_Position;	//�X�N���[�����W
	GSvector2 m_Center;		//�e�N�X�`���̒��S���W
	GScolor m_Color;		//�e�N�X�`���̐F
	GSvector2 m_Scale;		//�g��k��
	float m_Rotate;			//��]
};

#endif // !TEXTURE2DPARAMETER_H_
