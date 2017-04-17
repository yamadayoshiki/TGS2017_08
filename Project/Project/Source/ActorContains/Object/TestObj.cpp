#include "TestObj.h"

#include "../Body/BoundingBox.h"

TestObj::TestObj(IWorld * world, const GSvector2 & position) :
	Actor(world, ActorName::None, position, std::make_shared<BoundingBox>(GSvector2{ -1.0f, -1.0f }, GSvector2{ 1.0f, 1.0f })){

	
}

void TestObj::onUpdate(float deltaTime)
{	
	if (gsGetKeyState(GKEY_LEFT) == GS_TRUE) {
		m_Position.x -= 1.0f;
	}
	if (gsGetKeyState(GKEY_RIGHT) == GS_TRUE) {
		m_Position.x += 1.0f;
	}
	if (gsGetKeyState(GKEY_UP) == GS_TRUE) {
		m_Position.y += 1.0f;
	}
	if (gsGetKeyState(GKEY_DOWN) == GS_TRUE) {
		m_Position.y -= 1.0f;
	}
}

void TestObj::onDraw() const
{
	Actor::onDraw();
}

void TestObj::onCollide(Actor &)
{
}

void TestObj::onMessage(EventMessage event, void *)
{
}
