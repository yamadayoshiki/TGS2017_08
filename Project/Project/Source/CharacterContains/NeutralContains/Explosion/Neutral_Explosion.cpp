#include "Neutral_Explosion.h"

//コンストラクタ
Neutral_Explosion::Neutral_Explosion(
	IWorld* world,
	const GSvector2& position)
	:Actor(world, ActorName::Neutral_Explosion, position) {
}