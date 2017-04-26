#include "OrientedBoundingBox.h"

#include <gslib.h>
#include <vector>

#include "BoundingCircle.h"
#include "BoundingCapsule.h"
#include "BoundingSegment.h"
#include "BoundingBox.h"
#include "Ray.h"

#include "Base/HitInfo.h"
#include "Collision/Collision.h"

#include "../../Define/Def_Nagano.h"
#include "../../Define/Def_Nakayama.h"

static const float EPSILON = 1e-3f;

//OBB�̔�����쐬
OrientedBoundingBox::OrientedBoundingBox(const GSvector2 & position, const GSvector2 & extents, const GSmatrix4& matrix) :
	Body(ShapeType::OBB, position, extents, matrix){
	mAxis[0] = GSvector2(1.0f, 0.0f);
	mAxis[1] = GSvector2(0.0f, 1.0f);
	gsLoadTexture(1000, "Resource/Texture/wall.png");
	size = GSvector2(gsTextureGetWidth(gsGetTexture(1000)), gsTextureGetHeight(gsGetTexture(1000)));
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

	//for (int i = 0; i < 4; i++) {
	//	line[0] = CornerPoint(i);
	//	line[1] = CornerPoint(i + 1);
	//	if (Collision::Segment_Segment(line, line, hitinfo.intersect)) {
	//		return true;

	//	}
	//}
	return false;//result;
}

// �Փ˔���(AABB)
bool OrientedBoundingBox::intersects(const BoundingBox & other, HitInfo & hitinfo) const{
	return false;// intersects(OrientedBoundingBox(other), hitinfo);
}

// �Փ˔���(OBB)
bool OrientedBoundingBox::intersects(const OrientedBoundingBox & other, HitInfo & hitinfo) const {
	// ����
	GSvector2 line1[2] = {};
	GSvector2 line2[2] = {};

	// ��_
	GSvector2 intersect;

	// �z����N���A
	hitinfo.intersects.clear();

	// �e�ӂ̌�������
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			// �e�ӂ���
			line1[0] = CornerPoint(i);
			line1[1] = CornerPoint(i + 1);
			// �e�ӂ���
			line2[0] = other.CornerPoint(j);
			line2[1] = other.CornerPoint(j + 1);
			// �����̔���
			if (Collision::Segment_Segment(line1, line2, intersect)) {
				//  �ŏ��̗v�f�ւ̃C�e���[�^��Ԃ�
				auto itr = std::find(hitinfo.intersects.begin(), hitinfo.intersects.end(), intersect);
				// �����ł��Ȃ������ꍇ
				if (itr == hitinfo.intersects.end()) {
					// �z��Ɍ�_����ǉ�
					hitinfo.intersects.push_back(intersect);
				}
			}
		}
	}
	// �z��̃T�C�Y��0�łȂ��ꍇ�������Ă���
	return hitinfo.intersects.size() > 0;
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

// ���_
GSvector2 OrientedBoundingBox::CornerPoint(int cornerIndex) const {
	switch (cornerIndex) {
	default:
	case 0: return mPosition + GSvector2(-mExtents.x, -mExtents.y) * CHIP_SIZE / 2 * mMatrix.getRotateMatrix();
	case 1: return mPosition + GSvector2(+mExtents.x, -mExtents.y) * CHIP_SIZE / 2 * mMatrix.getRotateMatrix();
	case 2: return mPosition + GSvector2(+mExtents.x, +mExtents.y) * CHIP_SIZE / 2 * mMatrix.getRotateMatrix();
	case 3: return mPosition + GSvector2(-mExtents.x, +mExtents.y) * CHIP_SIZE / 2 * mMatrix.getRotateMatrix();
	// 0�Ɠ���
	case 4: return mPosition + GSvector2(-mExtents.x, -mExtents.y) * CHIP_SIZE / 2 * mMatrix.getRotateMatrix();
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

// �}�`�`��
void OrientedBoundingBox::draw() const{
	// ��]�p�x
	GSvector3 angle = GSvector3(mMatrix.getRoll(), mMatrix.getPitch(), mMatrix.getYaw());
	// �`��
	gsDrawSprite2D(1000, &mPosition, &GSrect(0, 0, size.x, size.y), &GSvector2(CHIP_SIZE / 2, CHIP_SIZE / 2), NULL, &mExtents, 90 - mMatrix.getRoll());
}
