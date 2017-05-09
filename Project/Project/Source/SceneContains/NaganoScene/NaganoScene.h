#ifndef NAGANO_SCENE_H_
#define NAGANO_SCENE_H_

#include "../Scene/Scene.h"
#include <memory>

class World;

//ゲーム中
class NaganoScene : public Scene
{
public:
	// コンストラクタ    
	NaganoScene(const IGameManagerPtr& gameManager);
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