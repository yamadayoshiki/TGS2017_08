#include "Selector.h"

#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../Utility/Rederer2D/Renderer2D.h"
#include "../../WorldContains/EventMessage/EventMessage.h"
#include "../../DrawManager/DrawManager.h"
#include "../../TextureContains/Texture/Texture.h"

Selector::Selector(IWorld* world, const GSvector2 & position, const IGameManagerPtr & gameManager, const DrawOrder drawOrder) :
	UI_Base(world, ActorName::UI_Selector, position, gameManager, drawOrder, std::make_shared<Texture>("Cursor", gameManager->GetDrawManager(), drawOrder)) {
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

void Selector::ChangeDisplayMode(const DisplayMode mode){
	p_Texture->ChangeDisplayMode(mode);
}
