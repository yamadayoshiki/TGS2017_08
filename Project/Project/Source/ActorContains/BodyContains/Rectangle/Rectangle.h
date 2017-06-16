#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "../Base/BodyBase.h"

namespace Body
{
	//��`�N���X
	class Rectangle : public BodyBase
	{
	public:
		//�R���X�g���N�^
		Rectangle(
			const float width,
			const float height);
		//�f�X�g���N�^
		~Rectangle();
		//�����̎擾
		float GetWidth();
		//�c���̎擾
		float GetHeigh();

	protected:
		//�����s��`�Ƃ̏Փ˔���
		virtual bool IsCollide(AARectangle* other) override;
		//��`�Ƃ̏Փ˔���
		virtual bool IsCollide(Rectangle* other) override;
		//�����Ƃ̏Փ˔���
		virtual bool IsCollide(Line* other) override;

	protected:
		float m_Width;	//����
		float m_Heigh;	//�c��
	};
}
#endif // !RECTANGLE_H_
