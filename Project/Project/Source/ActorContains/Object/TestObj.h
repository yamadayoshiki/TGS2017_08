#pragma once

#include "../../WorldContains/IWorld.h"
#include "../Actor/Actor.h"
#include"../../Utility/Rederer2D/Renderer2D.h"
// “G
class TestObj : public Actor {
public:
	TestObj(const IWorldPtr& world, const GSvector2&  position, const IGameManagerPtr& gameManager);

	virtual void onUpdate(float deltaTime) override;
	virtual void onDraw() const override;
	virtual void onCollide(Actor&) override;
	virtual void onMessage(EventMessage event, void*) override;

	virtual ActorPtr clone(const GSvector2& position) override;
private:
	float angle;

	Renderer2DPtr p_Renderer2D;
};
