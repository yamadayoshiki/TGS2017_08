#ifndef AARECTANGLE_H_
#define AARECTANGLE_H_

#include "../Base/BodyBase.h"

namespace Body
{
	//�����s��`
	class AARectangle : public BodyBase
	{
	public:
		//�R���X�g���N�^
		AARectangle(
			const float width,
			const float height);
		//�f�X�g���N�^
		~AARectangle();
		//�����̎擾
		virtual float GetWidth();
		//�c���̎擾
		virtual float GetHeigh();

	protected:
		//�����s��`�Ƃ̏Փ˔���
		virtual bool IsCollide(Body::AARectangle* other) override;
		//��`�Ƃ̏Փ˔���
		virtual bool IsCollide(Body::Rectangle* other) override;
		//�����Ƃ̏Փ˔���
		virtual bool IsCollide(Body::Line* other) override;

	protected:
		float m_Width;	//����
		float m_Heigh;	//�c��
	};
}

#endif // !AARECTANGLE_H_
