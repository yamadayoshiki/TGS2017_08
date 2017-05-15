#include"BreakWall.h"

#include"../ActorContains/Body/OrientedBoundingBox.h"
#include"../Base/GameManagerContains/GameManager/GameManager.h"

BreakWall::BreakWall(IWorld * world, const GSvector2 & position, const IGameManagerPtr & gameManager)
	: Actor(world, ActorName::BreakBlock, position, gameManager, std::make_shared<NullTexture>(), std::make_shared<OrientedBoundingBox>(GSvector2{ 0.0f, 0.0f }, 0.0f, GSvector2{ 1.0f, 1.0f }))
{
	p_GameManager->GetRenderer2D()->LoadTexture("Block5", "Resource/StreamingAssets/Block5.png");
}

void BreakWall::onUpdate(float deltaTime)
{
}

void BreakWall::onDraw() const
{
	Actor::onDraw();
	gsTextPos(m_Transform.m_Position.x, m_Transform.m_Position.y);
	gsDrawText("a");

}

void BreakWall::onCollide(Actor &)
{
	glColor3f(1.0f, 0.0f, 0.0f);
}

void BreakWall::onMessage(EventMessage event, void *)
{
}

ActorPtr BreakWall::clone(const GSvector2 & position)
{
	return std::make_shared<BreakWall>(p_World, position, p_GameManager);
}
