#include "AnimationFont.h"
#include "../../../TextureContains/AnimationTexture/AnimationTexture.h"
#include "../../../Base/GameManagerContains/IGameManager.h"
#include <GSvector2.h>

AnimationFont::AnimationFont(IWorld * world,
	const GSvector2 & position,
	const IGameManagerPtr & gameManager,
	const std::string texName, 
	const float updateFrame)
	: Actor(world,
		ActorName::UI_Sprite,
		position,
		gameManager,
		std::make_shared<AnimationTexture>(texName, gameManager->GetDrawManager(), DrawOrder::UI, 50.0f, updateFrame)),
		p_DrawManager(gameManager->GetDrawManager())
{
	
}

AnimationFont::~AnimationFont() {
}

void AnimationFont::onUpdate(float deltaTime) {
}