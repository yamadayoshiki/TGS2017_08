#ifndef NEUTRAL_EXPLOSION_H_
#define NEUTRAL_EXPLOSION_H_

#include "../../../ActorContains/Actor/Actor.h"

class Neutral_Explosion :public Actor
{
public:
	//コンストラクタ
	Neutral_Explosion(
		const IWorldPtr& world, 
		const GSvector2& position,
		IGameManagerPtr gameManager);
};

#endif // !NEUTRAL_EXPLOSION_H_
