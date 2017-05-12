#include "Sprite.h"

Sprite::Sprite(IWorld * world, const GSvector2 & position, const IGameManagerPtr & gameManager) :
	UI_Base(world, ActorName::UI_Sprite, position, gameManager) {

}


void Sprite::onUpdate(float deltaTime)
{
}

void Sprite::onDraw() const
{
}

void Sprite::onMessage(EventMessage message, void * param)
{
}
