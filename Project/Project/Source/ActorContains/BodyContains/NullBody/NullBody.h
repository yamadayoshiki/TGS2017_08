#ifndef NULLBODY_H_
#define NULLBODY_H_
#include "../Interface/IBody.h"
#include "../BodyName.h"

namespace Body
{
	//�����Ȃ��Փ˔���}�`
	class NullBody : public IBody
	{
	public:
		//�R���X�g���N�^
		NullBody() {}
		//�Փ˂��Ă��邩
		bool IsCollide(IBody* other) override { return false; }
		//���O�̎擾
		BodyName GetName() const override { return BodyName::None; }
		//�Փˉ\���̎擾
		virtual bool IsExist() const { return false; };
		//�g�����X�t�H�[���̐ݒ�
		virtual void SetTransform(const TransformPtr& transform) {};
	};
}

#endif // !NULLBODY_H_
