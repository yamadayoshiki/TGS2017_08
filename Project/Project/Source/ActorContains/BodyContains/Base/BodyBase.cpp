#include "BodyBase.h"
#include "../BodyName.h"
#include <cassert>

//コンストラクタ
Body::BodyBase::BodyBase(const BodyName name)
	: m_Name(name)
	, m_IsExist(true) {
}

//デストラクタ
Body::BodyBase::~BodyBase() {
}

//衝突しているか
bool Body::BodyBase::IsCollide(IBody* other) {
	if (m_IsExist == false || other->IsExist() == false)
		return false;

	switch (other->GetName())
	{
	case BodyName::None:
		return false;

	case BodyName::AARectangle:
		return IsCollide((AARectangle*)other);

	case BodyName::Rectangle:
		return IsCollide((Rectangle*)other);

	case BodyName::Line:
		return IsCollide((Line*)other);

	default:
		assert(!"Can't Collide");
		return false;
		break;
	}
}

//名前の取得
BodyName Body::BodyBase::GetName() const {
	return m_Name;
}

//衝突可能かの取得
bool Body::BodyBase::IsExist() const {
	return m_IsExist;
}		

//トランスフォームの設定
void Body::BodyBase::SetTransform(const TransformPtr & transform){
	p_Transform = transform;
}

//衝突可能かの設定
void Body::BodyBase::SetExist(bool isExist) {
	m_IsExist = isExist;
}

//トランスフォームの取得
TransformPtr Body::BodyBase::GetTransform() const {
	return p_Transform;
}
