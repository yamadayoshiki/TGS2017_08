#ifndef SCENE_H_
#define SCENE_H_

#include "../IScene.h"
#include "../../Base/GameManagerContains/IGameManager.h"

//シーンインターフェイス
class Scene :public IScene
{
public:
	//コンストラクタ
	Scene(IGameManager* gameManager);
	//デフォルトコンストラクタ
	Scene();
	// 仮想デストラクタ     
	virtual ~Scene() {}
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
	IGameManager* p_GameManager;	//ゲームマネージャー
};

#endif // !SCENE_H_
