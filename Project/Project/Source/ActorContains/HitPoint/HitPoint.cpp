#include "HitPoint.h"

//�R���X�g���N�^
HitPoint::HitPoint(int maxHp)
	: maxHp(maxHp)
	, hp(maxHp)
	, canDead(true) {
	if (maxHp == 0)
		canDead = false;
}

//HP�����炷
void HitPoint::Decrease(int damage) {
	if (canDead == false)
		return;

	hp = hp - damage;
	if (0 >= hp)
		hp = 0;
}

//HP�𑝂₷
void HitPoint::Increase(int recover) {
	if (canDead == false)
		return;

	hp = hp + recover;
	if (hp >= maxHp)
		hp = maxHp;
}

//HP��0�ȉ���
bool HitPoint::IsDead() {
	if (canDead == false)
		return false;

	else
		return 0 >= hp;
}

//�|���邩�|���Ȃ���
bool HitPoint::CanDead(){
	return canDead;
}