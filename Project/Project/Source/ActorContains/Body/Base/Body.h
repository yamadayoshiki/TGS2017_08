#pragma once

#include "IBody.h"

#include "../../Transform/Transform.h"
#include "../../../Utility/MathSupport/MathSupport.h"
#include <GStype.h>
#include <GSmatrix4.h>

class Body : public IBody {
public:
	// �R���X�g���N�^
	Body() : mType(ShapeType::None), mTransform({ GSvector2(0.0f, 0.0f), 0.0f }), mRadius(0.0f), mLength(0.0f), mDirection(GSvector2(0, 0)), mHeight(0.0f), mWidth(0.0f), mExtents(GSvector2(0, 0)), mEnabled(false) {}
	// �R���X�g���N�^(��)
	Body(const ShapeType& type, const GSvector2& position, const float& radius) :
		mType(type), mTransform({ position, 0.0f }), mRadius(radius), mLength(0.0f), mDirection(GSvector2(0, 0)), mHeight(0.0f), mWidth(0.0f), mExtents(GSvector2(0, 0)), mEnabled(true) {}
	// �R���X�g���N�^(����)
	Body(const ShapeType& type, const GSvector2& position, const GSmatrix4& mat, const float& length) :
		mType(type), mTransform({ position, 0.0f }), mRadius(0.0f), mLength(length), mDirection(GSvector2(0, 0)), mHeight(0.0f), mWidth(0.0f), mExtents(GSvector2(0, 0)), mEnabled(true) {}
	// �R���X�g���N�^(���C)
	Body(const ShapeType& type, const GSvector2& position, const GSmatrix4& mat, const GSvector2& direction) :
		mType(type), mTransform({ position, 0.0f }), mRadius(0.0f), mLength(0.0f), mDirection(direction), mHeight(0.0f), mWidth(0.0f), mExtents(GSvector2(0, 0)), mEnabled(true) {}
	// �R���X�g���N�^(�J�v�Z��)
	Body(const ShapeType& type, const GSvector2& position, const GSmatrix4& mat, const float& radius, const float& length) :
		mType(type), mTransform({ position, 0.0f }), mRadius(radius), mLength(length), mDirection(GSvector2(0, 0)), mHeight(0.0f), mWidth(0.0f), mExtents(GSvector2(0, 0)), mEnabled(true) {}
	// �R���X�g���N�^(AABB)
	Body(const ShapeType& type, const GSvector2& position, const GSvector2& extents) :
		mType(type), mTransform({ position, 0.0f }), mLength(0.0f), mDirection(GSvector2(0, 0)), mHeight(0.0f), mWidth(0.0f), mExtents(GSvector2(0, 0)), mEnabled(true) {}
	// �R���X�g���N�^(OBB)
	Body(const ShapeType& type, const GSvector2& position, const float& angle, const GSvector2& extents) :
		mType(type), mTransform({ position, angle }), mRadius(0.0f), mLength(0.0f), mDirection(GSvector2(0, 0)), mHeight(0.0f), mWidth(0.0f), mExtents(extents), mEnabled(true) {}
	// �f�X�g���N�^
	virtual ~Body() {}

	// �����ON�AOFF
	virtual void active(bool active) override { mEnabled = active; }
	// ���肪���邩�ǂ���
	virtual bool enabled() const override { return mEnabled; }

	// �`��̎擾
	virtual ShapeType type() const override { return mType; }

	// ���S���W�̎擾
	virtual Transform transform() const override { return mTransform; }
	// ���W�̎擾
	virtual GSvector2 position() const override { return mTransform.m_Position; }
	// �p�x�̎擾
	virtual float angle() const override { return mTransform.m_Angle; }
	// �O���x�N�g���̎擾
	virtual GSvector2 forward() const override {
		GSvector2 result = MathSupport::RotateVector(GSvector2(1.0f, 0.0f), mTransform.m_Angle);
		return result.getNormalized();
	}

	// ���a�̎擾
	virtual float radius() const override { return mRadius; }
	// �����̎擾
	virtual float length() const override { return mLength; }
	// �����̎擾
	virtual GSvector2 direction() const override { return mDirection; }

	// �c���̎擾
	virtual float height() const override { return mHeight; }
	// �����̎擾
	virtual float width() const override { return mWidth; }

	// ��`�̑傫���̎擾
	virtual GSvector2 extents() const override { return mExtents; }
	// ��`�̎��̎擾
	virtual GSvector2 axis(const int index) const override { return mAxis[index]; }
	// �_�̎擾
	virtual GSvector2 points(const int index) const override { return mPoints[index]; }

protected:
	// �`��
	ShapeType mType;
	//// ���S���W
	//GSvector2 mPosition;
	//// �ϊ��s��
	//GSmatrix4 mMatrix;

	Transform mTransform;

	// ���a
	float mRadius;
	// ����
	float mLength;

	// ���C�p
	// ����
	GSvector2 mDirection;

	// �{�b�N�X�p
	// �c��
	float mHeight;
	// ����
	float mWidth;

	// ��`�̑傫��
	GSvector2 mExtents;
	// ��`�̎�
	GSvector2 mAxis[3];

	// �_
	GSvector2 mPoints[4];

	// ���肪���邩�ǂ���
	bool mEnabled;
};

