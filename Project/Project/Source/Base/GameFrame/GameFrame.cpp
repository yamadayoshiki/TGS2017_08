#include <GL/GLAux.h>
#include <GL\GL.h>
#include <GL/GLU.h>
#include <gslib.h>

#include"GameFrame.h"

#include"../GameManagerContains/GameManager/GameManager.h"
#include"../../Utility/Rederer2D/Renderer2D.h"
#include"../../Utility/InputState/InputState.h"

#include"../../SceneContains/SceneName.h"
#include"../../SceneContains/GameTitle/GameTitle.h"
#include"../../SceneContains/GamePlay/GamePlay.h"
#include"../../SceneContains/NaganoScene/NaganoScene.h"
#include"../../SceneContains/NakayamaScene/NakayamaScene.h"
#include"../../SceneContains/yamadaScene/yamadaScene.h"
#include "../../Define/Def_Nagano.h"
#include"../../WorldContains/World/World.h"


//コンストラクタ
GameFrame::GameFrame()
	:Game(SCREEN_SIZE.x, SCREEN_SIZE.y)
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
void GameFrame::start()
{
	//ワールド生成
	using WorldPtr = std::shared_ptr<World>;
	WorldPtr p_World;
	p_World = std::make_shared<World>();
	//シーンの追加
	m_SceneManager.Add(SceneName::GameTitle, std::make_shared<GameTitle>(p_GameManager, p_World));
	m_SceneManager.Add(SceneName::GamePlay, std::make_shared<GamePlay>(p_GameManager, p_World));
	m_SceneManager.Add(SceneName::NaganoScene, std::make_shared<NaganoScene>(p_GameManager, p_World));
	m_SceneManager.Add(SceneName::NakayamaScene, std::make_shared<NakayamaScene>(p_GameManager, p_World));
	m_SceneManager.Add(SceneName::YamadaScene, std::make_shared<yamadaScene>(p_GameManager, p_World));

	//初期シーンの設定
	m_SceneManager.Change(SceneName::YamadaScene);
}

// 更新
void GameFrame::update(float time)
{
	p_GameManager->Update();
	m_SceneManager.Update(time);
}

// 描画
void GameFrame::draw()
{
	m_SceneManager.Draw();
}

// 終了
void GameFrame::end()
{
	m_SceneManager.End();
}

// 実行中か
bool GameFrame::isRunning()
{
	return GetAsyncKeyState(VK_ESCAPE) == 0;
}