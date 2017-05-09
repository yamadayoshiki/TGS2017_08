#include "Button.h"

#include "../../FileReader/CsvReader.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../Utility/InputState/InputState.h"
#include "../../Utility/Rederer2D/Renderer2D.h"
#include "../Selector/Selector.h"
#include "../../WorldContains/EventMessage/EventMessage.h"
#include "../../SceneContains/SceneName.h"
#include <algorithm>

#define STR(var) #var

Button::Button(const IWorldPtr & world, const ActorName & name, const GSvector2 & position, const IGameManagerPtr & gameManager, const std::string & file_name) :
	UI_Base(world, name, position, gameManager) {
	m_Selector = std::make_shared<Selector>(world, GSvector2(0.0f, 0.0f), gameManager);
	addChild(m_Selector);

	regist(file_name);
}

void Button::regist(const std::string & file_name){
	CsvReader csv = CsvReader(file_name);

	// çsÇÃÉãÅ[Év
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
		data.param.SetRect(GSrect(0.0f, 0.0f, csv.getf(row, 8), csv.getf(row, 9)));
		data.param.SetPosition(GSvector2(csv.getf(row, 10), csv.getf(row, 11)));
		data.param.SetCenter(GSvector2(0.0f, 0.0f));
		data.param.SetScale(GSvector2(1.0f, 1.0f));
		data.param.SetRotate(csv.getf(row, 12));
		data.param.SetColor(GScolor(1.0f, 1.0f, 1.0f, csv.getf(row, 13)));

		m_Buttons[data.number] = data;

		p_GameManager->GetRenderer2D()->LoadTexture(data.file_name, data.file_name);
	}

	m_Index = m_Buttons[1].number;
	m_Selector->setPosition(m_Buttons[m_Index].param.GetPosition());
}

void Button::onUpdate(float deltaTime){
	moveSelector(GKEY_UP);
	moveSelector(GKEY_DOWN);
	moveSelector(GKEY_RIGHT);
	moveSelector(GKEY_LEFT);

	m_Selector->setPosition(m_Selector->getPosition().lerp(m_Buttons[m_Index].param.GetPosition(), 0.5f));

	if (p_GameManager->GetInputState()->IsKeyTrigger(GKEY_RETURN) && 
		m_Selector->getPosition() == m_Buttons[m_Index].param.GetPosition()) {
		p_World->sendMessage(EventMessage::END_SCENE, (void*)m_Buttons[m_Index].next);
	}
}

void Button::onDraw() const
{
	for (auto button : m_Buttons) {
		p_GameManager->GetRenderer2D()->DrawTexture(button.second.file_name, button.second.param);
	}
}

void Button::moveSelector(GKEYCODE key) {
	if (p_GameManager->GetInputState()->IsKeyTrigger(key)) {
		m_Index = getIndex(m_Index, m_Buttons[m_Index].key[key]);
	}
}

int Button::getIndex(int index, int next){
	if (next == 0)return index;
	return next;
}


