#pragma once

#include <GStype.h>
#include <vector>
#include "../Base/HitInfo.h"

class Collision {
public:
	// 球同士の衝突判定
	static bool Sphere_Sphere(const GSvector2& p1, const float& radius1, const GSvector2& p2, const float& radius2);
	
	// カプセル同士の衝突判定
	static bool Capsule_Capsule(const GSvector2 p1[], const float& radius1, const GSvector2 p2[], const float& radius2);
	static bool Capsule_Capsule(const GSvector2& pos1, const GSmatrix4& mat1, const float & len1, const float& radius1, const GSvector2& pos2, const GSmatrix4& mat2, const float & len2, const float& radius2);

	// 線分同士の衝突判定
	static bool Segment_Segment(const GSvector2 p1[], const GSvector2 p2[], GSvector2& intersect);

	// 球とカプセルの衝突判定
	static bool Sphere_Capsule(const GSvector2& sphere, const float& sphere_r, const GSvector2 capsule[], const float& capsule_r);
	static bool Sphere_Capsule(const GSvector2& sphere, const float& sphere_r, const GSvector2& cap_pos, const GSmatrix4& cap_mat, const float & cap_len, const float& cap_radius);

	// 球と線分の衝突判定
	static bool Sphere_Segment(const GSvector2& sphere, const float& sphere_r, const GSvector2 segment[]);
	static bool Sphere_Segment(const GSvector2& sphere, const float& sphere_r, const GSvector2& seg_pos, const GSmatrix4& seg_mat, const float & seg_len);

	// カプセルと線分の衝突判定
	static bool Capsule_Segment(const GSvector2 capsule[], const float& capsule_r, const GSvector2 segment[]);
	static bool Capsule_Segment(const GSvector2& seg_pos, const GSmatrix4& seg_mat, const float & seg_len, const GSvector2& cap_pos, const GSmatrix4& cap_mat, const float & cap_len, const float& cap_radius);

	// 円同士の衝突判定
	static bool Circle_Circle(const GSvector2& p1, const float& radius1, const GSvector2& p2, const float& radius2);

	// 矩形同士の衝突判定
	static bool Box_Box(const std::vector<GSvector2> box1, const std::vector<GSvector2> box2, HitInfo & hitinfo);

	// 線分と矩形の衝突判定
	static bool Segment_Box(const std::vector<GSvector2> segment, const std::vector<GSvector2> box, HitInfo & hitinfo);

};