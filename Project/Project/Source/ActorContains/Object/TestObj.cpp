#include "TestObj.h"

#include "../Body/OrientedBoundingBox.h"
#include "../../Map/Map.h"

TestObj::TestObj(IWorld * world, const GSvector2 & position) :
	Actor(world, ActorName::Enemy, position, std::make_shared<OrientedBoundingBox>(GSvector2{ 0.0f, 0.0f }, GSvector2{ 1.0f, 1.0f }, GS_MATRIX4_IDENTITY)){

	angle = 0.0f;
}

void TestObj::onUpdate(float deltaTime)
{	
	if (gsGetKeyState(GKEY_LEFT) == GS_TRUE) {
		m_Position.x -= 0.1f;
	}
	if (gsGetKeyState(GKEY_RIGHT) == GS_TRUE) {
		m_Position.x += 0.1f;
	}
	if (gsGetKeyState(GKEY_UP) == GS_TRUE) {
		m_Position.y += 0.1f;
	}
	if (gsGetKeyState(GKEY_DOWN) == GS_TRUE) {
		m_Position.y -= 0.1f;
	}

	if (gsGetKeyState(GKEY_A) == GS_TRUE) {
		angle += 1.0f;
	}
	if (gsGetKeyState(GKEY_D) == GS_TRUE) {
		angle -= 1.0f;
	}

	m_Matrix.setRotationZ(angle);
}

void TestObj::onDraw() const
{
	glDisable(GL_LIGHTING);
	Actor::onDraw();
	glColor3f(1.0f, 1.0f, 1.0f);
}

void TestObj::onCollide(Actor &)
{
	glColor3f(1.0f, 0.0f, 0.0f);
}

void TestObj::onMessage(EventMessage event, void *)
{
}

ActorPtr TestObj::clone(const GSvector2 & position)
{
	return std::make_shared<TestObj>(p_World, position);
}
