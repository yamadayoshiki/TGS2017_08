#include "../BodysPath.h"

//�R���X�g���N�^
Body::Rectangle::Rectangle(const float width, const float height)
	: BodyBase(BodyName::Rectangle)
	, m_Width(width)
	, m_Heigh(height) {
}

//�f�X�g���N�^
Body::Rectangle::~Rectangle() {
}

//�����̎擾
float Body::Rectangle::GetWidth() {
	return m_Width;
}

//�c���̎擾
float Body::Rectangle::GetHeigh() {
	return m_Heigh;
}

//�����s��`�Ƃ̏Փ˔���
bool Body::Rectangle::IsCollide(AARectangle * other) {
	return IsCollide2D::AARectangleToRectangle(
		other->GetTransform()->m_Position, other->GetWidth(), other->GetHeigh(),
		p_Transform->m_Position, GetWidth(), GetHeigh(), p_Transform->m_Angle);
}

//��`�Ƃ̏Փ˔���
bool Body::Rectangle::IsCollide(Rectangle * other) {
	return IsCollide2D::RectangleToRectangle(
		p_Transform->m_Position, GetWidth(), GetHeigh(), p_Transform->m_Angle,
		other->GetTransform()->m_Position, other->GetWidth(), other->GetHeigh(), other->GetTransform()->m_Angle);
}

//�����Ƃ̏Փ˔���
bool Body::Rectangle::IsCollide(Line * other) {
	return IsCollide2D::RectangleToLine(
		p_Transform->m_Position, GetWidth(), GetHeigh(), p_Transform->m_Angle,
		other->GetTransform()->m_Position, other->GetVector());
}