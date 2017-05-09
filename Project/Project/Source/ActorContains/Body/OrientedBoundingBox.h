#pragma once

#include "Base/Body.h"

// OBB
class OrientedBoundingBox : public Body {
public:
	//OBB�̔�����쐬
	OrientedBoundingBox(const GSvector2& position, const float & angle, const GSvector2 & extents);
	//OBB�̔�����쐬(aabb�𗘗p)
	explicit OrientedBoundingBox(const BoundingBox& aabb);
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
	OrientedBoundingBox transform_e(const Transform& transform) const;

	// ���_
	GSvector2 CornerPoint(int cornerIndex)const;
	// ��`�̃T�C�Y
	GSvector2 Size()const;
	// ���S���W
	GSvector2 Center()const;
	// ��]
	GSvector2 Rotate(const GSvector2& pos, const float& angle)const;
	
	// �}�`�`��
	virtual void draw() const override;

	// �摜�T�C�Y
	GSvector2 size;
};