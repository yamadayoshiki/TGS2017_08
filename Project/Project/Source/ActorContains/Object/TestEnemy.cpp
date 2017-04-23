#include "TestEnemy.h"

#include "../Body/OrientedBoundingBox.h"

TestEnemy::TestEnemy(IWorld * world, const GSvector2 & position) :
	Actor(world, ActorName::Enemy, position, std::make_shared<OrientedBoundingBox>(GSvector2{ 0.0f, 0.0f }, GSvector2{ 1.0f, 1.0f }, GS_MATRIX4_IDENTITY)) {
	angle = 0.0f;

	gsLoadTexture(1, "Resource/Texture/wall.png");

}

void TestEnemy::onUpdate(float deltaTime)
{
	if (gsGetKeyState(GKEY_L) == GS_TRUE) {
		angle += 1.0f;
	}
	if (gsGetKeyState(GKEY_K) == GS_TRUE) {
		angle -= 1.0f;
	}
}

void TestEnemy::onDraw() const
{
	gsDrawSprite2D(1, &m_Position, NULL, NULL, NULL, NULL, NULL);

}

void TestEnemy::onCollide(Actor &)
{
	glColor3f(1.0f, 0.0f, 0.0f);

}

void TestEnemy::onMessage(EventMessage event, void *)
{
}

ActorPtr TestEnemy::clone(const GSvector2 & position)
{
	return std::make_shared<TestEnemy>(p_World, position);
}
