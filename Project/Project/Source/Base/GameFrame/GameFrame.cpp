#include <gslib.h>

#include"GameFrame.h"

#include"../GameManagerContains/GameManager/GameManager.h"
#include"../../Utility/Rederer2D/Renderer2D.h"
#include"../../Utility/InputState/InputState.h"
#include"../../Utility/EnumRap/EnumRap.h"

#include"../../SceneContains/SceneName.h"
#include"../../SceneContains/GameTitle/GameTitle.h"
#include"../../SceneContains/GameSelect/GameSelect.h"
#include"../../SceneContains/GamePlay/GamePlay.h"
#include"../../SceneContains/GameResult/GameResult.h"
#include"../../SceneContains/GameCredit/GameCredit.h"
#include"../../SceneContains/GameEnd/GameEnd.h"

#include"../../SceneContains/NaganoScene/NaganoScene.h"
#include"../../SceneContains/NakayamaScene/NakayamaScene.h"
#include"../../SceneContains/yamadaScene/yamadaScene.h"

#include "../../Define/Def_Nagano.h"
#include"../../WorldContains/World/World.h"

//コンストラクタ
GameFrame::GameFrame() : Game(SCREEN_SIZE.x, SCREEN_SIZE.y)
	, m_SceneManager() {
	//ゲームマネージャー生成
	p_GameManager = std::make_shared<GameManager>(
		std::make_shared<Renderer2D>(),
		std::make_shared<InputState>());

	//コンテンツの読み込み
	p_GameManager->LoadContent();
}

//デストラクタ
GameFrame::~GameFrame() {
	// コンテンツの削除
	p_GameManager->UnLoadContent();
}

//初期化
void GameFrame::start(){
	// シーンのstring対応の登録
	p_GameManager->GetSceneEnum()->AddEnum("GameTitle", SceneName::GameTitle);
	p_GameManager->GetSceneEnum()->AddEnum("GameSelect", SceneName::GameSelect);
	p_GameManager->GetSceneEnum()->AddEnum("GamePlay", SceneName::GamePlay);
	p_GameManager->GetSceneEnum()->AddEnum("GameResult", SceneName::GameResult);
	p_GameManager->GetSceneEnum()->AddEnum("GameCredit", SceneName::GameCredit);
	p_GameManager->GetSceneEnum()->AddEnum("GameEnd", SceneName::GameEnd);

	//シーンの追加
	m_SceneManager.Add(SceneName::GameTitle, std::make_shared<GameTitle>(p_GameManager));
	m_SceneManager.Add(SceneName::GameSelect, std::make_shared<GameSelect>(p_GameManager));
	m_SceneManager.Add(SceneName::GamePlay, std::make_shared<GamePlay>(p_GameManager));
	m_SceneManager.Add(SceneName::GameResult, std::make_shared<GameResult>(p_GameManager));
	m_SceneManager.Add(SceneName::GameCredit, std::make_shared<GameCredit>(p_GameManager));
	m_SceneManager.Add(SceneName::GameEnd, std::make_shared<GameEnd>(p_GameManager));

	//初期シーンの設定
	m_SceneManager.Change(SceneName::GameTitle);
}

// 更新
void GameFrame::update(float time)
{
	p_GameManager->Update();
	if (p_GameManager->GetInputState()->IsKeyState(VK_SPACE)) return;
	m_SceneManager.Update(time);
}

// 描画
void GameFrame::draw()
{
	m_SceneManager.Draw();
}

// 終了
void GameFrame::end(){
	m_SceneManager.End();
}

// 実行中か
bool GameFrame::isRunning(){
	// Endシーンでない場合は実行中
	return m_SceneManager.GetSceneName() != SceneName::GameEnd && GetAsyncKeyState(VK_ESCAPE) == 0;
}