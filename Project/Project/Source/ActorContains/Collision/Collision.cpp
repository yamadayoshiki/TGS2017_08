#include "Collision.h"

#include <algorithm>
#include <gslib.h>

// �����m�̏Փ˔���
bool Collision::Sphere_Sphere(const GSvector2& p1, const float& radius1, const GSvector2& p2, const float& radius2){
	return false; // Vector3::Distance(p1, p2) <= radius1 + radius2;
}

// �J�v�Z�����m�̏Փ˔���
bool Collision::Capsule_Capsule(const GSvector2 p1[], const float& radius1, const GSvector2 p2[], const float& radius2) {
	//VECTOR p1_start = Vector3::Vector3ToVECTOR(p1[0]);
	//VECTOR p1_end = Vector3::Vector3ToVECTOR(p1[1]);
	//VECTOR p2_start = Vector3::Vector3ToVECTOR(p2[0]);
	//VECTOR p2_end = Vector3::Vector3ToVECTOR(p2[1]);

	//if (HitCheck_Capsule_Capsule(p1_start, p1_end, radius1, p2_start, p2_end, radius2) == TRUE)return true;
	//else return false;

	return false;// HitCheck_Capsule_Capsule(p1_start, p1_end, radius1, p2_start, p2_end, radius2);
}

// �J�v�Z�����m�̏Փ˔���
bool Collision::Capsule_Capsule(const GSvector2 & pos1, const GSmatrix4 & mat1, const float & len1, const float & radius1, const GSvector2 & pos2, const GSmatrix4 & mat2, const float & len2, const float & radius2)
{
	//Vector3 p1[2], p2[2];
	//p1[0] = pos1 + Vector3::Up * len1 * mat1;
	//p1[1] = pos1 + Vector3::Down * len1 * mat1;
	//p2[0] = pos2 + Vector3::Up * len2 * mat2;
	//p2[1] = pos2 + Vector3::Down * len2 * mat2;

	return false;// Capsule_Capsule(p1, radius1, p2, radius2);
}

// �������m�̏Փ˔���
bool Collision::Segment_Segment(const GSvector2 p1[], const GSvector2 p2[]){
	GSvector2 a = p1[0];
	GSvector2 b = p1[1];
	GSvector2 c = p2[0];
	GSvector2 d = p2[1];

	GSvector2 ab = b - a;
	GSvector2 ac = c - a;
	GSvector2 ad = d - a;
	GSvector2 ca = a - c;
	GSvector2 cb = b - c;
	GSvector2 cd = d - c;

	if (ab.CCW(ac) * ab.CCW(ad) <= 0.0f &&
		cd.CCW(ca) * cd.CCW(cb) <= 0.0f) {
		return true;
	}

	return false;
}

// ���ƃJ�v�Z���̏Փ˔���
bool Collision::Sphere_Capsule(const GSvector2& sphere, const float& sphere_r, const GSvector2 capsule[], const float& capsule_r){
	//VECTOR sphere_pos = Vector3::Vector3ToVECTOR(sphere);
	//VECTOR capsule_start = Vector3::Vector3ToVECTOR(capsule[0]);
	//VECTOR capsule_end = Vector3::Vector3ToVECTOR(capsule[1]);

	return false;// Segment_Point_MinLength_Square(capsule_start, capsule_end, sphere_pos) < std::powf(sphere_r + capsule_r, 2);
}

// ���ƃJ�v�Z���̏Փ˔���
bool Collision::Sphere_Capsule(const GSvector2 & sphere, const float & sphere_r, const GSvector2 & cap_pos, const GSmatrix4 & cap_mat, const float & cap_len, const float & cap_radius)
{
	//Vector3 p[2];
	//p[0] = cap_pos + Vector3::Up * cap_len * cap_mat;
	//p[1] = cap_pos + Vector3::Down * cap_len * cap_mat;

	return false; //Sphere_Capsule(sphere, sphere_r, p, cap_radius);
}

// ���Ɛ����̏Փ˔���
bool Collision::Sphere_Segment(const GSvector2& sphere, const float& sphere_r, const GSvector2 & seg_pos, const GSmatrix4 & seg_mat, const float & seg_len){
	//Vector3 p[2];
	//p[0] = seg_pos + Vector3::Up * seg_len * seg_mat;
	//p[1] = seg_pos + Vector3::Down * seg_len * seg_mat;

	return false;// Sphere_Segment(sphere, sphere_r, p);
}

// ���Ɛ����̏Փ˔���
bool Collision::Sphere_Segment(const GSvector2& pos, const float& radius, const GSvector2 segment[]){
	//VECTOR segment_start = Vector3::Vector3ToVECTOR(segment[0]);
	//VECTOR segment_end   = Vector3::Vector3ToVECTOR(segment[1]);
	//VECTOR sphere_pos = Vector3::Vector3ToVECTOR(pos);
	
	return false; //HitCheck_Line_Sphere(segment_start, segment_end, sphere_pos, radius);
}

// �J�v�Z���Ɛ����̏Փ˔���
bool Collision::Capsule_Segment(const GSvector2 capsule[], const float& capsule_r, const GSvector2 segment[]){
	//VECTOR p1_start = Vector3::Vector3ToVECTOR(capsule[0]);
	//VECTOR p1_end = Vector3::Vector3ToVECTOR(capsule[1]);
	//VECTOR p2_start = Vector3::Vector3ToVECTOR(segment[0]);
	//VECTOR p2_end = Vector3::Vector3ToVECTOR(segment[1]);

	return false; // Segment_Segment_MinLength_Square(p1_start, p1_end, p2_start, p2_end) < std::powf(capsule_r, 2);
}

// �J�v�Z���Ɛ����̏Փ˔���
bool Collision::Capsule_Segment(const GSvector2 & seg_pos, const GSmatrix4 & seg_mat, const float & seg_len, const GSvector2 & cap_pos, const GSmatrix4 & cap_mat, const float & cap_len, const float & cap_radius){
	//Vector3 p1[2], p2[2];
	//p1[0] = cap_pos + Vector3::Up * cap_len * cap_mat;
	//p1[1] = cap_pos + Vector3::Down * cap_len * cap_mat;
	//p2[0] = seg_pos + Vector3::Up * seg_len * seg_mat;
	//p2[1] = seg_pos + Vector3::Down * seg_len * seg_mat;

	return false;// Capsule_Segment(p1, cap_radius, p2);
}

bool Collision::Circle_Circle(const GSvector2 & p1, const float & radius1, const GSvector2 & p2, const float & radius2){
	return (p1 - p2).lengthSq() <= (radius1 + radius2) * (radius1 + radius2);
}


////�_�Ǘ��p�N���X
//class Point {
//	float x;
//	float y;
//	//�R���X�g���N�^
//	Point(float ix, float iy) {
//		x = ix;
//		y = iy;
//	}
//	//�_�ړ��֐�
//	void addPoint(int add) {
//		x = x + add;
//		y = y + add;
//	}
//}
//
////�l�p�`�Ǘ��p�N���X
//class myRect {
//	Point[] rp; //�l���̍��W
//	Point cp; //�������W
//
//			  //�R���X�g���N�^
//			  //������Wp�A��w�A����h
//	myRect(Point p, int iw, int ih) {
//		rp = new Point[4];
//		rp[0] = new Point(p.x, p.y);
//		rp[1] = new Point(p.x + iw, p.y);
//		rp[2] = new Point(p.x + iw, p.y + ih);
//		rp[3] = new Point(p.x, p.y + ih);
//		cp = new Point(p.x + iw / 2, p.y + ih / 2);
//	}
//	//���S�_���ړ�����֐�
//	void moveCenter(int move) {
//		cp.addPoint(move);
//		for (int i = 0; i < 4; i++) {
//			rp[i].addPoint(move);
//		}
//	}
//	//�l�p�`��`�悷��֐�
//	void dispRect(int c) {
//		stroke(c);
//		strokeWeight(4);
//		line(rp[0].x, rp[0].y, rp[1].x, rp[1].y);
//		line(rp[1].x, rp[1].y, rp[2].x, rp[2].y);
//		line(rp[2].x, rp[2].y, rp[3].x, rp[3].y);
//		line(rp[3].x, rp[3].y, rp[0].x, rp[0].y);
//	}
//	//�l�p�`�� deg�x��]������֐�
//	void rotate(float deg) {
//		rp[0] = caclRotate(rp[0], cp, deg);
//		rp[1] = caclRotate(rp[1], cp, deg);
//		rp[2] = caclRotate(rp[2], cp, deg);
//		rp[3] = caclRotate(rp[3], cp, deg);
//	}
//
//	/**************************************************
//	* ���@�藝��]���W�v�Z�֐�
//	*-------------------------------------------------
//	* ��]����_���W p1
//	* ��]�������W cp
//	* ��]�p�x deg
//	***************************************************/
//	Point caclRotate(Point p1, Point cp, float deg) {
//		float cx, cy;
//		cx = (cp.x - p1.x)*cos(radians(deg)) - (cp.y - p1.y)*sin(radians(deg)) + cp.x;
//		cy = (cp.x - p1.x)*sin(radians(deg)) + (cp.y - p1.y)*cos(radians(deg)) + cp.y;
//		return(new Point(cx, cy));
//	}
//}
//
////�O���[�o���ϐ�
//myRect rectWhite; //���l�p�`
//myRect rectBlue; //�l�p�`
//int rw, rh; //�l�p�`�̕��ƍ���
//int moveW, moveB; //�l�p�`�̈ړ���
//float deg; //��]�p�x
//int c1, c2; //�`��F
//
//			//���������֐�
//void setup() {
//	size(300, 300);
//
//	rw = 100; //�l�p�`�̕�
//	rh = 50; //�l�p�`�̍���
//	moveW = 2; //���l�p�͉��Ɉړ�
//	moveB = -2; //�l�p�͏�Ɉړ�
//
//				//�l�p�`���쐬����
//	rectWhite = new myRect(new Point(0, 0), rw, rh);
//	rectBlue = new myRect(new Point(width - rw, height - rh), rw, rh);
//	deg = 2;
//	frameRate(30);
//}
//
////�`�揈���֐�
//void draw() {
//	//��]�������l�p�`�̎l�����W���v�Z����
//	rectWhite.rotate(deg);
//	rectBlue.rotate(-deg);
//
//	//�Փ˔�����s��
//	//���l�p�� [0]-[1] �Ɛl�p��[0]-[1]�A[1]-[2]�A[2]-[3]�A[3]-[0]
//	//���l�p�� [1]-[2] �Ɛl�p��[0]-[1]�A[1]-[2]�A[2]-[3]�A[3]-[0]
//	//���l�p�� [2]-[3] �Ɛl�p��[0]-[1]�A[1]-[2]�A[2]-[3]�A[3]-[0]
//	//���l�p�� [3]-[0] �Ɛl�p��[0]-[1]�A[1]-[2]�A[2]-[3]�A[3]-[0] 
//	//���N���X���肷��
//
//	boolean t1, t2;
//
//	//i �͔��l�p��4�ӂ̃C���f�b�N�X
//	for (int i = 0; i < 4; i++) {
//		//���W�z��3-4�̔�r�Ȃ�A3-0�̔�r�ɒu��������
//		int toi;
//		toi = i + 1;
//		if (toi > 3) toi = 0;
//
//		//j �͐l�p��4�ӂ̃C���f�b�N�X
//		for (int j = 0; j < 4; j++) {
//			//���W�z��3-4�̔�r�Ȃ�A3-0�̔�r�ɒu��������
//			int toj;
//			toj = j + 1;
//			if (toj > 3) toj = 0;
//
//			//�N���X����
//			t1 = isCollisionSide(rectWhite.rp[i], rectWhite.rp[toi],
//				rectBlue.rp[j], rectBlue.rp[toj]);
//
//			t2 = isCollisionSide(rectBlue.rp[j], rectBlue.rp[toj],
//				rectWhite.rp[i], rectWhite.rp[toi]);
//			if (t1 == true && t2 == true) {
//				//�N���X���Ă���̂ŐԐF�ɂ���
//				c1 = color(255, 100, 100);
//				c2 = c1;
//				break;
//			}
//		}
//	}
//
//	//�`�悷�� 
//	rectWhite.dispRect(c1);
//	rectBlue.dispRect(c2);
//}