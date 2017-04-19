#pragma once

#include "Base/Body.h"

// üª
class BoundingSegment : public Body {
public:
	//üªÌ»èðì¬
	BoundingSegment(const GSvector2& pos, const GSmatrix4& mat, const float& len);
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
	virtual IBodyPtr transform(const GSmatrix4& mat) const override;

	// BodyÌÏ·
	BoundingSegment transform_e(const GSmatrix4& mat) const;

	// n_©çI_ÖÌûüðÔ·
	GSvector2 Direction()const;

	// ¸_
	GSvector2 Point(int index)const;

	// }``æ
	virtual void draw() const override;
};
