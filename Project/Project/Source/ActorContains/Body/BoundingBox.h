#pragma once

#include "Base/Body.h"

// AABB
class BoundingBox : public Body {
public:
	//AABBÌ»èðì¬
	BoundingBox(const GSvector2 & position, const GSvector2 & extents);
public:
	// ÕË»è
	virtual bool isCollide(const IBody& other, HitInfo& hitinfo) const override;
	// ÕË»è()
	virtual bool intersects(const BoundingCircle& sphere, HitInfo& hitinfo) const override;
	// ÕË»è(JvZ)
	virtual bool intersects(const BoundingCapsule& capsule, HitInfo& hitinfo) const override;
	// ÕË»è(üª)
	virtual bool intersects(const BoundingSegment& segment, HitInfo& hitinfo) const override;
	// ÕË»è(AABB)
	virtual bool intersects(const BoundingBox& aabb, HitInfo& hitinfo) const override;
	// ÕË»è(OBB)
	virtual bool intersects(const OrientedBoundingBox& other, HitInfo& hitinfo) const override;
	// ÕË»è(C)
	virtual bool intersects(const Ray& ray, HitInfo& hitinfo) const override;

	// BodyÌÏ·
	virtual IBodyPtr transform(const Transform& transform) const override;

	// BodyÌÏ·
	BoundingBox transform_e(const Transform& transform) const;

	// ¸_
	GSvector2 CornerPoint(int cornerIndex)const;
	// é`ÌTCY
	GSvector2 Size()const;
	// SÀW
	GSvector2 Center()const;

	// }``æ
	virtual void draw() const override;

	// æTCY
	GSvector2 size;
};
