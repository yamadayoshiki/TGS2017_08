#pragma once

#include "../../WorldContains/IWorld.h"
#include "../../ActorContains/Actor/Actor.h"

class SpriteCreator : public Actor {
public:
	SpriteCreator(IWorld* world, const GSvector2& position, const IGameManagerPtr& gameManager, const std::string & file_name);

	void regist(const std::string & file_name);
};