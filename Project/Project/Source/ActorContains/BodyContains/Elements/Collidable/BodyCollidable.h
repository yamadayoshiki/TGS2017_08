#ifndef BODYCOLLIDABLE_H_
#define BODYCOLLIDABLE_H_
#include "../Shape/BodyCollidableShape.h"
#include <vector>
#include "../Primitive/AABB2D/AABB2D.h"
namespace Body
{
	//���̌`��Ǘ�
	struct BodyCollidable {
		int m_NumShapes;							//�ێ�����`��̐�
		std::vector<BodyCollidableShape> m_Shapes;	//�`��z��
		GSvector2 m_AABBHalf;						//AABB�̔����̒���

		//���W�A��]�̐ݒ�
		void SetParam(const GSvector2& position, const float angle) {
			for (int i = 0; i < m_NumShapes; i++) {
				m_Shapes[i].p_Primitive->SetParam(position, angle + m_Shapes[i].m_OffsetAngle, m_Shapes[i].m_OffsetPos);
			}
		}

		//�ǉ�
		void Add(const BodyCollidableShape& shape) {
			m_NumShapes++;
			m_Shapes.push_back(shape);
		}
	};
}

#endif // !BODYCOLLIDABLE_H_