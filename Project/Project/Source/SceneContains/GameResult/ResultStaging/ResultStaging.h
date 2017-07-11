#ifndef RESULT_STAGING_H_
#define RESULT_STAGING_H_

#include"../../../WorldContains/IWorldPtr.h"
#include"../../../Base/GameManagerContains/IGameManagerPtr.h"
#include"../../IScene.h"
#include "../../../StagingContains/TransitionStaging/TransitionPtr.h"


class ResultStaging :public IScene
{
public:
	//コンストラクタ
	ResultStaging(IWorld* world, const IGameManagerPtr& gameManager);

protected:
	// 開始     
	virtual void Start();
	// 更新     
	virtual void Update(float deltaTime);
	//描画
	virtual void Draw()const;
	//終了
	virtual void End();
	// 終了しているか？     
	virtual bool IsEnd() const override;
	// 次のシーンを返す     
	virtual SceneName Next() const override;
	// 名前の設定
	virtual void SetName(const SceneName& name)override;
	// 名前の取得
	virtual SceneName GetName() override;

private:
	//ワールド
	IWorldPtr p_World;
	//ゲームマネージャー
	IGameManagerPtr p_GameManager;
	//タイマー
	float timer_{ 0.0f };
	//終了フラグ
	bool is_End{ false };
	TransitionPtr m_Transition;
};
#endif // !RESULT_STAGING_H_
