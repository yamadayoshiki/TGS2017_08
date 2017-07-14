#ifndef IBODY_H_
#define IBODY_H_
#include "IBodyPtr.h"
#include "../../Transform/TransformPtr.h"
#include "../Elements/MotionType.h"
#include "../Elements/Primitive/Interface/IPrimitive2DPtr.h"
struct GSvector2;
namespace Body
{
	struct ContactSet;
	class IBody
	{
	public:
		//�Փ˂��Ă��邩
		virtual ContactSet IsCollide(IBody* other) = 0;
		//�g�����X�t�H�[���̐ݒ�
		virtual void SetTransform(const TransformPtr& transform) = 0;
		//�Փˉ\���̐ݒ�
		virtual void SetExist(bool isExist) = 0;
		//�`��̒ǉ�
		virtual void AddShape(const IPrimitive2DSPtr& p, const GSvector2& offsetPos, float offsetAngle) = 0;
		//AABB�̐ݒ�
		virtual void SetAABB(const GSvector2& AABBHalf) = 0;
		//�N���[������
		virtual IBodyPtr Clone(const MotionType type) = 0;
	};
}
#endif