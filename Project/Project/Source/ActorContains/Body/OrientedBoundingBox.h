#pragma once

#include "Base/Body.h"

// OBB
class OrientedBoundingBox : public Body {
public:
	//OBBÌ»èðì¬
	OrientedBoundingBox(const GSvector2& position, const float & angle, const GSvector2 & extents);
	//OBBÌ»èðì¬(aabbðp)
	explicit OrientedBoundingBox(const BoundingBox& aabb);
public:
	// ÕË»è
	virtual bool isCollide(const IBody& other, HitInfo& hitinfo) const override;
	// ÕË»è()
	virtual bool intersects(const BoundingCircle& other, HitInfo& hitinfo) const override;
	// ÕË»è(JvZ)
	virtual bool intersects(const BoundingCapsule& other, HitInfo& hitinfo) const override;
	// ÕË»è(üª)
	virtual bool intersects(const BoundingSegment& other, HitInfo& hitinfo) const override;
	// ÕË»è(AABB)
	virtual bool intersects(const BoundingBox& other, HitInfo& hitinfo) const override;
	// ÕË»è(OBB)
	virtual bool intersects(const OrientedBoundingBox& other, HitInfo& hitinfo) const override;
	// ÕË»è(C)
	virtual bool intersects(const Ray& other, HitInfo& hitinfo) const override;

	// BodyÌÏ·
	virtual IBodyPtr transform(const Transform& transform) const override;

	// BodyÌÏ·
	OrientedBoundingBox transform_e(const Transform& transform) const;

	// ¸_
	GSvector2 CornerPoint(int cornerIndex)const;
	// é`ÌTCY
	GSvector2 Size()const;
	// SÀW
	GSvector2 Center()const;
	// ñ]
	GSvector2 Rotate(const GSvector2& pos, const float& angle)const;
	
	// }``æ
	virtual void draw() const override;

	// æTCY
	GSvector2 size;
};