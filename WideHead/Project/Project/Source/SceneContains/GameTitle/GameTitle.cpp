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
	, p_SceneChildMgr(std::unique_ptr<SceneChildMgr>())
	,m_Number(0)
{
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
	calcTest();
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

void GameTitle::calcTest()
{
#define NUMBER 60
#define PLUS 5

	if (m_Number == NUMBER + PLUS * 0)
	{
		p_World->addActor(ActorGroup::UI, (p_PushBMessage[0] = std::make_shared<AnimationFont>(p_World.get(), GSvector2(315, 700), p_GameManager, "StartLogo1", 60)).lock());
	}
	if (m_Number == NUMBER + PLUS * 1)
	{
		p_World->addActor(ActorGroup::UI, (p_PushBMessage[1] = std::make_shared<AnimationFont>(p_World.get(), GSvector2(365, 700), p_GameManager, "StartLogo2", 60)).lock());
	}
	if (m_Number == NUMBER + PLUS * 2)
	{
		p_World->addActor(ActorGroup::UI, (p_PushBMessage[2] = std::make_shared<AnimationFont>(p_World.get(), GSvector2(415, 700), p_GameManager, "StartLogo3", 60)).lock());
	}
	if (m_Number == NUMBER + PLUS * 3)
	{
		p_World->addActor(ActorGroup::UI, (p_PushBMessage[3] = std::make_shared<AnimationFont>(p_World.get(), GSvector2(465, 700), p_GameManager, "StartLogo4", 60)).lock());
	}
	if (m_Number == NUMBER + PLUS * 4)
	{
		p_World->addActor(ActorGroup::UI, (p_PushBMessage[4] = std::make_shared<AnimationFont>(p_World.get(), GSvector2(515, 700), p_GameManager, "StartLogo5", 60)).lock());
	}
	if (m_Number == NUMBER + PLUS * 5)
	{
		p_World->addActor(ActorGroup::UI, (p_PushBMessage[5] = std::make_shared<AnimationFont>(p_World.get(), GSvector2(565, 700), p_GameManager, "StartLogo6", 60)).lock());
	}
	if (m_Number == NUMBER + PLUS * 6)
	{
		p_World->addActor(ActorGroup::UI, (p_PushBMessage[6] = std::make_shared<AnimationFont>(p_World.get(), GSvector2(615, 700), p_GameManager, "StartLogo7", 60)).lock());
	}
	if (m_Number == NUMBER + PLUS * 7)
	{
		p_World->addActor(ActorGroup::UI, (p_PushBMessage[7] = std::make_shared<AnimationFont>(p_World.get(), GSvector2(665, 700), p_GameManager, "StartLogo8", 60)).lock());
	}
	if (m_Number == NUMBER + PLUS * 8)
	{
		p_World->addActor(ActorGroup::UI, (p_PushBMessage[8] = std::make_shared<AnimationFont>(p_World.get(), GSvector2(715, 700), p_GameManager, "StartLogo9", 60)).lock());
	}
	if (m_Number == NUMBER + PLUS * 9)
	{
		p_World->addActor(ActorGroup::UI, (p_PushBMessage[9] = std::make_shared<AnimationFont>(p_World.get(), GSvector2(765, 700), p_GameManager, "StartLogo10", 60)).lock());
	}
	if (m_Number == NUMBER + PLUS * 10)
	{
		p_World->addActor(ActorGroup::UI, (p_PushBMessage[10] = std::make_shared<AnimationFont>(p_World.get(), GSvector2(815, 700), p_GameManager, "StartLogo11", 60)).lock());
	}
	if (m_Number == NUMBER + PLUS * 11)
	{
		p_World->addActor(ActorGroup::UI, (p_PushBMessage[11] = std::make_shared<AnimationFont>(p_World.get(), GSvector2(865, 700), p_GameManager, "StartLogo12", 60)).lock());
	}
	if (m_Number == NUMBER + PLUS * 12)
	{
		p_World->addActor(ActorGroup::UI, (p_PushBMessage[12] = std::make_shared<AnimationFont>(p_World.get(), GSvector2(915, 700), p_GameManager, "StartLogo13", 60)).lock());
	}

	if (m_Number <= 121) { m_Number += 1; }
}