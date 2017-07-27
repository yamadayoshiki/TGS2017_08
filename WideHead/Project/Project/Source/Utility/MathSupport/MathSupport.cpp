#include "MathSupport.h"
#include <gslib.h>
#include "../../Define/Def_Nakayama.h"
#include "../../Define/Def_Float.h"
#include <cmath>

// ��̃x�N�g���̊p�x�����߂�(-180<value<=180)
float MathSupport::GetVec2ToVec2Angle(const GSvector2& dynamic, const GSvector2& base) {
	//����
	float result = 0;

	//���K��
	GSvector2 base_N = base.getNormalized();
	GSvector2 dynamic_N = dynamic.getNormalized();

	//�O�ς����߂�
	float cross = base_N.CCW(dynamic_N);

	//���ς����߂�
	float dot = base_N.dot(dynamic_N);

	//���ς���p�x�֕ϊ�
	result = acosf(dot);
	result = result * 180.0f / PI;

	//��������ւ�
	if (cross < 0)
		result = -result;

	//���ʂ�Ԃ�
	return result;
}

float MathSupport::DegreeToRadian(float degree) {
	return degree / 180.0f * PI;
}

// �x�N�g���̉�]
GSvector2 MathSupport::RotateVector(const GSvector2 vector, const float radian) {
	// ��]��̃x�N�g����Ԃ�
	float xcos = vector.x * gsCos(radian);
	float ysin = vector.y * gsSin(radian);
	float xsin = vector.x * gsSin(radian);
	float ycos = vector.y * gsCos(radian);
	float x = xcos - ysin;
	float y = xsin + ycos;
	return GSvector2(x, y);
}


// �x���@��GSvector2�ɕϊ�
GSvector2 MathSupport::GetAngleToVector2(const float& angle)
{
	//�ϊ�
	float x = cosf(angle * PI / 180);
	float y = sinf(angle * PI / 180);

	//���ʂ�Ԃ�
	return GSvector2(x, y);
}

//�p�x�̐��K��(-180<value<=180)
float MathSupport::GetAngleClamp(const float angle) {
	float result = angle;
	if (result >= 180.0f)
		result = 180.0f;

	else if (-180.0f >= result)
		result = -180.0f;

	if (-180.0f == result)
		result = 180.0f;

	return result;
}

//�p�x�̐��K��(-180<=value<=180)
float MathSupport::GetAngleNormalize(const float angle) {
	float result = angle;
	while (result < -180)
	{
		result += 360;
	}
	while (180 < result)
	{
		result -= 360;
	}
	return result;
}

//���R���̌��������߂�
unsigned MathSupport::GetDigit(unsigned num) {
	unsigned result = log10(num) + 1;
	if (result == 0)
		result = 1;
	return result;
}

//���R����؂���
unsigned int MathSupport::GetCutNum(const unsigned int value, const unsigned int head, const unsigned int length) {
	//���̐�
	int digit = GetDigit(value);

	if (digit < length)
		return 0;

	//�؂�̂Ă錅�̒���
	int high = head - 1;
	int low = digit - (high + length);

	//���ʕϐ�
	int result = 0;
	//��ʌ��؂�̂�
	result = value % (int)std::pow(10, low + length);
	//���ʌ��؂�̂�
	result = result / (int)std::pow(10, low);

	return result;
}

//�p�x�������s�p�x�ɕϊ�(-90,0,90,180)
float MathSupport::AngleCnvAAAngle(const float angle) {
	float result = GetAngleNormalize(angle);
	if (result <= -135 || 135 <= result)
		result = 180;
	else if (result <= -45)
		result = -90;
	else if (result <= 45)
		result = 0;
	else if (result <= 135)
		result = 90;

	return result;
}

