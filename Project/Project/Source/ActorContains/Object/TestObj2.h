#pragma once

#include "../../WorldContains/IWorld.h"
#include "../Actor/Actor.h"
#include"../../Utility/Rederer2D/Renderer2D.h"
// “G
class TestObj2 : public Actor {
public:
	TestObj2(IWorld* world, const GSvector2&  position,IGameManager* gameManager);

	virtual void onUpdate(float deltaTime) override;
	virtual void onDraw() const override;
	virtual void onCollide(Actor&) override;
	virtual void onMessage(EventMessage event, void*) override;

	virtual ActorPtr clone(const GSvector2& position) override;
private:
	float angle;

	Renderer2D* p_Renderer2D;
};
