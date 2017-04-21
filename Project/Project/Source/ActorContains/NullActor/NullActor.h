#ifndef NULLACTOR_H_
#define NULLACTOR_H_

#include "../Actor/Actor.h"

class NullActor :public Actor
{
public:
	NullActor(IWorld* world,IGameManager* gameManager);
	NullActor();

	virtual void onUpdate(float deltaTime) override;
	virtual void onDraw() const override;

	virtual ActorPtr clone(const GSvector2& position) override;

private:

};

#endif // !NULLACTOR_H_
