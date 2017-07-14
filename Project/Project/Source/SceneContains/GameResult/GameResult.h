#ifndef GAMERESULT_H_
#define GAMERESULT_H_

#include "../Scene/Scene.h"
#include"../SceneManager/SceneManager.h"

#include <string>

#include<gslib.h>
class World;

//ゲーム中
class GameResult : public Scene
{
public:
	// コンストラクタ    
	GameResult(const IGameManagerPtr& gameManager);

	enum class Rank{
		RankS,
		RankA,
		RankB,
		RankC,
	};
protected:
	// 開始     
	virtual void OnStart();
	// 更新     
	virtual void OnUpdate(float deltaTime);
	//描画
	virtual void OnDraw()const;
	//終了
	virtual void OnEnd();

private:
	SceneManager*	m_SceneManager;

	float timer_{ 0.0f };
	
};

#endif