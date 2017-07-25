#include "ResultStart.h"
#include"../GameResult.h"
#include"../../../Utility/Sound/SoundName.h"
#include "../../../Utility/InputState/InputState.h"
#include "../../../Base/GameManagerContains/GameManager/GameManager.h"
#include"../../../UIContains/Sprite/Sprite.h"


#include<GSeasing.h>

ResultStart::ResultStart()
	: timer_(0.0f) {
}

ResultStart::~ResultStart() {
}

// 開始     
void ResultStart::OnStart()
{
	timer_ = 0.0f;
}
// 更新     
void ResultStart::OnUpdate(float deltaTime)
{
	std::dynamic_pointer_cast<GameResult>(p_Parent.lock())->GetBlock().lock()->ChangeDisplayMode(DisplayMode::Display);
	if (timer_ >= 120.0f || p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_B)) {
		Change(SceneName::ResultStaging);
	}
	timer_ += deltaTime;
}
//描画
void ResultStart::OnDraw()const {
}
//終了
void ResultStart::OnEnd() {
	std::dynamic_pointer_cast<GameResult>(p_Parent.lock())->GetBlock().lock()->ChangeDisplayMode(DisplayMode::NonDisplay);
}