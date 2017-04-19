#include "Collision.h"

#include <algorithm>
#include <gslib.h>

// 球同士の衝突判定
bool Collision::Sphere_Sphere(const GSvector2& p1, const float& radius1, const GSvector2& p2, const float& radius2){
	return false; // Vector3::Distance(p1, p2) <= radius1 + radius2;
}

// カプセル同士の衝突判定
bool Collision::Capsule_Capsule(const GSvector2 p1[], const float& radius1, const GSvector2 p2[], const float& radius2) {
	//VECTOR p1_start = Vector3::Vector3ToVECTOR(p1[0]);
	//VECTOR p1_end = Vector3::Vector3ToVECTOR(p1[1]);
	//VECTOR p2_start = Vector3::Vector3ToVECTOR(p2[0]);
	//VECTOR p2_end = Vector3::Vector3ToVECTOR(p2[1]);

	//if (HitCheck_Capsule_Capsule(p1_start, p1_end, radius1, p2_start, p2_end, radius2) == TRUE)return true;
	//else return false;

	return false;// HitCheck_Capsule_Capsule(p1_start, p1_end, radius1, p2_start, p2_end, radius2);
}

// カプセル同士の衝突判定
bool Collision::Capsule_Capsule(const GSvector2 & pos1, const GSmatrix4 & mat1, const float & len1, const float & radius1, const GSvector2 & pos2, const GSmatrix4 & mat2, const float & len2, const float & radius2)
{
	//Vector3 p1[2], p2[2];
	//p1[0] = pos1 + Vector3::Up * len1 * mat1;
	//p1[1] = pos1 + Vector3::Down * len1 * mat1;
	//p2[0] = pos2 + Vector3::Up * len2 * mat2;
	//p2[1] = pos2 + Vector3::Down * len2 * mat2;

	return false;// Capsule_Capsule(p1, radius1, p2, radius2);
}

// 線分同士の衝突判定
bool Collision::Segment_Segment(const GSvector2 p1[], const GSvector2 p2[]){
	float ta = (p2[0].x - p2[1].x) * (p1[0].y - p2[0].y) + (p2[0].y - p2[1].y) * (p2[0].x - p1[0].x);
	float tb = (p2[0].x - p2[1].x) * (p1[1].y - p2[0].y) + (p2[0].y - p2[1].y) * (p2[0].x - p1[1].x);
	float tc = (p1[0].x - p1[1].x) * (p2[0].y - p1[0].y) + (p1[0].y - p1[1].y) * (p1[0].x - p2[0].x);
	float td = (p1[0].x - p1[1].x) * (p2[1].y - p1[0].y) + (p1[0].y - p1[1].y) * (p1[0].x - p2[1].x);

	return tc * td < 0 && ta * tb < 0;
}

// 球とカプセルの衝突判定
bool Collision::Sphere_Capsule(const GSvector2& sphere, const float& sphere_r, const GSvector2 capsule[], const float& capsule_r){
	//VECTOR sphere_pos = Vector3::Vector3ToVECTOR(sphere);
	//VECTOR capsule_start = Vector3::Vector3ToVECTOR(capsule[0]);
	//VECTOR capsule_end = Vector3::Vector3ToVECTOR(capsule[1]);

	return false;// Segment_Point_MinLength_Square(capsule_start, capsule_end, sphere_pos) < std::powf(sphere_r + capsule_r, 2);
}

// 球とカプセルの衝突判定
bool Collision::Sphere_Capsule(const GSvector2 & sphere, const float & sphere_r, const GSvector2 & cap_pos, const GSmatrix4 & cap_mat, const float & cap_len, const float & cap_radius)
{
	//Vector3 p[2];
	//p[0] = cap_pos + Vector3::Up * cap_len * cap_mat;
	//p[1] = cap_pos + Vector3::Down * cap_len * cap_mat;

	return false; //Sphere_Capsule(sphere, sphere_r, p, cap_radius);
}

// 球と線分の衝突判定
bool Collision::Sphere_Segment(const GSvector2& sphere, const float& sphere_r, const GSvector2 & seg_pos, const GSmatrix4 & seg_mat, const float & seg_len){
	//Vector3 p[2];
	//p[0] = seg_pos + Vector3::Up * seg_len * seg_mat;
	//p[1] = seg_pos + Vector3::Down * seg_len * seg_mat;

	return false;// Sphere_Segment(sphere, sphere_r, p);
}

// 球と線分の衝突判定
bool Collision::Sphere_Segment(const GSvector2& pos, const float& radius, const GSvector2 segment[]){
	//VECTOR segment_start = Vector3::Vector3ToVECTOR(segment[0]);
	//VECTOR segment_end   = Vector3::Vector3ToVECTOR(segment[1]);
	//VECTOR sphere_pos = Vector3::Vector3ToVECTOR(pos);
	
	return false; //HitCheck_Line_Sphere(segment_start, segment_end, sphere_pos, radius);
}

// カプセルと線分の衝突判定
bool Collision::Capsule_Segment(const GSvector2 capsule[], const float& capsule_r, const GSvector2 segment[]){
	//VECTOR p1_start = Vector3::Vector3ToVECTOR(capsule[0]);
	//VECTOR p1_end = Vector3::Vector3ToVECTOR(capsule[1]);
	//VECTOR p2_start = Vector3::Vector3ToVECTOR(segment[0]);
	//VECTOR p2_end = Vector3::Vector3ToVECTOR(segment[1]);

	return false; // Segment_Segment_MinLength_Square(p1_start, p1_end, p2_start, p2_end) < std::powf(capsule_r, 2);
}

// カプセルと線分の衝突判定
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
