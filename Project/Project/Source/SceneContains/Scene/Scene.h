#ifndef SCENE_H_
#define SCENE_H_

#include "../IScene.h"
#include "../../Base/GameManagerContains/IGameManagerPtr.h"

class World;

using WorldPtr = std::shared_ptr<World>;

//シーンインターフェイス
class Scene :public IScene
{
public:
	//コンストラクタ
	Scene(const IGameManagerPtr& gameManager,const WorldPtr& world);
	// 仮想デストラクタ     
	virtual ~Scene();
	// 開始     
	virtual void Start() override;
	// 更新     
	virtual void Update(float deltaTime) override;
	// 終了しているか？     
	virtual bool IsEnd() const override;

public:
	// 描画     
	virtual void Draw() const override = 0;
	// 次のシーンを返す     
	virtual SceneName Next() const override = 0;
	// 終了     
	virtual void End() override = 0;

protected:
	// 開始     
	virtual void OnStart() = 0;
	// 更新     
	virtual void OnUpdate(float deltaTime) = 0;

protected:
	bool m_IsEnd;					//終了フラグ
	IGameManagerPtr p_GameManager;	//ゲームマネージャー
	
	WorldPtr p_World;
};

#endif // !SCENE_H_
