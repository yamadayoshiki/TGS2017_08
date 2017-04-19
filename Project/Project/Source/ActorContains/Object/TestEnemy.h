#pragma once

#include "../../WorldContains/IWorld.h"
#include "../Actor/Actor.h"

// “G
class TestEnemy : public Actor {
public:
	TestEnemy(IWorld* world, const GSvector2&  position);

	virtual void onUpdate(float deltaTime) override;
	virtual void onDraw() const override;
	virtual void onCollide(Actor&) override;
	virtual void onMessage(EventMessage event, void*) override;
private:
	float angle;

};
