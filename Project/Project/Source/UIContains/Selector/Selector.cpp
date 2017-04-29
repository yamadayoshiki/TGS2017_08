#include "Selector.h"

#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../Utility/Rederer2D/Renderer2D.h"
#include "../../WorldContains/EventMessage/EventMessage.h"

Selector::Selector(const IWorldPtr & world, const GSvector2 & position, const IGameManagerPtr & gameManager) :
	UI_Base(world, ActorName::UISelector, position, gameManager) {
	p_GameManager->GetRenderer2D()->LoadTexture("Resource/Texture/UI/Block5.png", "Resource/Texture/UI/Block5.png");
}

void Selector::onUpdate(float deltaTime)
{
}

void Selector::onDraw() const
{
	p_GameManager->GetRenderer2D()->DrawTexture("Resource/Texture/UI/Block5.png", m_Position);

}

void Selector::onMessage(EventMessage message, void* param)
{
	switch (message){
	case EventMessage::SELECT:
		break;
	default:
		break;
	}
}
