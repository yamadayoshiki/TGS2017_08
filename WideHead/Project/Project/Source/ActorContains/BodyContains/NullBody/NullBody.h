#ifndef NULLBODY_H_
#define NULLBODY_H_
#include "../Interface/IBody.h"
namespace Body
{
	//�����Ȃ��Փ˔���}�`
	class NullBody : public IBody
	{
	public:
		//�R���X�g���N�^
		NullBody() {}
		//�Փ˂��Ă��邩
		ContactSet IsCollide(IBody* other) override;
		//�g�����X�t�H�[���̐ݒ�
		void SetTransform(const TransformPtr& transform)override {}
		//�Փˉ\���̐ݒ�
		void SetExist(bool isExist) override {}
		//�`��̒ǉ�
		void AddShape(const IPrimitive2DSPtr& p, const GSvector2& offsetPos, float offsetAngle) override {}
		//AABB�̐ݒ�
		void SetAABB(const GSvector2& AABBHalf) {};
		//�N���[������
		IBodyPtr Clone(const MotionType type) { return std::shared_ptr<NullBody>(); }
		//�ό`
		void Transform(const BodyCollidable& bodyCollidable) override {}
		//�`��Ǘ��̎擾
		BodyCollidable GetBodyCollidable() override;
		//�Փˉ\���̐ݒ�
		virtual bool GetExist() const override { return false; }
	};
}

#endif // !NULLBODY_H_