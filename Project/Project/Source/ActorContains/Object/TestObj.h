#pragma once

#include "../../WorldContains/IWorld.h"
#include "../Actor/Actor.h"
#include"../../Utility/Rederer2D/Renderer2D.h"
// “G
class TestObj : public Actor {
public:
	TestObj(IWorld* world, const GSvector2&  position);

	virtual void onUpdate(float deltaTime) override;
	virtual void onDraw() const override;
	virtual void onCollide(Actor&) override;
	virtual void onMessage(EventMessage event, void*) override;

	virtual ActorPtr clone(const GSvector2& position) override;
private:
	float angle;

	Renderer2D* p_Renderer2D;
};
