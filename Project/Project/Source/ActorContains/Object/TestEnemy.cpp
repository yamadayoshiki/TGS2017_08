#include "TestEnemy.h"

#include "../Body/OrientedBoundingBox.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"

TestEnemy::TestEnemy(IWorld* world, const GSvector2 & position,const IGameManagerPtr& gameManager) :
	Actor(world, ActorName::Enemy, position,gameManager, std::make_shared<NullTexture>(),std::make_shared<OrientedBoundingBox>(GSvector2{ 0.0f, 0.0f }, 0.0f, GSvector2{ 1.0f, 1.0f })) {
	angle = 0.0f;
	p_GameManager->GetRenderer2D()->LoadTexture("wall", "Resource/Texture/wall.png");
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
	

	//p_GameManager->GetRenderer2D()->DrawTexture("wall", m_Position);

	Actor::onDraw();
	gsTextPos(m_Transform.m_Position.x, m_Transform.m_Position.y);
	gsDrawText("a");

}

void TestEnemy::onCollide(Actor &)
{
	glColor3f(1.0f, 0.0f, 0.0f);

}

void TestEnemy::onMessage(EventMessage event, void *)
{
}

ActorPtr TestEnemy::clone(const GSvector2 & position, const FourDirection& front)
{
	return std::make_shared<TestEnemy>(p_World, position,p_GameManager);
}
