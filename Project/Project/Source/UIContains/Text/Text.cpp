#include "Text.h"

Text::Text(IWorld * world, const GSvector2 & position, const IGameManagerPtr & gameManager) :
	UI_Base(world, ActorName::UI_Button, GSvector2(0.0f, 0.0f), gameManager) {
}

void Text::onUpdate(float deltaTime){

}

void Text::onDraw() const{

}

void Text::onMessage(EventMessage message, void * param)
{
}
