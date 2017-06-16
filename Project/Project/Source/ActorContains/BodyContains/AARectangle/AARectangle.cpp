#include "../BodysPath.h"
#include "../../../Utility/MathSupport/MathSupport.h"

//コンストラクタ
Body::AARectangle::AARectangle(
	const float width, 
	const float height)
	: BodyBase(BodyName::AARectangle)
	, m_Width(width)
	, m_Heigh(height) {
}

//デストラクタ
Body::AARectangle::~AARectangle() {
}

//横幅の取得
float Body::AARectangle::GetWidth() {
	float aAAngle = MathSupport::AngleCnvAAAngle(p_Transform->m_Angle);
	if (aAAngle == 0 || aAAngle == 180)
		return m_Width;

	if (aAAngle == 90 || aAAngle == -90)
		return m_Heigh;

	return m_Width;
}

//縦幅の取得
float Body::AARectangle::GetHeigh() {
	float aAAngle = MathSupport::AngleCnvAAAngle(p_Transform->m_Angle);
	if (aAAngle == 0 || aAAngle == 180)
		return m_Heigh;

	if (aAAngle == 90 || aAAngle == -90)
		return m_Width;

	return m_Heigh;
}

//軸平行矩形との衝突判定
bool Body::AARectangle::IsCollide(AARectangle * other) {
	return IsCollide2D::AARectangleToAARectangle(
		p_Transform->m_Position, GetWidth(), GetHeigh(), 
		other->GetTransform()->m_Position, other->GetWidth(), other->GetHeigh());
}

//矩形との衝突判定
bool Body::AARectangle::IsCollide(Body::Rectangle * other) {
	return IsCollide2D::AARectangleToRectangle(
		p_Transform->m_Position, GetWidth(), GetHeigh(), 
		other->GetTransform()->m_Position, other->GetWidth(), other->GetHeigh(), other->GetTransform()->m_Angle);
}

//線分との衝突判定
bool Body::AARectangle::IsCollide(Body::Line * other) {
	return IsCollide2D::AARectangleToLine(
		p_Transform->m_Position, GetWidth(), GetHeigh(), 
		other->GetTransform()->m_Position, other->GetVector());
}