#include "UIManager_Play.h"

UIManager_Play::UIManager_Play(IWorld* world, const IGameManagerPtr & gameManager) :
	Actor(world, ActorName::UI_Manager, GSvector2(), gameManager) {
}

//void UIManager_GamePlay::regist()
//{
//}
//
//void UIManager_GamePlay::create()
//{
//}
