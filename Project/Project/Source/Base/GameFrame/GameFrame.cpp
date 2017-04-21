#include <GL/GLAux.h>
#include <GL\GL.h>
#include <GL/GLU.h>
#include <gslib.h>

#include"GameFrame.h"
#include"../GameManagerContains/GameManager/GameManager.h"
#include"../../SceneContains/SceneName.h"
#include"../../SceneContains/GameTitle/GameTitle.h"
#include"../../SceneContains/GamePlay/GamePlay.h"
#include"../../SceneContains/NaganoScene/NaganoScene.h"
#include"../../SceneContains/NakayamaScene/NakayamaScene.h"
#include "../../Define/Def_Nagano.h"
#include"../../Utility/Rederer2D/Renderer2D.h"
#include"../../Utility/InputState/InputState.h"

//コンストラクタ
GameFrame::GameFrame()
	:Game(SCREEN_SIZE.x, SCREEN_SIZE.y)
	,m_SceneManager()
{
	p_GameManager = std::make_shared<GameManager>(new Renderer2D(),new InputState());
	p_GameManager->LoadContent();
}

//デストラクタ
GameFrame::~GameFrame()
{
	p_GameManager->UnLoadContent();
}

//初期化
void GameFrame::start()
{
	m_SceneManager.Add(SceneName::GameTitle, std::make_shared<GameTitle>());
	m_SceneManager.Add(SceneName::GamePlay, std::make_shared<GamePlay>(p_GameManager.get()));
	m_SceneManager.Add(SceneName::NaganoScene, std::make_shared<NaganoScene>());
	m_SceneManager.Add(SceneName::NakayamaScene, std::make_shared<NakayamaScene>());
	m_SceneManager.Change(SceneName::GamePlay);
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