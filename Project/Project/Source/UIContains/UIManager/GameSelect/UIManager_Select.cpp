#include "UIManager_Select.h"

UIManager_Select::UIManager_Select(IWorld* world, const IGameManagerPtr & gameManager) :
	Actor(world, ActorName::UI_Manager, GSvector2(), gameManager) {
}

//void UIManager_GameSelect::regist()
//{
//}
//
//void UIManager_GameSelect::create()
//{
//}
