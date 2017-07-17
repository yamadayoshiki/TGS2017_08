#include "Button.h"

#include "../../FileReader/CsvReader.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../Utility/InputState/InputState.h"
#include "../../Utility/Rederer2D/Renderer2D.h"
#include "../Selector/Selector.h"
#include "../../WorldContains/EventMessage/EventMessage.h"
#include "../../SceneContains/SceneName.h"
#include "../../Utility/Texture2DParameter/Texture2DParameter.h"
#include "../../DrawManager/DrawManager.h"
#include <algorithm>

#define STR(var) #var

Button::Button(
	IWorld* world,
	const GSvector2 & position,
	const IGameManagerPtr & gameManager,
	const std::string & file_name)
	: UI_Base(world, ActorName::UI_Button, position, gameManager, DrawOrder::UI)
	, m_Mode(DisplayMode::Display) {
	regist(file_name);
}

Button::~Button() {
	for (auto button : m_Buttons) {
		p_GameManager->GetDrawManager()->Remove(button.second.drawOrderID);
	}
}

void Button::regist(const std::string & file_name) {
	CsvReader csv = CsvReader(file_name);

	// ボタンが指定されていないときのみカーソルを生成
	if (csv.rows() == 1) {
		dead();
		return;
	}

	// セレクタを生成
	p_Selector = std::make_shared<Selector>(p_World, GSvector2(0.0f, 0.0f), p_GameManager, DrawOrder::UI_Front2);
	addChild(p_Selector);

	// 行のループ
	for (int row = 1; row < csv.rows(); row++) {
		ButtonData data;

		data.file_name = csv.get(row, static_cast<int>(Element::NAME));
		data.number = csv.geti(row, static_cast<int>(Element::NUMBER));
		data.next = p_GameManager->GetSceneEnum()->GetEnum(csv.get(row, static_cast<int>(Element::SCENE)));
		data.key[GKEY_UP] = csv.geti(row, static_cast<int>(Element::UP));
		data.key[GKEY_DOWN] = csv.geti(row, static_cast<int>(Element::DOWN));
		data.key[GKEY_LEFT] = csv.geti(row, static_cast<int>(Element::LEFT));
		data.key[GKEY_RIGHT] = csv.geti(row, static_cast<int>(Element::RIGHT));
		data.anim = csv.geti(row, static_cast<int>(Element::ANIMATE));
		data.drawOrderID = p_GameManager->GetDrawManager()->RegisterDefaultParam(data.file_name, data.param, (DrawOrder)csv.geti(row, static_cast<int>(Element::DRAWORDER)));
		data.param->m_Position = GSvector2(csv.getf(row, static_cast<int>(Element::POS_X)), csv.getf(row, static_cast<int>(Element::POS_Y)));

		m_Buttons[data.number] = data;
	}

	m_Index = m_Buttons[1].number;
	p_Selector->setPosition(m_Buttons[m_Index].param->m_Position);
}

void Button::onUpdate(float deltaTime) {
	if (getCount() == 0) {
		dead();
		return;
	}

	if (m_Mode == DisplayMode::NonDisplay)return;

	moveSelector(GKEY_UP);
	moveSelector(GKEY_DOWN);
	moveSelector(GKEY_RIGHT);
	moveSelector(GKEY_LEFT);

	p_Selector->setPosition(p_Selector->getPosition().lerp(m_Buttons[m_Index].param->m_Position, 0.5f));

	if (p_GameManager->GetInputState()->IsKeyTrigger(GKEY_RETURN) &&
		p_Selector->getPosition() == m_Buttons[m_Index].param->m_Position) {
		p_World->sendMessage(EventMessage::END_SCENE, (void*)m_Buttons[m_Index].next);
	}
}

void Button::onDraw() const {
}

void Button::ChangeDisplayMode(const DisplayMode mode) {
	m_Mode = mode;
	for (auto itr = m_Buttons.begin(); itr != m_Buttons.end(); itr++)
		p_GameManager->GetDrawManager()->ChageDisplayMode(itr->second.drawOrderID, mode);

	p_Selector->ChangeDisplayMode(mode);
}

void Button::moveSelector(GKEYCODE key) {
	if (p_GameManager->GetInputState()->IsKeyTrigger(key)) {
		m_Index = getIndex(m_Index, m_Buttons[m_Index].key[key]);
	}
}

int Button::getIndex(int index, int next) {
	if (next == 0)return index;
	return next;
}


