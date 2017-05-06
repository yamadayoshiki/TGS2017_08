#include "MathSupport.h"
#include <gslib.h>


float MathSupport::GetAngle(const GSvector2& dynamic, const GSvector2& base) {
	//Œ‹‰Ê
	float result = 0;

	//³‹K‰»
	GSvector2 base_N = base.getNormalized();
	GSvector2 dynamic_N = dynamic.getNormalized();

	//ŠOÏ‚ğ‹‚ß‚é
	float cross = base_N.CCW(dynamic_N);

	//“àÏ‚ğ‹‚ß‚é
	float dot = base_N.dot(dynamic_N);

	//“àÏ‚©‚çŠp“x‚Ö•ÏŠ·
	result = acosf(dot);
	result = result * 180.0f / 3.14f;

	//•„†“ü‚ê‘Ö‚¦
	if (cross < 0)
		result = -result;

	//Œ‹‰Ê‚ğ•Ô‚·
	return result;
}