#include"CreditStart.h"

#include"../GameCredit.h"
#include"../../../Utility/Sound/SoundName.h"
#include "../../../Utility/InputState/InputState.h"
#include "../../../Base/GameManagerContains/GameManager/GameManager.h"
#include"../../../UIContains/Sprite/Sprite.h"


#include<GSeasing.h>

CreditStart::CreditStart()
	: timer_(0.0f) {
}

CreditStart::~CreditStart() {
}

// �J�n     
void CreditStart::OnStart()
{
	timer_ = 0.0f;
}
// �X�V     
void CreditStart::OnUpdate(float deltaTime)
{
	std::dynamic_pointer_cast<GameCredit>(p_Parent.lock())->GetBlock().lock()->ChangeDisplayMode(DisplayMode::Display);
	if (timer_ >= 120.0f)Change(SceneName::CreditStaging);
	timer_ += deltaTime;
}
//�`��
void CreditStart::OnDraw()const {
}
//�I��
void CreditStart::OnEnd() {
	std::dynamic_pointer_cast<GameCredit>(p_Parent.lock())->GetBlock().lock()->ChangeDisplayMode(DisplayMode::NonDisplay);
}