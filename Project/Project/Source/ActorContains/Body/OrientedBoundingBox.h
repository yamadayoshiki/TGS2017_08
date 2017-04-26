#pragma once

#include "Base/Body.h"
#include <vector>

// OBB
class OrientedBoundingBox : public Body {
public:
	//OBB�̔�����쐬
	OrientedBoundingBox(const GSvector2& position, const GSvector2& extents, const GSmatrix4& matrix);
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
	virtual IBodyPtr transform(const GSmatrix4& mat) const override;

	// Body�̕ϊ�
	OrientedBoundingBox transform_e(const GSmatrix4& mat) const;

	// ���_
	GSvector2 CornerPoint(int cornerIndex)const;
	// �l���_�̎擾
	std::vector<GSvector2> CornerPoints()const;
	// ��`�̃T�C�Y
	GSvector2 Size()const;
	// ���S���W
	GSvector2 Center()const;
	
	GSvector2 size;

	// �}�`�`��
	virtual void draw() const override;
};