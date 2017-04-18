#include "TestEnemy.h"

#include "../Body/BoundingBox.h"

TestEnemy::TestEnemy(IWorld * world, const GSvector2 & position) :
	Actor(world, ActorName::None, position, std::make_shared<BoundingBox>(GSvector2{ -1.0f, -1.0f }, GSvector2{ 1.0f, 1.0f }, GS_MATRIX4_IDENTITY)){

	
}

void TestEnemy::onUpdate(float deltaTime)
{	
}

void TestEnemy::onDraw() const
{
	Actor::onDraw();

}

void TestEnemy::onCollide(Actor &)
{
}

void TestEnemy::onMessage(EventMessage event, void *)
{
}
