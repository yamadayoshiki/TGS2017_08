#ifndef BODYCOLLIDABLESHAPE_H_
#define BODYCOLLIDABLESHAPE_H_
#include "../Primitive/Interface/IPrimitive2DPtr.h"
#include <GSvector2.h>
namespace Body
{
	//剛体形状
	struct BodyCollidableShape
	{
		struct {
			IPrimitive2DSPtr p_Primitive;	//形状プリミティブ
			GSvector2 m_OffsetPos;			//オフセット位置
			float m_OffsetAngle;			//オフセット角度
		};

		//コンストラクタ
		BodyCollidableShape(const IPrimitive2DSPtr& primitive, const GSvector2 offsetPos, float offsetAngle)
			:p_Primitive(primitive), m_OffsetPos(offsetPos), m_OffsetAngle(offsetAngle) {
		}
		//コピーコンストラクタ
		BodyCollidableShape(const BodyCollidableShape& bodyCollidableShape) 
		:p_Primitive(bodyCollidableShape.p_Primitive),m_OffsetPos(bodyCollidableShape.m_OffsetPos),m_OffsetAngle(bodyCollidableShape.m_OffsetAngle){
		}
		//デストラクタ
		~BodyCollidableShape() {
		}

		// = 代入演算子
		BodyCollidableShape operator = (const BodyCollidableShape& bodyCollidableShape);
	};

	inline BodyCollidableShape BodyCollidableShape::operator=(const BodyCollidableShape& bodyCollidableShape) {
		this->p_Primitive = bodyCollidableShape.p_Primitive;
		this->m_OffsetPos = bodyCollidableShape.m_OffsetPos;
		this->m_OffsetAngle = bodyCollidableShape.m_OffsetAngle;
		return *this;
	}
}
#endif // !BODYCOLLIDABLESHAPE_H_