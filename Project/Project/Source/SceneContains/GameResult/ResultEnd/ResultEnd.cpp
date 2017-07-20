#include"ResultEnd.h"
#include<GSmusic.h>

#include"../GameResult.h"
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

ResultEnd::ResultEnd() {
}

ResultEnd::~ResultEnd(){
}

// 開始     
void ResultEnd::OnStart()
{
	timer_ = 0.0f;
	maxTimer_ = 60.0f;
	m_Color = { 1.0f,1.0f,1.0f,1.0f };
	p_World->addActor(ActorGroup::UI, std::make_shared<ResultPlayerStaging>(p_World.get(), p_GameManager));
	std::dynamic_pointer_cast<GameResult>(p_Parent.lock())->GetRankUI().lock()->playSE();
}
// 更新     
void ResultEnd::OnUpdate(float deltaTime)
{
	std::dynamic_pointer_cast<GameResult>(p_Parent.lock())->GetPlatform().lock()->ChangeDisplayMode(DisplayMode::Display);
	std::dynamic_pointer_cast<GameResult>(p_Parent.lock())->GetScoreUI().lock()->ChangeDisplayMode(DisplayMode::Display);
	std::dynamic_pointer_cast<GameResult>(p_Parent.lock())->GetScoreUI().lock()->SetNum(p_GameManager->GetScore()->ReleaseScore());
	std::dynamic_pointer_cast<GameResult>(p_Parent.lock())->GetRankUI().lock()->ChangeDisplayMode(DisplayMode::Display);
	std::dynamic_pointer_cast<GameResult>(p_Parent.lock())->GetBlock2().lock()->ChangeDisplayMode(DisplayMode::Display);

	float t = timer_ / maxTimer_;
	GScolor color = m_Color.lerp(GScolor(1.0f, 1.0f, 1.0f, 0.0f), t);
	std::dynamic_pointer_cast<GameResult>(p_Parent.lock())->GetBlock2().lock()->getTexture()->GetParameter()->m_Color = color;

	if (timer_ >= 60 * 5)
	{
		//次のステージがない場合ゲームクリアへ遷移
		if (MapOrder == 11) {
			p_GameManager->set_MapOrder(0);
			p_World->EndRequest(SceneName::GameCredit);
			return;
		}
		MapOrder += 1;
		p_GameManager->set_MapOrder(MapOrder);
		gsStopMusic();
		p_World->EndRequest(SceneName::GamePlay);
	}
	timer_ += deltaTime;
}
//描画
void ResultEnd::OnDraw()const {
}

//終了
void ResultEnd::OnEnd() {
	std::dynamic_pointer_cast<GameResult>(p_Parent.lock())->GetPlatform().lock()->ChangeDisplayMode(DisplayMode::NonDisplay);
	std::dynamic_pointer_cast<GameResult>(p_Parent.lock())->GetScoreUI().lock()->ChangeDisplayMode(DisplayMode::NonDisplay);
	std::dynamic_pointer_cast<GameResult>(p_Parent.lock())->GetRankUI().lock()->ChangeDisplayMode(DisplayMode::NonDisplay);
	std::dynamic_pointer_cast<GameResult>(p_Parent.lock())->GetBlock().lock()->ChangeDisplayMode(DisplayMode::NonDisplay);
}
