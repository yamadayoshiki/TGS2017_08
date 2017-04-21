#include "TestObj2.h"

#include "../Body/OrientedBoundingBox.h"
#include "../../Map/Map.h"
#include "../ActorGroup.h"

#include <algorithm>

TestObj2::TestObj2(IWorld * world, const GSvector2 & position) :
	Actor(world, ActorName::Player, position, std::make_shared<OrientedBoundingBox>(GSvector2{ 0.0f, 0.0f }, GSvector2{ 2.0f, 1.0f }, GS_MATRIX4_IDENTITY)) {

	angle = 0.0f;
}

void TestObj2::onUpdate(float deltaTime)
{
	if (gsGetKeyState(GKEY_LEFT) == GS_TRUE) {
		m_Position.x -= 10.0f;
	}
	if (gsGetKeyState(GKEY_RIGHT) == GS_TRUE) {
		m_Position.x += 10.0f;
	}
	if (gsGetKeyState(GKEY_DOWN) == GS_TRUE) {
		m_Position.y += 10.0f;
	}
	if (gsGetKeyState(GKEY_UP) == GS_TRUE) {
		m_Position.y -= 10.0f;
	}

	if (gsGetKeyState(GKEY_Z) == GS_TRUE) {
		angle += 1.0f;
	}
	if (gsGetKeyState(GKEY_X) == GS_TRUE) {
		angle -= 1.0f;
	}

	m_Matrix.setRotationZ(angle);
}

void TestObj2::onDraw() const
{
	glDisable(GL_LIGHTING);
	Actor::onDraw();
	glColor3f(1.0f, 1.0f, 1.0f);
}

void TestObj2::onCollide(Actor &)
{
	glColor3f(1.0f, 0.0f, 0.0f);
}

void TestObj2::onMessage(EventMessage event, void *)
{
}

ActorPtr TestObj2::clone(const GSvector2 & position)
{
	return std::make_shared<TestObj2>(p_World, position);
}
