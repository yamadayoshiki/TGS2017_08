#include "ResultStart.h"
#include"../GameResult.h"
#include"../../../Utility/Sound/SoundName.h"
#include "../../../Utility/InputState/InputState.h"
#include "../../../Base/GameManagerContains/GameManager/GameManager.h"
#include"../../../UIContains/Sprite/Sprite.h"


#include<GSeasing.h>

ResultStart::ResultStart(){
}

ResultStart::~ResultStart(){
}

// �J�n     
void ResultStart::OnStart()
{
	timer_ = 0.0f;
}
// �X�V     
void ResultStart::OnUpdate(float deltaTime)
{
	std::dynamic_pointer_cast<GameResult>(p_Parent.lock())->GetBlock().lock()->ChangeDisplayMode(DisplayMode::Display);
	if(timer_ >= 120.0f)Change(SceneName::ResultStaging);
	timer_ += deltaTime;
}
//�`��
void ResultStart::OnDraw()const{
}
//�I��
void ResultStart::OnEnd(){
	std::dynamic_pointer_cast<GameResult>(p_Parent.lock())->GetBlock().lock()->ChangeDisplayMode(DisplayMode::NonDisplay);
}