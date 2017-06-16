#include "../BodysPath.h"

//コンストラクタ
Body::Rectangle::Rectangle(const float width, const float height)
	: BodyBase(BodyName::Rectangle)
	, m_Width(width)
	, m_Heigh(height) {
}

//デストラクタ
Body::Rectangle::~Rectangle() {
}

//横幅の取得
float Body::Rectangle::GetWidth() {
	return m_Width;
}

//縦幅の取得
float Body::Rectangle::GetHeigh() {
	return m_Heigh;
}

//軸平行矩形との衝突判定
bool Body::Rectangle::IsCollide(AARectangle * other) {
	return IsCollide2D::AARectangleToRectangle(
		other->GetTransform()->m_Position, other->GetWidth(), other->GetHeigh(),
		p_Transform->m_Position, GetWidth(), GetHeigh(), p_Transform->m_Angle);
}

//矩形との衝突判定
bool Body::Rectangle::IsCollide(Rectangle * other) {
	return IsCollide2D::RectangleToRectangle(
		p_Transform->m_Position, GetWidth(), GetHeigh(), p_Transform->m_Angle,
		other->GetTransform()->m_Position, other->GetWidth(), other->GetHeigh(), other->GetTransform()->m_Angle);
}

//線分との衝突判定
bool Body::Rectangle::IsCollide(Line * other) {
	return IsCollide2D::RectangleToLine(
		p_Transform->m_Position, GetWidth(), GetHeigh(), p_Transform->m_Angle,
		other->GetTransform()->m_Position, other->GetVector());
}