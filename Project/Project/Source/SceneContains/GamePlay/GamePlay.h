#ifndef GAMEPLAY_H_
#define GAMEPLAY_H_

#include "../Scene/Scene.h"

class World;

//ゲーム中
class GamePlay : public Scene
{
public:
	// コンストラクタ    
	GamePlay(const IGameManagerPtr& gameManager, const WorldPtr& world);
	// 次のシーンを返す
	virtual SceneName Next() const override;
	// 終了
	virtual void End() override;

protected:
	// 開始     
	virtual void OnStart();
	// 更新     
	virtual void OnUpdate(float deltaTime);

private:
	using WorldPtr = std::shared_ptr<World>;
	WorldPtr p_World;	//ワールド
};

#endif