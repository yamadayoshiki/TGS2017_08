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


////点管理用クラス
//class Point {
//	float x;
//	float y;
//	//コンストラクタ
//	Point(float ix, float iy) {
//		x = ix;
//		y = iy;
//	}
//	//点移動関数
//	void addPoint(int add) {
//		x = x + add;
//		y = y + add;
//	}
//}
//
////四角形管理用クラス
//class myRect {
//	Point[] rp; //四隅の座標
//	Point cp; //中央座標
//
//			  //コンストラクタ
//			  //左上座標p、幅w、高さh
//	myRect(Point p, int iw, int ih) {
//		rp = new Point[4];
//		rp[0] = new Point(p.x, p.y);
//		rp[1] = new Point(p.x + iw, p.y);
//		rp[2] = new Point(p.x + iw, p.y + ih);
//		rp[3] = new Point(p.x, p.y + ih);
//		cp = new Point(p.x + iw / 2, p.y + ih / 2);
//	}
//	//中心点を移動する関数
//	void moveCenter(int move) {
//		cp.addPoint(move);
//		for (int i = 0; i < 4; i++) {
//			rp[i].addPoint(move);
//		}
//	}
//	//四角形を描画する関数
//	void dispRect(int c) {
//		stroke(c);
//		strokeWeight(4);
//		line(rp[0].x, rp[0].y, rp[1].x, rp[1].y);
//		line(rp[1].x, rp[1].y, rp[2].x, rp[2].y);
//		line(rp[2].x, rp[2].y, rp[3].x, rp[3].y);
//		line(rp[3].x, rp[3].y, rp[0].x, rp[0].y);
//	}
//	//四角形を deg度回転させる関数
//	void rotate(float deg) {
//		rp[0] = caclRotate(rp[0], cp, deg);
//		rp[1] = caclRotate(rp[1], cp, deg);
//		rp[2] = caclRotate(rp[2], cp, deg);
//		rp[3] = caclRotate(rp[3], cp, deg);
//	}
//
//	/**************************************************
//	* 加法定理回転座標計算関数
//	*-------------------------------------------------
//	* 回転する点座標 p1
//	* 回転中央座標 cp
//	* 回転角度 deg
//	***************************************************/
//	Point caclRotate(Point p1, Point cp, float deg) {
//		float cx, cy;
//		cx = (cp.x - p1.x)*cos(radians(deg)) - (cp.y - p1.y)*sin(radians(deg)) + cp.x;
//		cy = (cp.x - p1.x)*sin(radians(deg)) + (cp.y - p1.y)*cos(radians(deg)) + cp.y;
//		return(new Point(cx, cy));
//	}
//}
//
////グローバル変数
//myRect rectWhite; //白四角形
//myRect rectBlue; //青四角形
//int rw, rh; //四角形の幅と高さ
//int moveW, moveB; //四角形の移動量
//float deg; //回転角度
//int c1, c2; //描画色
//
//			//初期処理関数
//void setup() {
//	size(300, 300);
//
//	rw = 100; //四角形の幅
//	rh = 50; //四角形の高さ
//	moveW = 2; //白四角は下に移動
//	moveB = -2; //青四角は上に移動
//
//				//四角形を作成する
//	rectWhite = new myRect(new Point(0, 0), rw, rh);
//	rectBlue = new myRect(new Point(width - rw, height - rh), rw, rh);
//	deg = 2;
//	frameRate(30);
//}
//
////描画処理関数
//void draw() {
//	//回転させた四角形の四隅座標を計算する
//	rectWhite.rotate(deg);
//	rectBlue.rotate(-deg);
//
//	//衝突判定を行う
//	//白四角辺 [0]-[1] と青四角辺[0]-[1]、[1]-[2]、[2]-[3]、[3]-[0]
//	//白四角辺 [1]-[2] と青四角辺[0]-[1]、[1]-[2]、[2]-[3]、[3]-[0]
//	//白四角辺 [2]-[3] と青四角辺[0]-[1]、[1]-[2]、[2]-[3]、[3]-[0]
//	//白四角辺 [3]-[0] と青四角辺[0]-[1]、[1]-[2]、[2]-[3]、[3]-[0] 
//	//をクロス判定する
//
//	boolean t1, t2;
//
//	//i は白四角の4辺のインデックス
//	for (int i = 0; i < 4; i++) {
//		//座標配列が3-4の比較なら、3-0の比較に置き換える
//		int toi;
//		toi = i + 1;
//		if (toi > 3) toi = 0;
//
//		//j は青四角の4辺のインデックス
//		for (int j = 0; j < 4; j++) {
//			//座標配列が3-4の比較なら、3-0の比較に置き換える
//			int toj;
//			toj = j + 1;
//			if (toj > 3) toj = 0;
//
//			//クロス判定
//			t1 = isCollisionSide(rectWhite.rp[i], rectWhite.rp[toi],
//				rectBlue.rp[j], rectBlue.rp[toj]);
//
//			t2 = isCollisionSide(rectBlue.rp[j], rectBlue.rp[toj],
//				rectWhite.rp[i], rectWhite.rp[toi]);
//			if (t1 == true && t2 == true) {
//				//クロスしているので赤色にする
//				c1 = color(255, 100, 100);
//				c2 = c1;
//				break;
//			}
//		}
//	}
//
//	//描画する 
//	rectWhite.dispRect(c1);
//	rectBlue.dispRect(c2);
//}