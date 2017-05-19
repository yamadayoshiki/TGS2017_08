#ifndef MATHSUPPORT_H_
#define MATHSUPPORT_H_

#include <gslib.h>

class Point2;

namespace MathSupport
{
	// �~����
	static const float PI = 3.141592f;

	// ��̃x�N�g���̊p�x�����߂�(-180<value<=180)
	float GetVec2ToVec2Angle(const GSvector2& dynamic, const GSvector2& base = GSvector2(0.0f, -1.0f));

	// �x�N�g���̉�]
	GSvector2 RotateVector(const GSvector2 & pos, const float & angle);

	// �x���@��GSvector2�ɕϊ�
	GSvector2 GetAngleToVector2(const float& angle);

	// ���W���}�X�ɕϊ�
	Point2 GetVector2ToPoint2(const GSvector2 vector);

	//�p�x�̐��K��(-180<value<=180)
	float GetAngleNomalize(const float angle);
}

#endif