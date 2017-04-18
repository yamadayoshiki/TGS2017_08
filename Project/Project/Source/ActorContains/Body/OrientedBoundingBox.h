#pragma once

#include "Base/Body.h"

// OBB
class OrientedBoundingBox : public Body {
public:
	//OBB�̔�����쐬
	OrientedBoundingBox(const Vector3& position, const Vector3& extents, const Vector3& axis_x, const Vector3& axis_y, const Vector3& axis_z);
	//OBB�̔�����쐬(aabb�𗘗p)
	explicit OrientedBoundingBox(const BoundingBox& aabb);
public:
	// �Փ˔���
	virtual bool isCollide(const IBody& other, HitInfo& hitinfo) const override;
	// �Փ˔���(��)
	virtual bool intersects(const BoundingSphere& other, HitInfo& hitinfo) const override;
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
	// �Փ˔���(���f��)
	virtual bool intersects(const Model& other, HitInfo& hitinfo) const override;

	// ��ܔ���(�_)
	virtual bool contains(const Vector3& point) const override;
	// ��ܔ���(��)
	virtual bool contains(const BoundingSphere& sphere) const override;
	// ��ܔ���(����)
	virtual bool contains(const BoundingSegment& segment) const override;
	// ��ܔ���(AABB)
	virtual bool contains(const BoundingBox& aabb) const override;
	// ��ܔ���(OBB)
	virtual bool contains(const OrientedBoundingBox& obb) const override;

	// Body�̕��s�ړ�
	virtual IBodyPtr translate(const Vector3& pos) const override;
	// Body�̕ϊ�
	virtual IBodyPtr transform(const Matrix& mat) const override;

	// Body�̕��s�ړ�
	OrientedBoundingBox translate_e(const Vector3& pos) const;
	// Body�̕ϊ�
	OrientedBoundingBox transform_e(const Matrix& mat) const;

	// �ߐړ_
	Vector3 ClosestPoint(const Vector3& target)const;
	// ���_
	Vector3 CornerPoint(int cornerIndex)const;
	// ��`�̃T�C�Y
	Vector3 Size()const;
	// ���S���W
	Vector3 Center()const;

	// ���[�J�����W�֕ϊ�
	Matrix LocalToWorld() const;
	// ���[���h���W�֕ϊ�
	Matrix WorldToLocal() const;
	
	// �}�`�`��
	virtual void draw() const override;
};