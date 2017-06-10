#include "MathSupport.h"
#include <gslib.h>
#include "../../Define/Def_Nakayama.h"
#include "../PathFinder/Point2.h"
#include "../../Define/Def_Float.h"

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

// �x�N�g���̉�]
GSvector2 MathSupport::RotateVector(const GSvector2 & pos, const float & angle) {
	float f_angle = GetAngleNomalize(angle);

	// ��]��̃x�N�g����Ԃ�
	return GSvector2(pos.x * gsCos(f_angle) - pos.y * gsSin(f_angle), pos.x * gsSin(f_angle) + pos.y * gsCos(f_angle));
}


// �x���@��GSvector2�ɕϊ�
GSvector2 MathSupport::GetAngleToVector2(const float& angle)
{
	//�ϊ�
	float x = gsCos(angle * PI / 180);
	float y = gsSin(angle * PI / 180);

	//���ʂ�Ԃ�
	return GSvector2(x, y);
}


// ���W���}�X�ɕϊ�
Point2 MathSupport::GetVector2ToPoint2(const GSvector2 vector)
{
	//���ʕϐ�
	Point2 result;

	//�}�X�ɍ��킹��
	int x = vector.x / CHIP_SIZE + 1;
	int y = vector.y / CHIP_SIZE + 1;

	result.x = x;
	result.y = y;

	return result;
}

//�p�x�̐��K��(-180<value<=180)
float MathSupport::GetAngleNomalize(const float angle) {
	float result = angle;
	if (result >= 180.0f)
		result = 180.0f;

	else if (-180.0f >= result)
		result = -180.0f;

	if (-180.0f == result)
		result = 180.0f;

	return result;
}

//���R���̌��������߂�
unsigned MathSupport::GetDigit(unsigned num) {
	return log10(num) + 1;
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

