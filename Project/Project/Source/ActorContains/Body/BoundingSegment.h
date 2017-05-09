#pragma once

#include "Base/Body.h"

// ����
class BoundingSegment : public Body {
public:
	//�����̔�����쐬
	BoundingSegment(const GSvector2& pos, const GSmatrix4& mat, const float& len);
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
	BoundingSegment transform_e(const Transform& transform) const;

	// �n�_����I�_�ւ̕�����Ԃ�
	GSvector2 Direction()const;

	// ���_
	GSvector2 Point(int index)const;

	// �}�`�`��
	virtual void draw() const override;
};
