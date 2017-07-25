#ifndef TRANSFORM_H_
#define TRANSFORM_H_

#include <GSvector2.h>

//�g�����X�t�H�[���N���X
class Transform {
public:
	//�R���X�g���N�^
	Transform(GSvector2 pos, float angle);
	//�f�t�H���g�R���X�g���N�^
	Transform();
	//�f�X�g���N�^
	~Transform();
	//���ʃx�N�g�����擾
	GSvector2 GetForward() const;

public:
	// ���W
	GSvector2 m_Position;
	// ��]�p�x
	float m_Angle;
};

#endif // !TRANSFORM_H_