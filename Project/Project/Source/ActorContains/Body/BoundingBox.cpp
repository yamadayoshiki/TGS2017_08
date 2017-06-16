#include "BoundingBox.h"

#include "BoundingCircle.h"
#include "BoundingCapsule.h"
#include "BoundingSegment.h"
#include "OrientedBoundingBox.h"
#include "Ray.h"

#include "Base/HitInfo.h"
#include "Collision/Collision.h"

#include "../../Define/Def_Nagano.h"
#include "../../Define/Def_Nakayama.h"

#include <cmath>
#include <algorithm>
#include <limits>

//AABB�̔�����쐬
BoundingBox::BoundingBox(const GSvector2 & position, const GSvector2 & extents) :
	Body(ShapeType::Box, position, extents){

	gsLoadTexture(1000, "Resource/Texture/wall.png");
	size = GSvector2(gsTextureGetWidth(gsGetTexture(1000)), gsTextureGetHeight(gsGetTexture(1000)));
}

// �Փ˔���
bool BoundingBox::isCollide(const IBody & other, HitInfo & hitinfo) const {
	// �ǂ��炩�̔�����s��Ȃ��ꍇfalse
	if (!other.enabled() || !enabled())return false;

	return other.intersects(*this, hitinfo);
}

// �Փ˔���(��)
bool BoundingBox::intersects(const BoundingCircle & sphere, HitInfo & hitinfo) const{
	//const GSvector2 point = ClosestPoint(sphere.position());
	//hitinfo.intersect = point;
	return false;// sphere.contains(point);
}

// �Փ˔���(�J�v�Z��)
bool BoundingBox::intersects(const BoundingCapsule & capsule, HitInfo & hitinfo) const{
	return false;
}

// �Փ˔���(����)
bool BoundingBox::intersects(const BoundingSegment & segment, HitInfo & hitinfo) const{
	//float near_ = 0.0f;
	//float far_ = segment.length();
	//const GSvector2 direction = segment.Direction();
	//const bool result = intersects(segment.points(0), direction, near_, far_);
	//if (result) {
	//	hitinfo.intersect = segment.points(0) + direction * near_;
	//}
	return false;// result;
}

// �Փ˔���(AABB)
bool BoundingBox::intersects(const BoundingBox & aabb, HitInfo & hitinfo) const{
	return intersects(OrientedBoundingBox(aabb), hitinfo);
}

bool BoundingBox::intersects(const OrientedBoundingBox & other, HitInfo & hitinfo) const
{
	return other.intersects(*this, hitinfo);
}

// �Փ˔���(���C)
bool BoundingBox::intersects(const Ray & ray, HitInfo & hitinfo) const{
	//float start = 0.0f;
	//float end = 0.00001f;// std::numeric_limits<float>::max();
	//const bool result = intersects(ray.position(), ray.direction(), start, end);
	//if (result) {
	//	hitinfo.intersect = ray.position() + ray.direction() * start;
	//}
	return false;// result;
}

// Body�̕ϊ�
IBodyPtr BoundingBox::transform(const Transform & transform) const{
	return std::make_shared<BoundingBox>(transform_e(transform));
}

// Body�̕ϊ�
BoundingBox BoundingBox::transform_e(const Transform & transform) const{
	return BoundingBox(mTransform.m_Position + transform.m_Position, mExtents);
}

// ���_
GSvector2 BoundingBox::CornerPoint(int cornerIndex) const{
	switch (cornerIndex) {
	default:
	case 0: return mTransform.m_Position + GSvector2(-mExtents.x, -mExtents.y) * CHIP_SIZE / 2;
	case 1: return mTransform.m_Position + GSvector2(+mExtents.x, -mExtents.y) * CHIP_SIZE / 2;
	case 2: return mTransform.m_Position + GSvector2(+mExtents.x, +mExtents.y) * CHIP_SIZE / 2;
	case 3: return mTransform.m_Position + GSvector2(-mExtents.x, +mExtents.y) * CHIP_SIZE / 2;
		// 0�Ɠ���
	case 4: return mTransform.m_Position + GSvector2(-mExtents.x, -mExtents.y) * CHIP_SIZE / 2;
	}
}

// ��`�̃T�C�Y
GSvector2 BoundingBox::Size() const{
	return mExtents * 2.0f;
}

// ���S���W
GSvector2 BoundingBox::Center() const{
	return mTransform.m_Position;
}

// �}�`�`��
void BoundingBox::draw() const{
	// �`��
	gsDrawSprite2D(1000, &mTransform.m_Position, &GSrect(0, 0, size.x, size.y), &GSvector2(CHIP_SIZE / 2, CHIP_SIZE / 2), NULL, &mExtents, mTransform.m_Angle);
}
