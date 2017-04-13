#include "NullActor.h"

NullActor::NullActor(IWorld* world)
	:Actor(world
		, ActorName::None
		, GSvector2{ 0.0f, 0.0f })
{
}

NullActor::NullActor()
	:NullActor(nullptr)
{
}

void NullActor::onUpdate(float deltaTime)
{
}

void NullActor::onDraw() const
{
}