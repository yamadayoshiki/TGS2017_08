#ifndef YAMADA_SCENE_H_
#define YAMADA_SCENE_H_

#include "../Scene/Scene.h"

class World;

class yamadaScene:public Scene
{
public:
	// コンストラクタ    
	yamadaScene(const IGameManagerPtr& gameManager);
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
#endif // !YAMADA_SCENE_H_
