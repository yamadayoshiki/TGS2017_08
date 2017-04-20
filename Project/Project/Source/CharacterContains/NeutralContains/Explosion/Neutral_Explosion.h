#ifndef NEUTRAL_EXPLOSION_H_
#define NEUTRAL_EXPLOSION_H_

#include "../../../ActorContains/Actor/Actor.h"

class Neutral_Explosion :public Actor
{
public:
	//コンストラクタ
	Neutral_Explosion(
		IWorld* world,
		const GSvector2& position);
};

#endif // !NEUTRAL_EXPLOSION_H_
