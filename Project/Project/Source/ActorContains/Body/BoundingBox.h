#pragma once

#include "Base/Body.h"

// AABB
class BoundingBox : public Body {
public:
	//AABB�̔�����쐬
	BoundingBox(const GSvector2& min, const GSvector2& max, const GSmatrix4 & mat);
public:
	// �Փ˔���
	virtual bool isCollide(const IBody& other, HitInfo& hitinfo) const override;
	// �Փ˔���(��)
	virtual bool intersects(const BoundingCircle& sphere, HitInfo& hitinfo) const override;
	// �Փ˔���(�J�v�Z��)
	virtual bool intersects(const BoundingCapsule& capsule, HitInfo& hitinfo) const override;
	// �Փ˔���(����)
	virtual bool intersects(const BoundingSegment& segment, HitInfo& hitinfo) const override;
	// �Փ˔���(AABB)
	virtual bool intersects(const BoundingBox& aabb, HitInfo& hitinfo) const override;
	// �Փ˔���(���C)
	virtual bool intersects(const Ray& ray, HitInfo& hitinfo) const override;

	// Body�̕��s�ړ�
	virtual IBodyPtr translate(const GSvector2& pos) const override;
	// Body�̕ϊ�
	virtual IBodyPtr transform(const GSmatrix4& mat) const override;

	// Body�̕��s�ړ�
	BoundingBox translate_e(const GSvector2& pos) const;
	// Body�̕ϊ�
	BoundingBox transform_e(const GSmatrix4& mat) const;

	// ���̏Փ˔���
	bool intersects(const GSvector2& position, const GSvector2& direction, float& start, float& end) const;
	// �ߐړ_
	GSvector2 ClosestPoint(const GSvector2& target)const;
	// ���_
	GSvector2 CornerPoint(int cornerIndex)const;
	// ��`�̃T�C�Y
	GSvector2 Size()const;
	// ���S���W
	GSvector2 Center()const;

	// �}�`�`��
	virtual void draw(const GSmatrix4 & mat) const override;
};
