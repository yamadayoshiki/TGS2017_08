#ifndef GAMEPLAYPAUSE_H_
#define GAMEPLAYPAUSE_H_
#include "../../Scene/ChildScene.h"
//ゲーム画面ポーズ
class GamePlayPause : public ChildScene
{
public:
	GamePlayPause();

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
#endif // !GAMEPLAYPAUSE_H_
