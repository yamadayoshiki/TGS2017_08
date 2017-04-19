#include "OrientedBoundingBox.h"

#include "BoundingCircle.h"
#include "BoundingCapsule.h"
#include "BoundingSegment.h"
#include "BoundingBox.h"
#include "Ray.h"

#include "Base/HitInfo.h"
#include "../Collision/Collision.h"

static const float EPSILON = 1e-3f;

//OBB�̔�����쐬
OrientedBoundingBox::OrientedBoundingBox(const GSvector2 & position, const GSvector2 & extents, const GSmatrix4& matrix) :
	Body(ShapeType::OBB, position, extents, matrix){
	mAxis[0] = GSvector2(1.0f, 0.0f);
	mAxis[1] = GSvector2(0.0f, 1.0f);
}

//OBB�̔�����쐬(aabb�𗘗p)
OrientedBoundingBox::OrientedBoundingBox(const BoundingBox & aabb) :
	Body(ShapeType::OBB, GSvector2(0, 0), GSvector2(1.0f, 1.0f), GS_MATRIX4_IDENTITY) {
	mAxis[0] = GSvector2(1.0f, 0.0f);
	mAxis[1] = GSvector2(0.0f, 1.0f);
}

// �Փ˔���
bool OrientedBoundingBox::isCollide(const IBody & other, HitInfo & hitinfo) const{
	// �ǂ��炩�̔�����s��Ȃ��ꍇfalse
	if (!other.enabled() || !enabled())return false;
	
	return other.intersects(*this, hitinfo);
}

// �Փ˔���(��)
bool OrientedBoundingBox::intersects(const BoundingCircle & other, HitInfo & hitinfo) const{
	//Vector3 closest_point = ClosestPoint(other.position());
	//hitinfo.intersect = closest_point;
	return false;//other.contains(closest_point);
}

// �Փ˔���(�J�v�Z��)
bool OrientedBoundingBox::intersects(const BoundingCapsule & other, HitInfo & hitinfo) const{
	return false;
}

// �Փ˔���(����)
bool OrientedBoundingBox::intersects(const BoundingSegment & other, HitInfo & hitinfo) const {
	GSvector2 line[2] = {};
	//GSvector2 segment[2] = { other. };

	for (int i = 0; i < 4; i++) {
		line[0] = CornerPoint(i);
		line[1] = CornerPoint(i + 1);
		if (Collision::Segment_Segment(line, line)) {
			return true;

		}
	}
	return false;//result;
}

// �Փ˔���(AABB)
bool OrientedBoundingBox::intersects(const BoundingBox & other, HitInfo & hitinfo) const{
	return false;// intersects(OrientedBoundingBox(other), hitinfo);
}

// �Փ˔���(OBB)
bool OrientedBoundingBox::intersects(const OrientedBoundingBox & other, HitInfo & hitinfo) const{
	GSvector2 line1[2] = { };
	GSvector2 line2[2] = { };

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			line1[0] = CornerPoint(i);
			line1[1] = CornerPoint(i + 1);
			line2[0] = other.CornerPoint(j);
			line2[1] = other.CornerPoint(j + 1);
			if (Collision::Segment_Segment(line1, line2)) {
				return true;
			}
		}
	}
	return false;
}

// �Փ˔���(���C)
bool OrientedBoundingBox::intersects(const Ray & other, HitInfo & hitinfo) const {
	//BoundingBox aabb(-mExtents, mExtents);
	//const bool result = aabb.intersects(other.transform_e(WorldToLocal()), hitinfo);
	//if (result) {
	//	hitinfo.intersect = Vector3::Transform(hitinfo.intersect, LocalToWorld());
	//}
	return false;//result;
}

// Body�̕ϊ�
IBodyPtr OrientedBoundingBox::transform(const GSmatrix4 & mat) const {
	return std::make_shared<OrientedBoundingBox>(transform_e(mat));
}

// Body�̕ϊ�
OrientedBoundingBox OrientedBoundingBox::transform_e(const GSmatrix4 & mat) const{
	//const Vector3 scale = mat.Scale();
	return OrientedBoundingBox(mPosition + GSvector2(mat.getPosition()), mExtents, mat);
}

// �ߐړ_
GSvector2 OrientedBoundingBox::ClosestPoint(const GSvector2 & target) const{
	//const Vector3& d = target - mPosition;
	GSvector2 result = mPosition;
	//result += MathHelper::Clamp(Vector3::Dot(d, mAxis[0]), -mExtents.x, mExtents.x) * mAxis[0];
	//result += MathHelper::Clamp(Vector3::Dot(d, mAxis[1]), -mExtents.y, mExtents.y) * mAxis[1];
	//result += MathHelper::Clamp(Vector3::Dot(d, mAxis[2]), -mExtents.z, mExtents.z) * mAxis[2];
	return result;
}

// ���_
GSvector2 OrientedBoundingBox::CornerPoint(int cornerIndex) const {
	switch (cornerIndex) {
	default:
	case 0: return mPosition + GSvector2(-mExtents.x, +mExtents.y) * mMatrix.getRotateMatrix();
	case 1: return mPosition + GSvector2(+mExtents.x, +mExtents.y) * mMatrix.getRotateMatrix();
	case 2: return mPosition + GSvector2(+mExtents.x, -mExtents.y) * mMatrix.getRotateMatrix();
	case 3: return mPosition + GSvector2(-mExtents.x, -mExtents.y) * mMatrix.getRotateMatrix();
	// 0�Ɠ���
	case 4: return mPosition + GSvector2(-mExtents.x, +mExtents.y) * mMatrix.getRotateMatrix();
	}
}

// ��`�̃T�C�Y
GSvector2 OrientedBoundingBox::Size() const{
	return mExtents * 2.0f;
}

// ���S���W
GSvector2 OrientedBoundingBox::Center() const{
	return mPosition;
}

// ���[�J�����W�֕ϊ�
GSmatrix4 OrientedBoundingBox::LocalToWorld() const {
	return GSmatrix4(GS_MATRIX4_IDENTITY
		//mAxis[0].x, mAxis[0].y, mAxis[0].z, 0.0f,
		//mAxis[1].x, mAxis[1].y, mAxis[1].z, 0.0f,
		//mAxis[2].x, mAxis[2].y, mAxis[2].z, 0.0f,
		//mPosition.x, mPosition.y, mPosition.z, 1.0f
		);
}

// ���[���h���W�֕ϊ�
GSmatrix4 OrientedBoundingBox::WorldToLocal() const {
	return GSmatrix4(GS_MATRIX4_IDENTITY);// Matrix::InvertFast(LocalToWorld());
}

// �}�`�`��
void OrientedBoundingBox::draw() const{
	// ���W�ϊ��̓K��
	GSvector2 lt = CornerPoint(0);
	GSvector2 rt = CornerPoint(1);
	GSvector2 rb = CornerPoint(2);
	GSvector2 lb = CornerPoint(3);
	
	// ��
	glBegin(GL_LINES);
	glVertex2f(lt.x, lt.y);
	glVertex2f(rt.x, rt.y);
	glEnd();
	// �E
	glBegin(GL_LINES);
	glVertex2f(rt.x, rt.y);
	glVertex2f(rb.x, rb.y);
	glEnd();
	// ��
	glBegin(GL_LINES);
	glVertex2f(rb.x, rb.y);
	glVertex2f(lb.x, lb.y);
	glEnd();
	// ��
	glBegin(GL_LINES);
	glVertex2f(lb.x, lb.y);
	glVertex2f(lt.x, lt.y);
	glEnd();
}
