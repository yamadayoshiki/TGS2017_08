#include "../BodysPath.h"
#include "../../../Utility/MathSupport/MathSupport.h"

//�R���X�g���N�^
Body::AARectangle::AARectangle(
	const float width, 
	const float height)
	: BodyBase(BodyName::AARectangle)
	, m_Width(width)
	, m_Heigh(height) {
}

//�f�X�g���N�^
Body::AARectangle::~AARectangle() {
}

//�����̎擾
float Body::AARectangle::GetWidth() {
	float aAAngle = MathSupport::AngleCnvAAAngle(p_Transform->m_Angle);
	if (aAAngle == 0 || aAAngle == 180)
		return m_Width;

	if (aAAngle == 90 || aAAngle == -90)
		return m_Heigh;

	return m_Width;
}

//�c���̎擾
float Body::AARectangle::GetHeigh() {
	float aAAngle = MathSupport::AngleCnvAAAngle(p_Transform->m_Angle);
	if (aAAngle == 0 || aAAngle == 180)
		return m_Heigh;

	if (aAAngle == 90 || aAAngle == -90)
		return m_Width;

	return m_Heigh;
}

//�����s��`�Ƃ̏Փ˔���
bool Body::AARectangle::IsCollide(AARectangle * other) {
	return IsCollide2D::AARectangleToAARectangle(
		p_Transform->m_Position, GetWidth(), GetHeigh(), 
		other->GetTransform()->m_Position, other->GetWidth(), other->GetHeigh());
}

//��`�Ƃ̏Փ˔���
bool Body::AARectangle::IsCollide(Body::Rectangle * other) {
	return IsCollide2D::AARectangleToRectangle(
		p_Transform->m_Position, GetWidth(), GetHeigh(), 
		other->GetTransform()->m_Position, other->GetWidth(), other->GetHeigh(), other->GetTransform()->m_Angle);
}

//�����Ƃ̏Փ˔���
bool Body::AARectangle::IsCollide(Body::Line * other) {
	return IsCollide2D::AARectangleToLine(
		p_Transform->m_Position, GetWidth(), GetHeigh(), 
		other->GetTransform()->m_Position, other->GetVector());
}