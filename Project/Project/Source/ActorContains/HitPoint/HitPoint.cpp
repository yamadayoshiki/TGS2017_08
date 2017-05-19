#include "HitPoint.h"

//�R���X�g���N�^
HitPoint::HitPoint(int maxHp)
	: maxHp(maxHp)
	, hp(maxHp) {
}

//HP�����炷
void HitPoint::Decrease(int damage) {
	hp = hp - damage;
	if (0 >= hp)
		hp = 0;
}

//HP�𑝂₷
void HitPoint::Increase(int recover) {
	hp = hp + recover;
	if (hp >= maxHp)
		hp = maxHp;
}

//HP��0�ȉ���
bool HitPoint::IsDead() {
	return 0 >= hp;
}
