#include "AnimationSpriteBase.h"

AnimationSpriteBase::AnimationSpriteBase(
	IWorld * world,
	const GSvector2 & position,
	const IGameManagerPtr & gameManager,
	const ITexturePtr & texture)
	:Actor(world, ActorName::UI_Sprite, position, gameManager, texture) {
}