#include "../BodysPath.h"
#include "../../../Utility/MathSupport/MathSupport.h"

//�R���X�g���N�^
Body::Line::Line(const GSvector2 vector)
	: BodyBase(BodyName::Line) {
}

//�f�X�g���N�^
Body::Line::~Line() {
}

//�x�N�g���̎擾
GSvector2 Body::Line::GetVector() {
	return MathSupport::RotateVector(m_Vector, p_Transform->m_Angle);
}

//�����s��`�Ƃ̏Փ˔���
bool Body::Line::IsCollide(AARectangle * other) {
	return IsCollide2D::AARectangleToLine(
		other->GetTransform()->m_Position, other->GetWidth(), other->GetHeigh(),
		p_Transform->m_Position, GetVector());
}

//��`�Ƃ̏Փ˔���
bool Body::Line::IsCollide(Rectangle * other) {
	return IsCollide2D::RectangleToLine(
		other->GetTransform()->m_Position, other->GetWidth(), other->GetHeigh(), other->GetTransform()->m_Angle,
		p_Transform->m_Position, GetVector());
}

//�����Ƃ̏Փ˔���
bool Body::Line::IsCollide(Line * other) {
	return IsCollide2D::LineToLine(
		p_Transform->m_Position, GetVector(),
		other->GetTransform()->m_Position, other->GetVector());
}

