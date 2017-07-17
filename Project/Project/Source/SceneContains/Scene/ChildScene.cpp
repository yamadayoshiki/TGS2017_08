#include "ChildScene.h"

ChildScene::ChildScene()
	:Scene() {
}

ChildScene::~ChildScene()
{
}

void ChildScene::SetParent(const IScenePtr & parent) {
	p_Parent = parent;
}