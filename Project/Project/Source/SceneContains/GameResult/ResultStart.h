#ifndef RESULT_START_H_
#define RESULT_START_H_

#include"../Scene/Scene.h"

class ResultStart :public Scene
{
public:
	//コンストラクタ
	ResultStart(const IGameManagerPtr& gameManager);

protected:
	// 開始     
	virtual void OnStart();
	// 更新     
	virtual void OnUpdate(float deltaTime);
	//描画
	virtual void OnDraw()const;
	//終了
	virtual void End();
};
#endif // !RESULT_START_H_
