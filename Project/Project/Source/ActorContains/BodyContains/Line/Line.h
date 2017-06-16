#ifndef LINE_H_
#define LINE_H_

#include "../Base/BodyBase.h"
#include <GSvector2.h>

namespace Body
{
	//�����N���X
	class Line :public BodyBase
	{
	public:
		//�R���X�g���N�^
		Line(const GSvector2 vector);
		//�f�X�g���N�^
		~Line();
		//�x�N�g���̎擾
		GSvector2 GetVector();

	protected:
		//�����s��`�Ƃ̏Փ˔���
		virtual bool IsCollide(AARectangle* other) override;
		//��`�Ƃ̏Փ˔���
		virtual bool IsCollide(Body::Rectangle* other) override;
		//�����Ƃ̏Փ˔���
		virtual bool IsCollide(Line* other) override;

	protected:
		GSvector2 m_Vector;	//�x�N�g��
	};
}
#endif