#ifndef GAMEPLAYPLAY_H_
#define GAMEPLAYPLAY_H_
#include "../../Scene/ChildScene.h"
class GamePlayPlay : public ChildScene
{
public:
	GamePlayPlay();

protected:
	// 開始     
	virtual void OnStart() override;
	// 更新     
	virtual void OnUpdate(float deltaTime) override;
	// 描画     
	virtual void OnDraw()const override;
	//終了
	virtual void OnEnd()override;
};
#endif // !GAMEPLAYPLAY_H_
