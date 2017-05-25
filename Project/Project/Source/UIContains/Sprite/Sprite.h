#pragma once

#include "../Base/UI_Base.h"

class Sprite : public UI_Base {
public:
	Sprite(IWorld* world, const IGameManagerPtr& gameManager, const GSvector2& position, const ITexturePtr& texture = std::make_shared<NullTexture>());

	void regist(const std::string & file_name);

private:
	virtual void onUpdate(float deltaTime)override;
	virtual void onDraw()const override;
	virtual void onMessage(EventMessage message, void* param)override;
};