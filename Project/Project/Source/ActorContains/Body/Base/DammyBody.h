#pragma once

#include "Body.h"

// ����Ȃ�Body
class DammyBody : public Body{
public:
	// �R���X�g���N�^
	DammyBody() {}
	// Body�̕��s�ړ�
	virtual IBodyPtr translate(const GSvector2& position) const override { return std::make_shared<DammyBody>(); }
	// Body�̕ϊ�
	virtual IBodyPtr transform(const GSmatrix4& matrix) const override { return std::make_shared<DammyBody>(); }
	// �Փ˔���
	virtual bool isCollide(const IBody& other, HitInfo& hitinfo) const override { return false; }
	// �Փ˔���(��)
	virtual bool intersects(const BoundingCircle& other, HitInfo& hitinfo) const override { return false; }
	// �Փ˔���(�J�v�Z��)
	virtual bool intersects(const BoundingCapsule& other, HitInfo& hitinfo) const override { return false; }
	// �Փ˔���(����)
	virtual bool intersects(const BoundingSegment& other, HitInfo& hitinfo) const override { return false; }
	// �Փ˔���(AABB)
	virtual bool intersects(const BoundingBox& other, HitInfo& hitinfo) const override { return false; }
	// �Փ˔���(���C)
	virtual bool intersects(const Ray& other, HitInfo& hitinfo) const override { return false; }
	// �}�`�`��
	virtual void draw() const override{}
};
