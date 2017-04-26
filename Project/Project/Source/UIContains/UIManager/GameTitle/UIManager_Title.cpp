#include "UIManager_Title.h"

#include "../../Button/Button.h"

UIManager_Title::UIManager_Title(const IWorldPtr & world, const IGameManagerPtr & gameManager) :
	UIManager(world, gameManager) {

	addChild(std::make_shared<Button>(world, ActorName::Player, m_Position, gameManager, "Resource/StreamingAssets/UI/TitleScene/UI_Title_Button.csv"));
}

//void UIManager_GameTitle::regist()
//{
//}
//
//void UIManager_GameTitle::create()
//{
//}
