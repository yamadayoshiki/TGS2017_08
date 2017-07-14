#pragma once

#include "../../WorldContains/IWorld.h"
#include "../../ActorContains/Actor/Actor.h"

#include "../../StagingContains/TransitionStaging/TransitionManager/TransitionManager.h"

class UI_Base : public Actor {
public:
	UI_Base(IWorld* world, const ActorName& name, const GSvector2& position, const IGameManagerPtr& gameManager, const ITexturePtr& texture = std::make_shared<NullTexture>());
	~UI_Base();
	virtual void onUpdate(float deltaTime) override;
	virtual void onDraw() const override;
	virtual void onMessage(EventMessage event, void*) override;
private:
	TransitionManager m_Transition;
};