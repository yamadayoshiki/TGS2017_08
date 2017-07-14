#include "Selector.h"

#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../Utility/Rederer2D/Renderer2D.h"
#include "../../WorldContains/EventMessage/EventMessage.h"
#include "../../DrawManager/DrawManager.h"
#include "../../TextureContains/Texture/Texture.h"

Selector::Selector(IWorld* world, const GSvector2 & position, const IGameManagerPtr & gameManager) :
	UI_Base(world, ActorName::UI_Selector, position, gameManager, std::make_shared<Texture>("Cursor", gameManager->GetDrawManager(), DrawOrder::UI)) {
}

void Selector::onUpdate(float deltaTime) {
}

void Selector::onDraw() const {
}

void Selector::onMessage(EventMessage message, void* param)
{
	switch (message) {
	case EventMessage::SELECT:
		break;
	default:
		break;
	}
}
