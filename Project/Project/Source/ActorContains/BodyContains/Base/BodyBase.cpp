#include "BodyBase.h"
#include "../../../Utility/Collide2D/IsCollide2D.h"
#include "../../Transform/Transform.h"
#include "../Elements/Shape/BodyCollidableShape.h"
#include "../Elements/ContactSet/ContactSet.h"
#include "../Elements/Primitive/Interface/IPrimitive2D.h"
namespace Body
{
	//�R���X�g���N�^
	BodyBase::BodyBase(const MotionType type)
		: m_IsExist(true)
		, m_Type(type) {
	}

	//�f�X�g���N�^
	BodyBase::~BodyBase() {
	}

	//�Փ˂��Ă��邩
	ContactSet BodyBase::IsCollide(IBody* other) {
		return IsCollide((BodyBase*)other);
	}

	//�Փ˂��Ă��邩
	ContactSet BodyBase::IsCollide(BodyBase * other) {
		ContactSet result;
		if (this->m_IsExist == false || other->m_IsExist == false)
			return result;

		//�u���[�h�t�F�C�Y
		if (IsCollide2D::AABB2DToAABB2D(
			AABB2D(p_Transform->m_Position, this->m_Collidable.m_AABBHalf),
			AABB2D(other->p_Transform->m_Position, other->m_Collidable.m_AABBHalf)).m_NumContacts == 0)
			return result;

		//�i���[�t�F�C�Y
		this->m_Collidable.SetParam(p_Transform->m_Position, p_Transform->m_Angle);
		other->m_Collidable.SetParam(other->p_Transform->m_Position, other->p_Transform->m_Angle);
		for (int i = 0; i < this->m_Collidable.m_Shapes.size(); i++) {
			BodyCollidableShape shapeA = this->m_Collidable.m_Shapes[i];
			for (int j = 0; j < other->m_Collidable.m_Shapes.size(); j++) {
				BodyCollidableShape shapeB = other->m_Collidable.m_Shapes[j];
				//�����o������������
				if ((int)other->m_Type < (int)m_Type) std::swap(shapeA, shapeB);
				Contact l_Result = shapeA.p_Primitive->IsCollide(*shapeB.p_Primitive);
				if (l_Result.m_NumContacts >= 1)
					result.Add(l_Result);
			}
		}
		return result;
	}

	//�`��Ǘ��̎擾
	BodyCollidable Body::BodyBase::GetBodyCollidable() {
		return m_Collidable;
	}

	//�Փˉ\���̎擾
	bool BodyBase::IsExist() const {
		return m_IsExist;
	}

	//�g�����X�t�H�[���̐ݒ�
	void BodyBase::SetTransform(const TransformPtr & transform) {
		p_Transform = transform;
	}

	//�Փˉ\���̐ݒ�
	void BodyBase::SetExist(bool isExist) {
		m_IsExist = isExist;
	}

	void BodyBase::AddShape(const IPrimitive2DSPtr& p, const GSvector2 & offsetPos, float offsetAngle) {
		m_Collidable.Add(BodyCollidableShape(p, offsetPos, offsetAngle));
	}

	void BodyBase::SetAABB(const GSvector2 & AABBHalf) {
		m_Collidable.m_AABBHalf = AABBHalf;
	}

	IBodyPtr BodyBase::Clone(const MotionType type) {
		std::shared_ptr<BodyBase> result = std::make_shared<BodyBase>(type);
		result->m_Collidable = this->m_Collidable;
		return result;
	}

	//�g�����X�t�H�[���̎擾
	TransformPtr BodyBase::GetTransform() const {
		return p_Transform;
	}
}