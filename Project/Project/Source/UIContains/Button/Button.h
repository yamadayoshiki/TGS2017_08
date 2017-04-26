#pragma once

#include "../Base/UI_Base.h"

class Button : public UI_Base {
public:
	struct ButtonData {
		std::string file_name;
		int number;
		int up;
		int down;
		int left;
		int right;
		int anim;
		Texture2DParameter param;
	};
public:
	Button(const IWorldPtr& world, const ActorName& name, const GSvector2& position, const IGameManagerPtr& gameManager, const std::string & file_name);

	void regist(const std::string & file_name);

private:
	virtual void onUpdate(float deltaTime)override;
	virtual void onDraw()const override;
private:
	std::vector<ButtonData> m_Buttons;

};