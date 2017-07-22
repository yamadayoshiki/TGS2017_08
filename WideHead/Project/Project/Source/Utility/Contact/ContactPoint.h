#ifndef CONTACTPOINT_H_
#define CONTACTPOINT_H_
#include <GSvector2.h>
//�Փ˓_
struct ContactPoint
{
	float distance;		//�ђʐ[�x
	GSvector2 pointA;	//����A�̃��[�J�����W
	GSvector2 pointB;	//����B�̃��[�J�����W
	GSvector2 normal;	//�Փ˓_�̖@���x�N�g��

	ContactPoint() :distance(0.0f), pointA(0.0f, 0.0f), pointB(0.0f, 0.0f), normal(0.0f, 0.0f) {}
};
#endif // !CONTACTPOINT_H_
