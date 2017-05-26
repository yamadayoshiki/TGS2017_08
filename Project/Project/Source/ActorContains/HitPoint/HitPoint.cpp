#include "HitPoint.h"

//コンストラクタ
HitPoint::HitPoint(int maxHp)
	: maxHp(maxHp)
	, hp(maxHp)
	, canDead(true) {
	if (maxHp == 0)
		canDead = false;
}

//HPを減らす
void HitPoint::Decrease(int damage) {
	if (canDead == false)
		return;

	hp = hp - damage;
	if (0 >= hp)
		hp = 0;
}

//HPを増やす
void HitPoint::Increase(int recover) {
	if (canDead == false)
		return;

	hp = hp + recover;
	if (hp >= maxHp)
		hp = maxHp;
}

//HPが0以下か
bool HitPoint::IsDead() {
	if (canDead == false)
		return false;

	else
		return 0 >= hp;
}

//倒せるか倒せないか
bool HitPoint::CanDead(){
	return canDead;
}