#ifndef GAMEPLAYREADY_H_
#define GAMEPLAYREADY_H_
#include "../../Scene/ChildScene.h"
//ゲームプレイ準備
class GamePlayReady : public ChildScene
{
public:
	GamePlayReady();
	~GamePlayReady();

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
#endif // !GAMEPLAYREADY_H_