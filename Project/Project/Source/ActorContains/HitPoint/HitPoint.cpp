#include "HitPoint.h"

//コンストラクタ
HitPoint::HitPoint(int maxHp)
	: maxHp(maxHp)
	, hp(maxHp) {
}

//HPを減らす
void HitPoint::Decrease(int damage) {
	hp = hp - damage;
	if (0 >= hp)
		hp = 0;
}

//HPを増やす
void HitPoint::Increase(int recover) {
	hp = hp + recover;
	if (hp >= maxHp)
		hp = maxHp;
}

//HPが0以下か
bool HitPoint::IsDead() {
	return 0 >= hp;
}
