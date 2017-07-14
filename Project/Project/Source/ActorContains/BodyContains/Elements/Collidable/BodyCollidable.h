#ifndef BODYCOLLIDABLE_H_
#define BODYCOLLIDABLE_H_
#include "../Shape/BodyCollidableShape.h"
#include <vector>
#include "../Primitive/AABB2D/AABB2D.h"
namespace Body
{
	//剛体形状管理
	struct BodyCollidable {
		int m_NumShapes;							//保持する形状の数
		std::vector<BodyCollidableShape> m_Shapes;	//形状配列
		GSvector2 m_AABBHalf;						//AABBの半分の長さ

		//座標、回転の設定
		void SetParam(const GSvector2& position, const float angle) {
			for (int i = 0; i < m_NumShapes; i++) {
				m_Shapes[i].p_Primitive->SetParam(position, angle + m_Shapes[i].m_OffsetAngle, m_Shapes[i].m_OffsetPos);
			}
		}

		//追加
		void Add(const BodyCollidableShape& shape) {
			m_NumShapes++;
			m_Shapes.push_back(shape);
		}
	};
}

#endif // !BODYCOLLIDABLE_H_