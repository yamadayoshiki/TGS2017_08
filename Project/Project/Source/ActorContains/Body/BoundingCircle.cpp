#include "BoundingCircle.h"
#include "BoundingCapsule.h"
#include "BoundingSegment.h"
#include "BoundingBox.h"
#include "Ray.h"

#include "../Collision/Collision.h"

//���̔�����쐬����
BoundingCircle::BoundingCircle(const GSvector2& pos, const float& rad) :
	Body(ShapeType::Circle, pos, rad){
}

// �Փ˔���
bool BoundingCircle::isCollide(const IBody & other, HitInfo & hitinfo) const {
	// �ǂ��炩�̔�����s��Ȃ��ꍇfalse
	if (!other.enabled() || !enabled())return false;
	
	return other.intersects(*this, hitinfo);
}

// �Փ˔���(��)
bool BoundingCircle::intersects(const BoundingCircle & other, HitInfo & hitinfo) const {
	return Collision::Sphere_Sphere(mPosition, mRadius, other.mPosition, other.mRadius);
}

// �Փ˔���(�J�v�Z��)
bool BoundingCircle::intersects(const BoundingCapsule & other, HitInfo & hitinfo) const {
	return Collision::Sphere_Capsule(mPosition, mRadius, other.position(), other.matrix(), other.length(), other.radius());
}

// �Փ˔���(����)
bool BoundingCircle::intersects(const BoundingSegment & other, HitInfo & hitinfo) const {
	return Collision::Sphere_Segment(mPosition, mRadius, other.position(), other.matrix(), other.length());
}

// �Փ˔���(AABB)
bool BoundingCircle::intersects(const BoundingBox & other, HitInfo & hitinfo) const {
	return false;
}

// �Փ˔���(���C)
bool BoundingCircle::intersects(const Ray & other, HitInfo & hitinfo) const{
	return false;
}

// Body�̕��s�ړ�
IBodyPtr BoundingCircle::translate(const GSvector2 & pos) const {
	return std::make_shared<BoundingCircle>(translate_e(pos));
}

// Body�̕ϊ�
IBodyPtr BoundingCircle::transform(const GSmatrix4 & mat) const {
	return std::make_shared<BoundingCircle>(transform_e(mat));
}

// Body�̕��s�ړ�
BoundingCircle BoundingCircle::translate_e(const GSvector2 & pos) const {
	return BoundingCircle(mPosition + pos, mRadius);
}

// Body�̕ϊ�
BoundingCircle BoundingCircle::transform_e(const GSmatrix4 & mat) const {
	return BoundingCircle(mPosition + GSvector2(mat.getPosition().x, mat.getPosition().y), mRadius * mat.getScale().y);
}

// �}�`�`��
void BoundingCircle::draw(const GSmatrix4 & mat) const{
	//DrawSphere3D(Vector3::Vector3ToVECTOR(mCenter), mRadius, 32, GetColor(255, 0, 0), GetColor(125, 125, 125), FALSE);
}

