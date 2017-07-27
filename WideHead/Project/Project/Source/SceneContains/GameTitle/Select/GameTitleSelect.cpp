#include "GameTitleSelect.h"
#include "../GameTitle.h"
#include "../../../UIContains/Button/Button.h"
GameTitleSelect::GameTitleSelect()
{
}

void GameTitleSelect::OnStart(){
	std::dynamic_pointer_cast<GameTitle>(p_Parent.lock())->GetButtonUI().lock()->ChangeDisplayMode(DisplayMode::Display);
}

void GameTitleSelect::OnUpdate(float deltaTime){
}

void GameTitleSelect::OnEnd()
{
}
