#ifndef GAMEOVER_H_
#define GAMEOVER_H_

#include"../Scene/Scene.h"

class World;

class GameOver : public Scene
{
public:
	//コンストラクタ
	GameOver(const IGameManagerPtr& gameManager);

protected:
	// 開始     
	virtual void OnStart();
	// 更新     
	virtual void OnUpdate(float deltaTime);
	// 描画     
	virtual void OnDraw()const;
};

#endif // !GAMEOVER_H_
