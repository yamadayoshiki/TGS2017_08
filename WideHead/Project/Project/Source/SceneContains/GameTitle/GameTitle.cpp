#include "GameTitle.h"
#include <gslib.h>

#include "../SceneName.h"
#include "../../UIContains/UIManager/UIManager.h"
#include "../../ActorContains/ActorGroup.h"
#include"../../WorldContains/World/World.h"
#include "../../Utility/Rederer2D/Renderer2D.h"
#include"../../Utility/Score/Score.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../Define/Def_Nagano.h"
#include"../../Utility/InputState/InputState.h"
#include"../../Utility/Sound/SoundName.h"
#include"../../Utility/Animation/Animation.h"
#include "../../DrawManager/DrawManager.h"
#include "../../Utility/Texture2DParameter/Texture2DParameter.h"
#include "../../TextureContains/AnimationTexture/AnimationTexture.h"
#include "../Elements/DropSprite/DropSprite.h"
#include "../Elements/AnimationFont/AnimationFont.h"
#include "../../UIContains/Button/Button.h"
#include "../SceneManager/SceneChildMgr.h"
#include<GSmusic.h>
#include "Ready\GameTitleReady.h"
#include "Select\GameTitleSelect.h"

// コンストラクタ    
GameTitle::GameTitle(const IGameManagerPtr& gameManager)
	:Scene(gameManager)
	, p_Title(std::weak_ptr<DropSprite>())
	, p_Button(std::weak_ptr<Button>())
	, p_SceneChildMgr(std::unique_ptr<SceneChildMgr>()) {
}

void GameTitle::SetUp() {
	p_SceneChildMgr = std::make_unique<SceneChildMgr>(shared_from_this());
	p_SceneChildMgr->Add(SceneName::Start, std::make_shared<GameTitleReady>());
	p_SceneChildMgr->Add(SceneName::Select, std::make_shared<GameTitleSelect>());
	p_SceneChildMgr->SetUp();
}

// 開始     
void GameTitle::OnStart() {
	//各種パラメーター初期化
	p_GameManager->GetPlayerParameter().setRemaining(3);
	p_GameManager->GetScore()->initialze();
	p_GameManager->set_MapOrder(1);

	//UI生成
	ActorPtr p_UIMgr = std::make_shared<UIManager>(p_World.get(), p_GameManager, m_SceneName);
	p_World->addActor(ActorGroup::UI, p_UIMgr);

	//ポーズ画面ボタンUI
	p_Button = std::dynamic_pointer_cast<Button>(
		p_UIMgr->findChildren([&](const Actor& actor)
	{
		if (actor.getName() == ActorName::UI_Button)
			return true;
		else
			return false;
	}));

	//タイトルロゴ
	std::shared_ptr<DropSprite> dropSprite = std::make_shared<DropSprite>(p_World.get(), p_GameManager);
	p_Title = dropSprite;
	p_World->addActor(ActorGroup::UI, dropSprite);

	//Bボタンを押せ
	p_World->addActor(ActorGroup::UI, (p_PushBMessage[0] = std::make_shared<AnimationFont>(p_World.get(), GSvector2(315, 700), p_GameManager, "StartLogo1", 60)).lock());
	p_World->addActor(ActorGroup::UI, (p_PushBMessage[1] = std::make_shared<AnimationFont>(p_World.get(), GSvector2(365, 700), p_GameManager, "StartLogo2", 62)).lock());
	p_World->addActor(ActorGroup::UI, (p_PushBMessage[2] = std::make_shared<AnimationFont>(p_World.get(), GSvector2(415, 700), p_GameManager, "StartLogo3", 64)).lock());
	p_World->addActor(ActorGroup::UI, (p_PushBMessage[3] = std::make_shared<AnimationFont>(p_World.get(), GSvector2(465, 700), p_GameManager, "StartLogo4", 66)).lock());
	p_World->addActor(ActorGroup::UI, (p_PushBMessage[4] = std::make_shared<AnimationFont>(p_World.get(), GSvector2(515, 700), p_GameManager, "StartLogo5", 68)).lock());
	p_World->addActor(ActorGroup::UI, (p_PushBMessage[5] = std::make_shared<AnimationFont>(p_World.get(), GSvector2(565, 700), p_GameManager, "StartLogo6", 70)).lock());
	p_World->addActor(ActorGroup::UI, (p_PushBMessage[6] = std::make_shared<AnimationFont>(p_World.get(), GSvector2(615, 700), p_GameManager, "StartLogo7", 72)).lock());
	p_World->addActor(ActorGroup::UI, (p_PushBMessage[7] = std::make_shared<AnimationFont>(p_World.get(), GSvector2(665, 700), p_GameManager, "StartLogo8", 74)).lock());
	p_World->addActor(ActorGroup::UI, (p_PushBMessage[8] = std::make_shared<AnimationFont>(p_World.get(), GSvector2(715, 700), p_GameManager, "StartLogo9", 76)).lock());
	p_World->addActor(ActorGroup::UI, (p_PushBMessage[9] = std::make_shared<AnimationFont>(p_World.get(), GSvector2(765, 700), p_GameManager, "StartLogo10", 78)).lock());
	p_World->addActor(ActorGroup::UI, (p_PushBMessage[10] = std::make_shared<AnimationFont>(p_World.get(), GSvector2(815, 700), p_GameManager, "StartLogo11", 80)).lock());
	p_World->addActor(ActorGroup::UI, (p_PushBMessage[11] = std::make_shared<AnimationFont>(p_World.get(), GSvector2(865, 700), p_GameManager, "StartLogo12", 82)).lock());
	p_World->addActor(ActorGroup::UI, (p_PushBMessage[12] = std::make_shared<AnimationFont>(p_World.get(), GSvector2(915, 700), p_GameManager, "StartLogo13", 84)).lock());

	//子のセットアップ
	p_SceneChildMgr->SetUpChild();
	p_SceneChildMgr->Change(SceneName::Start);

	//各種パラメーター初期化
	p_GameManager->GetScore()->ScoreRest();
	p_Button.lock()->ChangeDisplayMode(DisplayMode::NonDisplay);

	//BGM
	gsBindMusic(BGM_GAME_TITLE);
	gsPlayMusic();
}

// 更新
void GameTitle::OnUpdate(float deltaTime) {
	//子シーンの更新
	p_SceneChildMgr->Update(deltaTime);
}

void GameTitle::OnEnd() {
	//子シーンの終了
	p_SceneChildMgr->End();
	p_SceneChildMgr->ReleaseWorld();

	gsStopMusic();
}

std::weak_ptr<DropSprite> GameTitle::GetTitle()
{
	return p_Title;
}

std::weak_ptr<AnimationFont> GameTitle::GetPushBMessage(const int index)
{
	return p_PushBMessage[index];
}

std::weak_ptr<Button> GameTitle::GetButtonUI()
{
	return p_Button;
}
