#ifndef GAMETUTORIALPAUSE_H_
#define GAMETUTORIALPAUSE_H_
#include "../../Scene/ChildScene.h"
//ゲーム画面ポーズ
class GameTutorialPause : public ChildScene
{
public:
	GameTutorialPause();

protected:
	// 開始     
	virtual void OnStart() override;
	// 更新     
	virtual void OnUpdate(float deltaTime) override;
	//終了
	virtual void OnEnd()override;
};
#endif // !GAMETUTORIALPAUSE_H_
