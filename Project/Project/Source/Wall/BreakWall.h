#ifndef BREAK_WALL
#define BREAK_WALL

#include"../ActorContains/Actor/Actor.h"
#include"../Utility/Rederer2D/Renderer2D.h"
#include"../WorldContains/IWorld.h"

class BreakWall : public Actor
{
public:
	BreakWall(IWorld* world, const GSvector2&  position, const IGameManagerPtr& gameManager);
	virtual void onUpdate(float deltaTime) override;
	virtual void onDraw() const override;
	virtual void onCollide(Actor&) override;
	virtual void onMessage(EventMessage event, void*) override;

	virtual ActorPtr clone(const GSvector2& position) override;

private:

};

#endif // !BREAK_WALL