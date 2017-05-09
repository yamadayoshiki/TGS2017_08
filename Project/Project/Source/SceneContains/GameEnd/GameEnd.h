#ifndef GAMEEND_H_
#define GAMEEND_H_

#include "../Scene/Scene.h"

class World;

//ゲーム中
class GameEnd : public Scene
{
public:
	// コンストラクタ    
	GameEnd(const IGameManagerPtr& gameManager);
protected:
	// 開始     
	virtual void OnStart();
	// 更新     
	virtual void OnUpdate(float deltaTime);
};

#endif