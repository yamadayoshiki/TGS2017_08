#ifndef IBODY_H_
#define IBODY_H_
#include "../../Transform/TransformPtr.h"

enum class BodyName;
namespace Body
{
	class IBody
	{
	public:
		//�Փ˂��Ă��邩
		virtual bool IsCollide(IBody* other) = 0;
		//���O�̎擾
		virtual BodyName GetName() const = 0;
		//�Փˉ\���̎擾
		virtual bool IsExist() const = 0;
		//�g�����X�t�H�[���̐ݒ�
		virtual void SetTransform(const TransformPtr& transform) = 0;
	};
}
#endif // !IBODY_H_
