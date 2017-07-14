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

Button::Button(IWorld* world, const GSvector2 & position, const IGameManagerPtr & gameManager, const std::string & file_name) :
	UI_Base(world, ActorName::UI_Button, position, gameManager) {
	regist(file_name);
}

Button::~Button() {
	for (auto button : m_Buttons) {
		p_GameManager->GetDrawManager()->Remove(button.second.drawOrderID);
		p_GameManager->UnLoadTexture(button.second.file_name);
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
	m_Selector = std::make_shared<Selector>(p_World, GSvector2(0.0f, 0.0f), p_GameManager);
	addChild(m_Selector);

	// 行のループ
	for (int row = 1; row < csv.rows(); row++) {
		ButtonData data;

		data.file_name = "Resource/Texture/UI/" + csv.get(row, 0);
		data.number = csv.geti(row, 1);
		data.next = p_GameManager->GetSceneEnum()->GetEnum(csv.get(row, 2));
		data.key[GKEY_UP] = csv.geti(row, 3);
		data.key[GKEY_DOWN] = csv.geti(row, 4);
		data.key[GKEY_LEFT] = csv.geti(row, 5);
		data.key[GKEY_RIGHT] = csv.geti(row, 6);
		data.anim = csv.geti(row, 7);
		data.param = std::make_shared<Texture2DParameter>();
		data.param->m_Rect = GSrect(0.0f, 0.0f, csv.getf(row, 8), csv.getf(row, 9));
		data.param->m_Position = GSvector2(csv.getf(row, 10), csv.getf(row, 11));
		data.param->m_Center = GSvector2(0.0f, 0.0f);
		data.param->m_Scale = GSvector2(1.0f, 1.0f);

		m_Buttons[data.number] = data;

		p_GameManager->LoadTexture(data.file_name, data.file_name);
		m_Buttons[data.number].drawOrderID = p_GameManager->GetDrawManager()->Register(data.file_name, data.param, DrawOrder::UI);
		p_GameManager->GetDrawManager()->ChageDisplayMode(data.drawOrderID, DisplayMode::Display);
	}

	m_Index = m_Buttons[1].number;
	m_Selector->setPosition(m_Buttons[m_Index].param->m_Position);
}

void Button::onUpdate(float deltaTime) {
	if (getCount() == 0) {
		dead();
		return;
	}

	moveSelector(GKEY_UP);
	moveSelector(GKEY_DOWN);
	moveSelector(GKEY_RIGHT);
	moveSelector(GKEY_LEFT);

	m_Selector->setPosition(m_Selector->getPosition().lerp(m_Buttons[m_Index].param->m_Position, 0.5f));

	if (p_GameManager->GetInputState()->IsKeyTrigger(GKEY_RETURN) &&
		m_Selector->getPosition() == m_Buttons[m_Index].param->m_Position) {
		p_World->sendMessage(EventMessage::END_SCENE, (void*)m_Buttons[m_Index].next);
	}
}

void Button::onDraw() const{
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


