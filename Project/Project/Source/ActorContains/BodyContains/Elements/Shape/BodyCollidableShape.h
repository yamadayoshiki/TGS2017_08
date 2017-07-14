#ifndef BODYCOLLIDABLESHAPE_H_
#define BODYCOLLIDABLESHAPE_H_
#include "../Primitive/Interface/IPrimitive2DPtr.h"
#include <GSvector2.h>
namespace Body
{
	//���̌`��
	struct BodyCollidableShape
	{
		struct {
			IPrimitive2DSPtr p_Primitive;	//�`��v���~�e�B�u
			GSvector2 m_OffsetPos;			//�I�t�Z�b�g�ʒu
			float m_OffsetAngle;			//�I�t�Z�b�g�p�x
		};

		//�R���X�g���N�^
		BodyCollidableShape(const IPrimitive2DSPtr& primitive, const GSvector2 offsetPos, float offsetAngle)
			:p_Primitive(primitive), m_OffsetPos(offsetPos), m_OffsetAngle(offsetAngle) {
		}
		//�R�s�[�R���X�g���N�^
		BodyCollidableShape(const BodyCollidableShape& bodyCollidableShape) 
		:p_Primitive(bodyCollidableShape.p_Primitive),m_OffsetPos(bodyCollidableShape.m_OffsetPos),m_OffsetAngle(bodyCollidableShape.m_OffsetAngle){
		}
		//�f�X�g���N�^
		~BodyCollidableShape() {
		}

		// = ������Z�q
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