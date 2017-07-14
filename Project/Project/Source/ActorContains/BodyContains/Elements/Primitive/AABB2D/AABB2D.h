#ifndef AABB2D_H_
#define AABB2D_H_
#include <GSvector2.h>
#include "../Interface/IPrimitive2D.h"
namespace Body
{
	//�����s��`
	struct AABB2D : public IPrimitive2D
	{
		struct
		{
			GSvector2 centerPoint;		//���S�_
			GSvector2 halfLength;		//�e�������̒���

			GSvector2 staticHalfLength;
		};
		//�R���X�g���N�^
		AABB2D(const GSvector2& centerPoint, const GSvector2& halfLength);
		//X���̒������擾
		float LengthX() const;
		//Y���̒������擾
		float LengthY() const;

		//���O�̎擾
		PrimitiveName GetName() const override;
		//���W�A��]�̐ݒ�
		void SetParam(const GSvector2& position, const float angle, const GSvector2& offsetVec)override;
		//�Փ˂��Ă��邩
		Contact IsCollide(IPrimitive2D& p) override;
		//�N���[������
		IPrimitive2D* Clone() override;
	};

	inline AABB2D::AABB2D(const GSvector2 & centerPoint, const GSvector2 & halfLength)
		: centerPoint(centerPoint), halfLength(halfLength), staticHalfLength(halfLength) {
	}

	inline float AABB2D::LengthX() const {
		return halfLength.x * 2;
	}

	inline float AABB2D::LengthY() const {
		return halfLength.y * 2;
	}
	inline PrimitiveName AABB2D::GetName() const {
		return PrimitiveName::AABB2D;
	}

}

#endif