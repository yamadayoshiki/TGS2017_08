#ifndef GAMERESULT_H_
#define GAMERESULT_H_

#include "../Scene/Scene.h"
#include <string>
class World;

//ゲーム中
class GameResult : public Scene
{
public:
	// コンストラクタ    
	GameResult(const IGameManagerPtr& gameManager);

protected:
	// 開始     
	virtual void OnStart();
	// 更新     
	virtual void OnUpdate(float deltaTime);

private:
	std::string m_Text;
};

#endif