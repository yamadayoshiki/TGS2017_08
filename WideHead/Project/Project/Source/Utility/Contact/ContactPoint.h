#ifndef CONTACTPOINT_H_
#define CONTACTPOINT_H_
#include <GSvector2.h>
//衝突点
struct ContactPoint
{
	float distance;		//貫通深度
	GSvector2 pointA;	//剛体Aのローカル座標
	GSvector2 pointB;	//剛体Bのローカル座標
	GSvector2 normal;	//衝突点の法線ベクトル

	ContactPoint() :distance(0.0f), pointA(0.0f, 0.0f), pointB(0.0f, 0.0f), normal(0.0f, 0.0f) {}
};
#endif // !CONTACTPOINT_H_
