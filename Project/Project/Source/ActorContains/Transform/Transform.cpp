#include "Transform.h"
#include "../../Utility/MathSupport/MathSupport.h"

//�R���X�g���N�^
Transform::Transform(GSvector2 pos, float angle)
	: m_Position(pos)
	, m_Angle(angle) {
}

//�f�t�H���g�R���X�g���N�^
Transform::Transform()
	: Transform(GSvector2(0.0f, 0.0f), 0.0f) {
}

//���ʃx�N�g�����擾
GSvector2 Transform::GetForward() const {
	return MathSupport::GetAngleToVector2(m_Angle);
}