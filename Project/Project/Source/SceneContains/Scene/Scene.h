#ifndef SCENE_H_
#define SCENE_H_

#include "../IScene.h"
#include "../../Base/GameManagerContains/IGameManagerPtr.h"
#include "../../StagingContains/TransitionStaging/TransitionPtr.h"

class World;

using WorldPtr = std::shared_ptr<World>;

//シーンインターフェイス
class Scene :public IScene, public std::enable_shared_from_this<Scene>
{
public:
	enum class CarsorMovement
	{
		Up = 0,		//上
		Down,		//下
		Right,		//右
		Left,		//左
	};
public:
	//デフォルトコンストラクタ
	Scene();
	//コンストラクタ
	explicit Scene(const IGameManagerPtr& gameManager);
	// 仮想デストラクタ     
	virtual ~Scene();

public:
	// 開始     
	void Start() override;
	// 更新     
	void Update(float deltaTime) override;
	// 描画     
	void Draw() const override;
	// 終了     
	void End() override;
	// 終了しているか？     
	bool IsEnd() const override;
	// 次のシーンを返す     
	SceneName Next() const override;
	// 名前を設定
	void SetName(const SceneName & name) override;
	// 名前の取得
	SceneName GetName() override;
	// 子の設定
	void SetUpChild(ChildScene& child) override;

protected:
	// 各種固有の開始     
	virtual void OnStart() {}
	// 各種固有の更新     
	virtual void OnUpdate(float deltaTime) {}
	// 各種固有の描画     
	virtual void OnDraw()const {}
	// 各種固有の終了     
	virtual void OnEnd() {}

protected:
	bool m_IsEnd;					//終了フラグ
	IGameManagerPtr p_GameManager;	//ゲームマネージャー
	WorldPtr p_World;				//ワールド
	SceneName m_SceneName;			//シーンの名前
	TransitionPtr m_Transition;		//遷移演出
	bool PauseFlag = false;			//ポーズフラグ
	CarsorMovement					//カーソル移動
		m_CarsorMovement{
		CarsorMovement::Up };
	int MapOrder = 0;				//マップの順番
	bool isGameClear;				//ゲームをクリアしたか
};

#endif // !SCENE_H_
