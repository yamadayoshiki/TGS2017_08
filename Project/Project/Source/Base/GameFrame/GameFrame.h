#ifndef GAMEFRAME_H_
#define GAMEFRAME_H_

#include<GSgame.h>
#include<memory>

#include "../../SceneContains/SceneManager/SceneManager.h"

class GameManager;

class GameFrame :public gslib::Game
{
public:
	GameFrame();
	~GameFrame();

private:

	// 開始
	void start() override;
	// 更新
	void update(float time) override;
	// 描画
	void draw() override;
	// 終了
	void end() override;
	// 実行中か
	virtual bool isRunning() override;

private:
	using GameManagerPtr = std::shared_ptr<GameManager>;
	GameManagerPtr p_GameManager;					//ゲームマネージャー
	std::shared_ptr<SceneManager> m_SceneManager;	//シーンマネージャー
};


#endif // !GAMEFRAME_H_