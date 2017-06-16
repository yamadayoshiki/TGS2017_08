#pragma once

#include "Base/Body.h"

// �J�v�Z��
class BoundingCapsule : public Body {
public:
	//�J�v�Z���̔�����쐬
	BoundingCapsule(const GSvector2& pos, const GSmatrix4& mat, const float& len, const float& rad);
public:
	// �Փ˔���
	virtual bool isCollide(const IBody& other, HitInfo& hitinfo) const override;
	// �Փ˔���(��)
	virtual bool intersects(const BoundingCircle& other, HitInfo& hitinfo) const override;
	// �Փ˔���(�J�v�Z��)
	virtual bool intersects(const BoundingCapsule& other, HitInfo& hitinfo) const override;
	// �Փ˔���(����)
	virtual bool intersects(const BoundingSegment& other, HitInfo& hitinfo) const override;
	// �Փ˔���(AABB)
	virtual bool intersects(const BoundingBox& other, HitInfo& hitinfo) const override;
	// �Փ˔���(OBB)
	virtual bool intersects(const OrientedBoundingBox& other, HitInfo& hitinfo) const override;
	// �Փ˔���(���C)
	virtual bool intersects(const Ray& other, HitInfo& hitinfo) const override;

	// Body�̕ϊ�
	virtual IBodyPtr transform(const Transform& transform) const override;

	// Body�̕ϊ�
	BoundingCapsule transform_e(const Transform& transform) const;

	// �}�`�`��
	virtual void draw() const override;
};