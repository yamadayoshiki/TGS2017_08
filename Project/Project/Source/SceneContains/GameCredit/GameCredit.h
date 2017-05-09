#ifndef GAMECREDIT_H_
#define GAMECREDIT_H_

#include "../Scene/Scene.h"

class World;

//ゲーム中
class GameCredit : public Scene
{
public:
	// コンストラクタ    
	GameCredit(const IGameManagerPtr& gameManager);
	// 次のシーンを返す
	virtual SceneName Next() const override;
	// 終了
	virtual void End() override;

protected:
	// 開始     
	virtual void OnStart();
	// 更新     
	virtual void OnUpdate(float deltaTime);
};

#endif