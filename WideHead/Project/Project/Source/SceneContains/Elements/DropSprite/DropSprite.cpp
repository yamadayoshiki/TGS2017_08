#include "DropSprite.h"
#include <GSvector2.h>
#include "../../../TextureContains/Texture/Texture.h"
#include "../../../Base/GameManagerContains/IGameManager.h"
#include "../../../Define/Def_Nagano.h"

DropSprite::DropSprite(IWorld * world, const IGameManagerPtr & gameManager)
	: Actor(
		world,
		ActorName::UI_Sprite,
		GSvector2(SCREEN_SIZE.x / 2, -300),
		gameManager,
		std::make_shared<Texture>("WideHead", gameManager->GetDrawManager(), DrawOrder::UI_Front1)) {
}

DropSprite::~DropSprite() {
}

void DropSprite::onUpdate(float deltaTime) {
	if (getPosition().y < 300)
		setPosition(getPosition().lerp(GSvector2(SCREEN_SIZE.x / 2, 300), 0.05f));
}