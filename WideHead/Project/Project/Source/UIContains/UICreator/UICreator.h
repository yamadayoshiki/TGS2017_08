#pragma once

#include "../../WorldContains/IWorld.h"
#include "../../ActorContains/Actor/Actor.h"

#include "../UIType.h"
#include "../../FileReader/CsvReaderPtr.h"

#include <unordered_map>
#include <string>

struct UIFilePaths;

class UICreator : public Actor {
public:
	UICreator(IWorld* world, const IGameManagerPtr& gameManager, const UIFilePaths& path);
};