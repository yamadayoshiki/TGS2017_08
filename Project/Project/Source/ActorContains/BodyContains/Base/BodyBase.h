#ifndef BODYBASE_H_
#define BODYBASE_H_
#include "../Interface/IBody.h"
#include "../../Transform/TransformPtr.h"
#include "../Elements/Collidable/BodyCollidable.h"
#include <GSvector2.h>
#include "../../../Utility/Contact/Contact.h"
#include "../Elements/MotionType.h"
namespace Body
{
	struct ContactSet;
	//�Փ˔���}�`���N���X
	class BodyBase : public Body::IBody
	{
	public:
		//�R���X�g���N�^
		explicit BodyBase(const MotionType type = MotionType::None);
		//�f�X�g���N�^
		~BodyBase();

		//�Փ˂��Ă��邩
		ContactSet IsCollide(IBody* other) override;
		//�g�����X�t�H�[���̐ݒ�
		virtual void SetTransform(const TransformPtr& transform) override;
		//�Փˉ\���̐ݒ�
		void SetExist(bool isExist) override;
		//�ǉ�
		void AddShape(const IPrimitive2DSPtr& p, const GSvector2& offsetPos, float offsetAngle) override;
		//AABB�̐ݒ�
		void SetAABB(const GSvector2& AABBHalf) override;
		//�N���[������
		IBodyPtr Clone(const MotionType type) override;
		//�ό`
		void Transform(const BodyCollidable& bodyCollidable)override;
		//�`��Ǘ��̎擾
		BodyCollidable GetBodyCollidable() override;
	public:
		//�Փ˂��Ă��邩
		ContactSet IsCollide(BodyBase* other);
		//�Փˉ\���̎擾
		bool IsExist() const;
		//�g�����X�t�H�[���̎擾
		TransformPtr GetTransform() const;

	private:
		bool m_IsExist;				//�Փˉ\��
		MotionType m_Type;			//�^�C�v
		BodyCollidable m_Collidable;//�`��Ǘ�

	protected:
		TransformPtr p_Transform;	//�g�����X�t�H�[��
	};
}
#endif
