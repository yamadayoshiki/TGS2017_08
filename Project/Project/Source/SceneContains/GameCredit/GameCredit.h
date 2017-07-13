#ifndef GAMECREDIT_H_
#define GAMECREDIT_H_

#include "../Scene/Scene.h"
#include"../SceneManager/SceneManager.h"

class World;

//ゲーム中
class GameCredit : public Scene
{
public:
	// コンストラクタ    
	GameCredit(const IGameManagerPtr& gameManager);

protected:
	// 開始     
	virtual void OnStart();
	// 更新     
	virtual void OnUpdate(float deltaTime);
	//描画
	virtual void OnDraw()const;
	//終了
	virtual void End();

private:
	SceneManager*	m_SceneManager;
};

#endif