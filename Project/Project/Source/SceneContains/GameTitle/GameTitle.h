#ifndef GAMETITLE_H_
#define GAMETITLE_H_

#include "../Scene/Scene.h"

//タイトルシーン
class GameTitle : public Scene
{
public:
	// コンストラクタ    
	GameTitle(const IGameManagerPtr& gameManager);

protected:
	// 開始     
	virtual void OnStart();
	// 更新     
	virtual void OnUpdate(float deltaTime);
	// 描画     
	virtual void OnDraw()const;
};

#endif