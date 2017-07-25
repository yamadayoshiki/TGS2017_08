#ifndef AASEGMENT_H_
#define AASEGMENT_H_
#include <GSvector2.h>
#include "../Interface/IPrimitive2D.h"
//�����s����
namespace Body
{
	//����
	struct AASegment2D : public IPrimitive2D
	{
		GSvector2 point;	//�n�_
		GSvector2 vector;	//�x�N�g��
		const GSvector2 staticVector;

		//�R���X�g���N�^
		AASegment2D(const GSvector2& point, const GSvector2& vector);
		//�f�X�g���N�^
		~AASegment2D();
		//�I�_���擾
		GSvector2 GetEndPoint() const;
		//X���̒������擾
		float LengthX() const;
		//Y���̒������擾
		float LengthY() const;

		//���O�̎擾
		PrimitiveName GetName() const override;
		//���W�A��]�̐ݒ�
		void SetParam(const GSvector2& position, const float angle, const GSvector2& offsetVec) override;
		//�Փ˂��Ă��邩
		Contact IsCollide(IPrimitive2D& p) override;
		//�N���[������
		IPrimitive2D* Clone() override;
	};

	inline AASegment2D::AASegment2D(const GSvector2& point, const GSvector2& vector)
		: point(point), vector(vector), staticVector(vector) {
	}

	inline AASegment2D::~AASegment2D() {
	}

	inline GSvector2 AASegment2D::GetEndPoint() const {
		return point + vector;
	}
	inline float AASegment2D::LengthX() const {
		return fabs(vector.x);
	}
	inline float AASegment2D::LengthY() const {
		return fabs(vector.y);
	}
}
#endif // !AASEGMENT_H_
