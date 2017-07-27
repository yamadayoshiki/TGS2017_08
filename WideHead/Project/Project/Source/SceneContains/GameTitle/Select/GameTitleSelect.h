#ifndef GAMETITLESELECT_H_
#define GAMETITLESELECT_H_
#include "../../Scene/ChildScene.h"
class GameTitleSelect : public ChildScene
{
public:
	GameTitleSelect();

protected:
	// 開始     
	virtual void OnStart() override;
	// 更新     
	virtual void OnUpdate(float deltaTime) override;
	//終了
	virtual void OnEnd()override;
};
#endif // !GAMETITLESELECT_H_
