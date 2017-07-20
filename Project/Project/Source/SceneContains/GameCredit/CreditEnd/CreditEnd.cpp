#include "CreditEnd.h"

#include<GSmusic.h>

#include"../GameCredit.h"
#include "../../../WorldContains/World/World.h"
#include"../../../ActorContains/ActorGroup.h"
#include "../../../Utility/InputState/InputState.h"
#include "../../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../../Define/Def_Nagano.h"
#include"../../../Utility/Sound/SoundName.h"
#include"../../../Utility/Score/Score.h"
#include"../../../Utility/Texture2DParameter/Texture2DParameter.h"
#include"../../../UIContains/UIManager/UIManager.h"
#include"../../../UIContains/Sprite/Sprite.h"
#include"../../../UIContains/Number/Number.h"
#include"../../../UIContains/Rank/Rank.h"
#include"../../../TextureContains/Texture/Texture.h"

#include"../../Elements/ResultPlayerStaging/ResultPlayerStaging.h"

CreditEnd::CreditEnd(){
}

// 開始     
void CreditEnd::OnStart()
{
	p_GameManager->set_MapOrder(0);
	MapOrder = p_GameManager->get_MapOrder();

	timer_ = 0.0f;
	maxTimer_ = 60.0f;
	m_Color = { 1.0f,1.0f,1.0f,1.0f };
	p_World->addActor(ActorGroup::UI, std::make_shared<ResultPlayerStaging>(p_World.get(), p_GameManager));
}
// 更新     
void CreditEnd::OnUpdate(float deltaTime)
{
	std::dynamic_pointer_cast<GameCredit>(p_Parent.lock())->GetPlatform().lock()->ChangeDisplayMode(DisplayMode::Display);
	std::dynamic_pointer_cast<GameCredit>(p_Parent.lock())->GetTortal().lock()->ChangeDisplayMode(DisplayMode::Display);
	std::dynamic_pointer_cast<GameCredit>(p_Parent.lock())->GetMaxCombo().lock()->ChangeDisplayMode(DisplayMode::Display);
	std::dynamic_pointer_cast<GameCredit>(p_Parent.lock())->GetRetry().lock()->ChangeDisplayMode(DisplayMode::Display);
	std::dynamic_pointer_cast<GameCredit>(p_Parent.lock())->GetScoreUI().lock()->ChangeDisplayMode(DisplayMode::Display);
	std::dynamic_pointer_cast<GameCredit>(p_Parent.lock())->GetScoreUI().lock()->SetNum(p_GameManager->GetScore()->GetTotalScore());
	std::dynamic_pointer_cast<GameCredit>(p_Parent.lock())->GetComboUI().lock()->ChangeDisplayMode(DisplayMode::Display);
	std::dynamic_pointer_cast<GameCredit>(p_Parent.lock())->GetComboUI().lock()->SetNum(p_GameManager->GetPlayerParameter().getMaxCombo());
	std::dynamic_pointer_cast<GameCredit>(p_Parent.lock())->GetRetryUI().lock()->ChangeDisplayMode(DisplayMode::Display);
	std::dynamic_pointer_cast<GameCredit>(p_Parent.lock())->GetRetryUI().lock()->SetNum(p_GameManager->GetPlayerParameter().getRetryCount());
	std::dynamic_pointer_cast<GameCredit>(p_Parent.lock())->GetRankUI().lock()->ChangeDisplayMode(DisplayMode::Display);
	std::dynamic_pointer_cast<GameCredit>(p_Parent.lock())->GetBlock().lock()->ChangeDisplayMode(DisplayMode::Display);

	float t = timer_ / maxTimer_;
	GScolor color = m_Color.lerp(GScolor(1.0f, 1.0f, 1.0f, 0.0f), t);
	std::dynamic_pointer_cast<GameCredit>(p_Parent.lock())->GetBlock().lock()->getTexture()->GetParameter()->m_Color = color;

	if (timer_ >= 60 * 5)
	{
		gsStopMusic();
		p_World->EndRequest(SceneName::GameTitle);
	}
	timer_ += deltaTime;
}
//描画
void CreditEnd::OnDraw()const{
}
//終了
void CreditEnd::OnEnd(){
	std::dynamic_pointer_cast<GameCredit>(p_Parent.lock())->GetPlatform().lock()->ChangeDisplayMode(DisplayMode::NonDisplay);
	std::dynamic_pointer_cast<GameCredit>(p_Parent.lock())->GetTortal().lock()->ChangeDisplayMode(DisplayMode::NonDisplay);
	std::dynamic_pointer_cast<GameCredit>(p_Parent.lock())->GetMaxCombo().lock()->ChangeDisplayMode(DisplayMode::NonDisplay);
	std::dynamic_pointer_cast<GameCredit>(p_Parent.lock())->GetRetry().lock()->ChangeDisplayMode(DisplayMode::NonDisplay);
	std::dynamic_pointer_cast<GameCredit>(p_Parent.lock())->GetScoreUI().lock()->ChangeDisplayMode(DisplayMode::NonDisplay);
	std::dynamic_pointer_cast<GameCredit>(p_Parent.lock())->GetRankUI().lock()->ChangeDisplayMode(DisplayMode::NonDisplay);
	std::dynamic_pointer_cast<GameCredit>(p_Parent.lock())->GetBlock().lock()->ChangeDisplayMode(DisplayMode::NonDisplay);
}