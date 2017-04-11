#include <GL/GLAux.h>
#include <GL\GL.h>
#include <GL/GLU.h>
#include <gslib.h>

#include"GameFrame.h"

#include "../../WorldContains/World/World.h"
#include "../GameManager/GameManager.h"

//コンストラクタ
GameFrame::GameFrame()
	:Game(1024, 768)
	, p_GameManager(new GameManager())
{
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
	p_World = std::make_shared<World>();
}

// 更新
void GameFrame::update(float time)
{
	p_World->update(time);
}

// 描画
void GameFrame::draw()
{
	p_World->Draw();
}

// 終了
void GameFrame::end()
{
}

// 実行中か
bool GameFrame::isRunning()
{
	return GetAsyncKeyState(VK_ESCAPE) == 0;
}