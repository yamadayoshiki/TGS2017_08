#ifndef GAMETITLEREADY_H_
#define GAMETITLEREADY_H_
#include "../../Scene/ChildScene.h"

class GameTitleReady : public ChildScene
{
public:
	GameTitleReady();

protected:
	// 開始     
	virtual void OnStart() override;
	// 更新     
	virtual void OnUpdate(float deltaTime) override;
	//終了
	virtual void OnEnd()override;
};
#endif // !GAMETITLEREADY_H_
