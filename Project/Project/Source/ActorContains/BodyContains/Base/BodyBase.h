#ifndef BODYBASE_H_
#define BODYBASE_H_

#include "../Interface/IBody.h"
#include "../../Transform/TransformPtr.h"
namespace Body
{
	//�Փ˔���}�`��s�錾
	class AARectangle;
	class Line;
	class Rectangle;

	//�Փ˔���}�`���N���X
	class BodyBase : public Body::IBody
	{
	public:
		//�R���X�g���N�^
		BodyBase(const BodyName name);
		//�f�X�g���N�^
		~BodyBase();

		//�Փ˂��Ă��邩
		bool IsCollide(IBody* other) override;
		//���O�̎擾
		BodyName GetName() const override;
		//�Փˉ\���̎擾
		bool IsExist() const override;
		//�g�����X�t�H�[���̐ݒ�
		virtual void SetTransform(const TransformPtr& transform);

	public:
		//�Փˉ\���̐ݒ�
		void SetExist(bool isExist);
		//�g�����X�t�H�[���̎擾
		TransformPtr GetTransform() const;

	protected:
		//�����s��`�Ƃ̏Փ˔���
		virtual bool IsCollide(AARectangle* other) = 0;
		//��`�Ƃ̏Փ˔���
		virtual bool IsCollide(Rectangle* other) = 0;
		//�����Ƃ̏Փ˔���
		virtual bool IsCollide(Line* other) = 0;

	private:
		BodyName m_Name;			//���O
		bool m_IsExist;				//�Փˉ\��

	protected:
		TransformPtr p_Transform;	//�g�����X�t�H�[��
	};
}
#endif
