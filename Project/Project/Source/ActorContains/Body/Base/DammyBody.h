#pragma once

#include "Body.h"

// »èÈµBody
class DammyBody : public Body{
public:
	// RXgN^
	DammyBody() {}
	// BodyÌÏ·
	virtual IBodyPtr transform(const Transform & transform) const override { return std::make_shared<DammyBody>(); }
	// ÕË»è
	virtual bool isCollide(const IBody& other, HitInfo& hitinfo) const override { return false; }
	// ÕË»è()
	virtual bool intersects(const BoundingCircle& other, HitInfo& hitinfo) const override { return false; }
	// ÕË»è(JvZ)
	virtual bool intersects(const BoundingCapsule& other, HitInfo& hitinfo) const override { return false; }
	// ÕË»è(üª)
	virtual bool intersects(const BoundingSegment& other, HitInfo& hitinfo) const override { return false; }
	// ÕË»è(AABB)
	virtual bool intersects(const BoundingBox& other, HitInfo& hitinfo) const override { return false; }
	// ÕË»è(OBB)
	virtual bool intersects(const OrientedBoundingBox& other, HitInfo& hitinfo) const override { return false; }
	// ÕË»è(C)
	virtual bool intersects(const Ray& other, HitInfo& hitinfo) const override { return false; }
	// }``æ
	virtual void draw() const override{}
};
