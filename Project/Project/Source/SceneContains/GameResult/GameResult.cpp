#include "GameResult.h"

#include <gslib.h>
#include<GSmusic.h>

#include "../SceneName.h"
#include "../../WorldContains/World/World.h"
#include"../../ActorContains/ActorGroup.h"
#include"../../Utility/Rederer2D/Renderer2D.h"
#include"../../CharacterContains/PlayerContains/Player/Player.h"
#include "../../Utility/InputState/InputState.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../Define/Def_Nagano.h"
#include"../../Utility/Sound/SoundName.h"
#include"../../Utility/Score/Score.h"
#include"../../UIContains/UIManager/UIManager.h"
#include"../../Utility/EnumRap/EnumRap.h"

#include"ResultStart\ResultStart.h"
#include"ResultStaging\ResultStaging.h"
#include"ResultEnd\ResultEnd.h"



// コンストラクタ    
GameResult::GameResult(const IGameManagerPtr& gameManager)
	: Scene(gameManager)
	, m_SceneManager(new SceneManager()){
}

GameResult::~GameResult(){
	delete m_SceneManager;
}

// 開始     
void GameResult::OnStart() {
	p_World->addActor(ActorGroup::UI, std::make_shared<UIManager>(p_World.get(), p_GameManager, m_SceneName));

	MapOrder = p_GameManager->get_MapOrder();

	m_SceneManager->Initialize();
	//シーンの追加
	//m_SceneManager->Add(SceneName::ResultStart, std::make_shared<ResultStart>(p_World.get(), p_GameManager));
	//m_SceneManager->Add(SceneName::ResultStaging, std::make_shared<ResultStaging>(p_World.get(), p_GameManager));
	m_SceneManager->Add(SceneName::ResultEnd, std::make_shared<ResultEnd>(p_World.get(), p_GameManager));

	m_SceneManager->Change(SceneName::ResultEnd);

	//BGMの設定
	gsBindMusic(BGM_GAME_CLER);
	//BGM再生
	gsPlayMusic();
}

// 更新     
void GameResult::OnUpdate(float deltaTime) {

	m_SceneManager->Update(deltaTime);

	timer_ += deltaTime;
}

void GameResult::OnDraw() const
{
	m_SceneManager->Draw();
}

void GameResult::OnEnd() {
	m_SceneManager->Initialize();
}
