#ifndef BUTTON_H_
#define BUTTON_H_

#include "../Base/UI_Base.h"
#include "../../SceneContains/SceneName.h"
#include "../../Utility/EnumRap/EnumRap.h"
#include "../../Utility/Texture2DParameter/Texture2DParameterPtr.h"
#include "../../DrawManager/DrawOrderObject.h"
#include <unordered_map>
class Selector;
class Button : public UI_Base {
	enum class Element {
		NAME = 0,	// �e�N�X�`���̖��O
		NUMBER,		// �ԍ�
		SCENE,		// �ړ���
		UP,
		DOWN,
		LEFT,
		RIGHT,
		ANIMATE,	// �A�j���[�V�������邩���Ȃ���
		POS_X,		// ���W.x
		POS_Y,		// ���W.y
		DRAWORDER,	// �`�揇��
	};
public:
	struct ButtonData {
		std::string file_name;
		DrawOrderID drawOrderID;
		int number;
		int anim;
		SceneName next;
		std::unordered_map<GSushort, int> key;
		Texture2DParameterSPtr param;
		GSvector2 m_CursorPos;
	};
public:
	Button(
		IWorld* world,
		const GSvector2& position,
		const IGameManagerPtr& gameManager,
		const std::string & file_name);
	~Button();
	void regist(const std::string & file_name);

private:
	virtual void onUpdate(float deltaTime)override;
	virtual void onDraw()const override;

public:
	void ChangeDisplayMode(const DisplayMode mode) override;

private:
	int getIndex(int index, int next);
	void moveSelector(GSushort button);
private:
	std::unordered_map<int, ButtonData> m_Buttons;
	std::shared_ptr<Selector> p_Selector;
	int m_Index;
	float m_Timer;
	DisplayMode m_Mode;
};

#endif // !BUTTON_H_