#include "NullActor.h"

NullActor::NullActor(const IWorldPtr& world, const IGameManagerPtr& gameManager)
	:Actor(world
		, ActorName::None
		, GSvector2{ 0.0f, 0.0f }
		,gameManager)
{
}

NullActor::NullActor()
	:NullActor(nullptr,nullptr)
{
}

void NullActor::onUpdate(float deltaTime)
{
}

void NullActor::onDraw() const
{
}

ActorPtr NullActor::clone(const GSvector2& position)
{
	return std::make_shared<NullActor>(p_World,p_GameManager);
}
