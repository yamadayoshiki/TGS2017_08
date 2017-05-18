#pragma once

#include "../Base/UI_Base.h"

class Text : public UI_Base {
public:
	struct Data {
		std::string file_name;
		int anim;
		GSvector2 size;
		GSvector2 rect;
		Texture2DParameter param;
	};
public:
	Text(IWorld* world, const GSvector2& position, const IGameManagerPtr& gameManager);

private:
	virtual void onUpdate(float deltaTime)override;
	virtual void onDraw()const override;
	virtual void onMessage(EventMessage message, void* param)override;
};