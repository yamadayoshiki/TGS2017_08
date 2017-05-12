#ifndef GAMESELECT_H_
#define GAMESELECT_H_

#include "../Scene/Scene.h"

class World;

//ゲーム中
class GameSelect : public Scene
{
public:
	// コンストラクタ    
	GameSelect(const IGameManagerPtr& gameManager);

protected:
	// 開始     
	virtual void OnStart();
	// 更新     
	virtual void OnUpdate(float deltaTime);
};

#endif