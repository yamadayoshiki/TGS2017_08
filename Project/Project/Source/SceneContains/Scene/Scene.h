#ifndef SCENE_H_
#define SCENE_H_

#include "../IScene.h"
#include "../../Base/GameManagerContains/IGameManagerPtr.h"
#include "../../StagingContains/TransitionStaging/TransitionPtr.h"

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
	// 描画     
	virtual void Draw() const override;
	// 終了しているか？     
	virtual bool IsEnd() const override;

public:
	// 次のシーンを返す     
	virtual SceneName Next() const override = 0;
	// 終了     
	virtual void End() override = 0;
	// 名前を設定
	virtual void SetName(const SceneName & name) override;

protected:
	// 各種固有の開始     
	virtual void OnStart() = 0;
	// 各種固有の更新     
	virtual void OnUpdate(float deltaTime) = 0;

protected:
	bool m_IsEnd;					//終了フラグ
	IGameManagerPtr p_GameManager;	//ゲームマネージャー
	WorldPtr p_World;
	//ワールド
	// シーンの名前
	SceneName m_SceneName;
	// 遷移演出
	TransitionPtr m_Transition;

};

#endif // !SCENE_H_
