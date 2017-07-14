#ifndef BUTTON_H_
#define BUTTON_H_

#include "../Base/UI_Base.h"
#include "../../SceneContains/SceneName.h"
#include "../../Utility/EnumRap/EnumRap.h"
#include "../../Utility/Texture2DParameter/Texture2DParameterPtr.h"
#include "../../DrawManager/DrawOrderObject.h"
#include <unordered_map>

class Button : public UI_Base {
public:
	struct ButtonData {
		std::string file_name;
		DrawOrderID drawOrderID;
		int number;
		int anim;
		SceneName next;
		std::unordered_map<GKEYCODE, int> key;
		Texture2DParameterSPtr param;
	};
public:
	Button(IWorld* world, const GSvector2& position, const IGameManagerPtr& gameManager, const std::string & file_name);
	~Button();
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

#endif // !BUTTON_H_