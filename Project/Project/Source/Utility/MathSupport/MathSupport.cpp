#include "MathSupport.h"
#include <gslib.h>


float MathSupport::GetAngle(const GSvector2& dynamic, const GSvector2& base) {
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
	result = result * 180.0f / 3.14f;

	//��������ւ�
	if (cross < 0)
		result = -result;

	//���ʂ�Ԃ�
	return result;
}

// �x�N�g���̉�]
GSvector2 MathSupport::RotateVector(const GSvector2 & pos, const float & angle){
	// ��]��̃x�N�g����Ԃ�
	return GSvector2(pos.x * gsCos(angle) - pos.y * gsSin(angle), pos.x * gsSin(angle) + pos.y * gsCos(angle));
}
