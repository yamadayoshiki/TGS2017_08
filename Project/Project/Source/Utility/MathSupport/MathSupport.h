#ifndef MATHSUPPORT_H_
#define MATHSUPPORT_H_

#include <gslib.h>

namespace MathSupport
{
	// �~����
	static const float PI = 3.141592f;

	// ��̃x�N�g���̊p�x�����߂�(-180<value<=180)
	float GetVec2ToVec2Angle(const GSvector2& dynamic, const GSvector2& base = GSvector2(1.0f, 0.0f));

	// �x�N�g���̉�]
	GSvector2 RotateVector(const GSvector2 vector, const float angle);

	// �x���@��GSvector2�ɕϊ�
	GSvector2 GetAngleToVector2(const float& angle);

	//�p�x�̐��K��(-180<value<=180)
	float GetAngleClamp(const float angle);

	//�p�x�̐��K��(-180<=value<=180)
	float GetAngleNormalize(const float angle);

	//���R���̌��������߂�
	unsigned int GetDigit(const unsigned num);

	//���R����؂���
	unsigned int GetCutNum(const unsigned int value, const unsigned int head, const unsigned int length);

	//�p�x�������s�p�x�ɕϊ�(-90,0,90,180)
	float AngleCnvAAAngle(const float angle);
}

#endif