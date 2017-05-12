#include "Neutral_Explosion.h"

//コンストラクタ
Neutral_Explosion::Neutral_Explosion(
	IWorld* world,
	const GSvector2& position,
	IGameManagerPtr gaemManager)
	:Actor(world, ActorName::Neutral_Explosion, position,gaemManager) {
}