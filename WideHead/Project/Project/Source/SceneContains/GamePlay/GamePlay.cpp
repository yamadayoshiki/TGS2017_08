#include "GamePlay.h"

#include <gslib.h>
#include<GSmusic.h>

#include "../SceneName.h"
#include "../../WorldContains/World/World.h"
#include"../../ActorContains/ActorGroup.h"
#include"../../CharacterContains/PlayerContains/Player/Player.h"
#include "../../Utility/InputState/InputState.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../Define/Def_Nagano.h"
#include "../../Define/Def_Nakayama.h"
#include "../../Utility/Rederer2D/Renderer2D.h"
#include"../../MapGenerator/MapGenerator.h"
#include "../../Utility/FourDirection/FourDirection.h"
#include"../../CharacterContains/Factory/CharacterFactory.h"
#include"../../Utility/Sound/SoundName.h"
#include "../../StagingContains/TransitionStaging/Transition/Transition.h"
#include"../../UIContains/UIManager/UIManager.h"
#include "../../UIContains/Number/Number.h"
#include "../../UIContains/Sprite/Sprite.h"
#include "../../UIContains/Button/Button.h"
#include "../SceneManager/SceneChildMgr.h"
#include "../../Utility/Score/Score.h"
#include "Ready\GamePlayReady.h"
#include "Play\GamePlayPlay.h"
#include "Pause\GamePlayPause.h"
#include "../../WorldContains/EventMessage/EventMessage.h"
#include "Close\GamePlayClose.h"

// コンストラクタ    
GamePlay::GamePlay(const IGameManagerPtr& gameManager)
	: Scene(gameManager) {
}

void GamePlay::SetUp() {
	p_SceneChildMgr = std::make_unique<SceneChildMgr>(shared_from_this());
	p_SceneChildMgr->Add(SceneName::Start, std::make_shared<GamePlayReady>());
	p_SceneChildMgr->Add(SceneName::Play, std::make_shared<GamePlayPlay>());
	p_SceneChildMgr->Add(SceneName::Pause, std::make_shared<GamePlayPause>());
	p_SceneChildMgr->Add(SceneName::Close, std::make_shared<GamePlayClose>());
	p_SceneChildMgr->SetUp();
}

// 開始     
void GamePlay::OnStart() {
	//Mapデータの設定
	MapSetDeta();

	// UIの生成
	ActorPtr p_UIMgr = std::make_shared<UIManager>(p_World.get(), p_GameManager, m_SceneName);
	p_World->addActor(ActorGroup::UI, p_UIMgr);

	//スコアUIの取得
	p_ScoreUI = std::dynamic_pointer_cast<Number>(
		p_UIMgr->findChildren([&](const Actor& actor)
	{
		if (actor.getName() == ActorName::UI_Number)
		{
			if (dynamic_cast<Number*>(const_cast<Actor*>(&actor))->GetUsage() == "Score")
				return true;
		}
		return false;
	}));
	//プレイヤー残機UIの取得
	p_PlayerRemainingUI = std::dynamic_pointer_cast<Number>(
		p_UIMgr->findChildren([&](const Actor& actor)
	{
		if (actor.getName() == ActorName::UI_Number)
		{
			if (dynamic_cast<Number*>(const_cast<Actor*>(&actor))->GetUsage() == "PlayerRemaining")
				return true;
		}
		return false;
	}));
	//ポーズ画面ボタンUI
	p_ButtonUI = std::dynamic_pointer_cast<Button>(
		p_UIMgr->findChildren([&](const Actor& actor)
	{
		if (actor.getName() == ActorName::UI_Button)
			return true;
		else
			return false;
	}));
	//ポーズ画面背景
	p_PauseBack = std::dynamic_pointer_cast<Sprite>(
		p_UIMgr->findChildren([&](const Actor& actor)
	{
		if (actor.getName() == ActorName::UI_Sprite)
		{
			if (dynamic_cast<Sprite*>(const_cast<Actor*>(&actor))->GetUsage() == "PauseBackGround")
				return true;
		}
		return false;
	}));

	//子のセットアップ
	p_SceneChildMgr->SetUpChild();
	p_SceneChildMgr->Change(SceneName::Start);

	//各種パラメーター初期化
	p_GameManager->GetScore()->ScoreRest();
	p_ButtonUI.lock()->ChangeDisplayMode(DisplayMode::NonDisplay);
	p_PauseBack.lock()->ChangeDisplayMode(DisplayMode::NonDisplay);

	//BGM再生
	gsBindMusic(BGM_GAME_PLAY);
	gsPlayMusic();
}

// 更新     
void GamePlay::OnUpdate(float deltaTime) {
	//子シーンの更新
	p_SceneChildMgr->Update(deltaTime);
}

void GamePlay::OnDraw() const {
}

void GamePlay::OnEnd() {
	//子シーンの終了
	p_SceneChildMgr->End();
	p_SceneChildMgr->ReleaseWorld();

	//BGM停止
	gsStopMusic();

	//マップ番号設定
	if (MapOrder >= 1)
		p_GameManager->set_MapOrder(MapOrder);

	else
		MapOrder = 0;
}

void GamePlay::HandleMessage(EventMessage message, void * param) {
	switch (message)
	{
	case EventMessage::END_SCENE:
		if (IsExistBrother((const SceneName&)param) == true)
			p_World->EndRequest((const SceneName&)param);
		return;
	}

	p_SceneChildMgr->HandleMessage(message, param);
}

std::weak_ptr<Number> GamePlay::GetScoreUI() {
	return p_ScoreUI;
}

std::weak_ptr<Number> GamePlay::GetPlayerRemainingUI() {
	return p_PlayerRemainingUI;
}

std::weak_ptr<Button> GamePlay::GetButtonUI() {
	return p_ButtonUI;
}

std::weak_ptr<Sprite> GamePlay::GetPauseBack() {
	return p_PauseBack;
}

//Mapデータの設定
void GamePlay::MapSetDeta() {
	//マップデータによる生成
	p_World->SetMapGenerator(p_World, p_GameManager);
	p_World->SetCharacterFactory(new CharacterFactory(p_World, p_GameManager));
	MapOrder = p_GameManager->get_MapOrder();
	p_World->generate(p_World, p_GameManager, "Resource/StreamingAssets/stage" + std::to_string(MapOrder) + ".csv");
}