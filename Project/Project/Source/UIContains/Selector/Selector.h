#pragma once

#include "../Base/UI_Base.h"

class Selector : public UI_Base {
public:
	Selector(IWorld* world, const GSvector2& position, const IGameManagerPtr& gameManager);

private:
	virtual void onUpdate(float deltaTime)override;
	virtual void onDraw()const override;
	virtual void onMessage(EventMessage message, void* param)override;
};
