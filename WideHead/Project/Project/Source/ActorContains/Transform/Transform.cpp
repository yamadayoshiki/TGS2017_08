#include "Transform.h"
#include "../../Utility/MathSupport/MathSupport.h"

//コンストラクタ
Transform::Transform(GSvector2 pos, float angle)
	: m_Position(pos)
	, m_Angle(angle) {
}

//デフォルトコンストラクタ
Transform::Transform()
	: m_Position(GSvector2(0.0f, 0.0f))
	, m_Angle(0.0f) {
}

Transform::~Transform(){
}

//正面ベクトルを取得
GSvector2 Transform::GetForward() const {
	return MathSupport::GetAngleToVector2(m_Angle);
}