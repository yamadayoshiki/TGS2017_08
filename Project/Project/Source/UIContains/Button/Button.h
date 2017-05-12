#pragma once

#include "../Base/UI_Base.h"
#include "../../SceneContains/SceneName.h"
#include "../../Utility/EnumRap/EnumRap.h"

#include <unordered_map>

class Button : public UI_Base {
public:
	struct ButtonData {
		std::string file_name;
		int number;
		int anim;
		SceneName next;
		std::unordered_map<GKEYCODE, int> key;
		Texture2DParameter param;
	};
public:
	Button(IWorld* world, const ActorName& name, const GSvector2& position, const IGameManagerPtr& gameManager, const std::string & file_name);

	void regist(const std::string & file_name);

private:
	virtual void onUpdate(float deltaTime)override;
	virtual void onDraw()const override;

	int getIndex(int index, int next);
	void moveSelector(GKEYCODE key);
private:
	std::unordered_map<int, ButtonData> m_Buttons;
	ActorPtr m_Selector;
	int m_Index;
	float m_Timer;
};