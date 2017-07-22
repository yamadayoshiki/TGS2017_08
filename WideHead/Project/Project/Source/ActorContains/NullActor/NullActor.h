#ifndef NULLACTOR_H_
#define NULLACTOR_H_

#include "../Actor/Actor.h"

class NullActor :public Actor
{
public:
	NullActor(IWorld* world, const IGameManagerPtr& gameManager);
	NullActor();

	virtual void onUpdate(float deltaTime) override {}
	virtual void onDraw() const override {}

private:

};

#endif // !NULLACTOR_H_