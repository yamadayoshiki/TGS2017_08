#pragma once

#include "IBody.h"
#include <GStype.h>
#include <GSmatrix4.h>

class Body : public IBody {
public:
	// �R���X�g���N�^
	Body() : mType(ShapeType::None), mPosition(GSvector2(0, 0)), mMatrix(GS_MATRIX4_IDENTITY), mRadius(0.0f), mLength(0.0f), mDirection(GSvector2(0, 0)), mHeight(0.0f), mWidth(0.0f), mDepth(0.0f), mMin(GSvector2(0, 0)), mMax(GSvector2(0, 0)), mExtents(GSvector2(0, 0)), mEnabled(false){}
	// �R���X�g���N�^(��)
	Body(const ShapeType& type, const GSvector2& position, const float& radius) :
		mType(type), mPosition(position), mMatrix(GS_MATRIX4_IDENTITY), mRadius(radius), mLength(0.0f), mDirection(GSvector2(0, 0)), mHeight(0.0f), mWidth(0.0f), mDepth(0.0f), mMin(GSvector2(0, 0)), mMax(GSvector2(0, 0)), mExtents(GSvector2(0, 0)), mEnabled(true) {}
	// �R���X�g���N�^(����)
	Body(const ShapeType& type, const GSvector2& position, const GSmatrix4& mat, const float& length) :
		mType(type), mPosition(position), mMatrix(mat), mRadius(0.0f), mLength(length), mDirection(GSvector2(0, 0)), mHeight(0.0f), mWidth(0.0f), mDepth(0.0f), mMin(GSvector2(0, 0)), mMax(GSvector2(0, 0)), mExtents(GSvector2(0, 0)), mEnabled(true) {}
	// �R���X�g���N�^(���C)
	Body(const ShapeType& type, const GSvector2& position, const GSmatrix4& mat, const GSvector2& direction) :
		mType(type), mPosition(position), mMatrix(GS_MATRIX4_IDENTITY), mRadius(0.0f), mLength(0.0f), mDirection(direction), mHeight(0.0f), mWidth(0.0f), mDepth(0.0f), mMin(GSvector2(0, 0)), mMax(GSvector2(0, 0)), mExtents(GSvector2(0, 0)), mEnabled(true) {}
	// �R���X�g���N�^(�J�v�Z��)
	Body(const ShapeType& type, const GSvector2& position, const GSmatrix4& mat, const float& radius, const float& length) :
		mType(type), mPosition(position), mMatrix(mat), mRadius(radius), mLength(length), mDirection(GSvector2(0, 0)), mHeight(0.0f), mWidth(0.0f), mDepth(0.0f), mMin(GSvector2(0, 0)), mMax(GSvector2(0, 0)), mExtents(GSvector2(0, 0)), mEnabled(true) {}
	// �R���X�g���N�^(AABB)
	Body(const ShapeType& type, const GSvector2& position, const GSvector2 & min, const GSvector2 & max, const GSmatrix4& mat) :
		mType(type), mPosition(position), mMatrix(mat), mRadius(0.0f), mLength(0.0f), mDirection(GSvector2(0, 0)), mHeight(0.0f), mWidth(0.0f), mDepth(0.0f), mMin(min), mMax(max), mExtents(GSvector2(0, 0)), mEnabled(true) {}
	// �f�X�g���N�^
	virtual ~Body(){}

	// �����ON�AOFF
	virtual void active(bool active) override { mEnabled = active; }
	// ���肪���邩�ǂ���
	virtual bool enabled() const override { return mEnabled; }

	// �`��̎擾
	virtual ShapeType type() const override { return mType; }
	// ���S���W�̎擾
	virtual GSvector2 position() const override { return mPosition; }
	// �ϊ��s��̎擾
	virtual GSmatrix4 matrix() const override { return mMatrix; }
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
	// ���s�̎擾
	virtual float depth() const override { return mDepth; }
	// ��`�̍ŏ��_�̎擾
	virtual GSvector2 box_min() const override { return mMin; }
	// ��`�̍ő�_�̎擾
	virtual GSvector2 box_max() const override { return mMax; }
	// ��`�̑傫���̎擾
	virtual GSvector2 extents() const override { return mExtents; }
	// ��`�̎��̎擾
	virtual GSvector2 axis(const int index) const override { return mAxis[index]; }
	// �_�̎擾
	virtual GSvector2 points(const int index) const override { return mPoints[index]; }
	
protected:
	// �`��
	ShapeType mType;
	// ���S���W
	GSvector2 mPosition;
	// �ϊ��s��
	GSmatrix4 mMatrix;
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
	// ���s
	float mDepth;

	// ��`�̍ŏ��_
	GSvector2 mMin;
	// ��`�̍ő�_
	GSvector2 mMax;

	// ��`�̑傫��
	GSvector2 mExtents;
	// ��`�̎�
	GSvector2 mAxis[3];

	// �_
	GSvector2 mPoints[4];

	// ���肪���邩�ǂ���
	bool mEnabled;
};

