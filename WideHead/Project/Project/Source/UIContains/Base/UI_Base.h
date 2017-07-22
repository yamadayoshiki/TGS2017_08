#pragma once

#include "../../WorldContains/IWorld.h"
#include "../../ActorContains/Actor/Actor.h"
#include "../../StagingContains/TransitionStaging/TransitionManager/TransitionManager.h"
enum class DrawOrder;

class UI_Base : public Actor {
public:
	UI_Base(
		IWorld* world,
		const ActorName& name,
		const GSvector2& position,
		const IGameManagerPtr& gameManager,
		const DrawOrder drawOrder,
		const ITexturePtr& texture = std::make_shared<NullTexture>());
	~UI_Base();
	virtual void onUpdate(float deltaTime) override;
	virtual void onDraw() const override;
	virtual void onMessage(EventMessage event, void*) override;

public:
	//•`‰æƒ‚[ƒh‚Ì•ÏX
	virtual void ChangeDisplayMode(const DisplayMode mode) = 0;
private:
	TransitionManager m_Transition;

protected:
	DrawOrder m_DrawOrder;			//•`‰æ‡˜
};