#include "NullActor.h"
#include <GSvector2.h>
NullActor::NullActor(IWorld* world, const IGameManagerPtr& gameManager)
	:Actor(world
		, ActorName::None
		, GSvector2{ 0.0f, 0.0f }
		,gameManager){
}

NullActor::NullActor()
	:NullActor(nullptr,nullptr){
}