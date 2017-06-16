#pragma once

#include "Base/Body.h"

// AABB
class BoundingBox : public Body {
public:
	//AABB�̔�����쐬
	BoundingBox(const GSvector2 & position, const GSvector2 & extents);
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
	// �Փ˔���(OBB)
	virtual bool intersects(const OrientedBoundingBox& other, HitInfo& hitinfo) const override;
	// �Փ˔���(���C)
	virtual bool intersects(const Ray& ray, HitInfo& hitinfo) const override;

	// Body�̕ϊ�
	virtual IBodyPtr transform(const Transform& transform) const override;

	// Body�̕ϊ�
	BoundingBox transform_e(const Transform& transform) const;

	// ���_
	GSvector2 CornerPoint(int cornerIndex)const;
	// ��`�̃T�C�Y
	GSvector2 Size()const;
	// ���S���W
	GSvector2 Center()const;

	// �}�`�`��
	virtual void draw() const override;

	// �摜�T�C�Y
	GSvector2 size;
};
