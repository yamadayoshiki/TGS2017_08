#ifndef CREDIT_END_H_
#define CREDIT_END_H_

#include"../../../WorldContains/IWorldPtr.h"
#include"../../../Base/GameManagerContains/IGameManagerPtr.h"
#include"../../IScene.h"
#include"../../../Utility/Texture2DParameter/Texture2DParameterPtr.h"
#include"../../../StagingContains/TransitionStaging/TransitionPtr.h"
#include <GStype.h>

class CreditEnd :public IScene
{
public:
public:
	//コンストラクタ
	CreditEnd(IWorld* world, const IGameManagerPtr& gameManager);

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
	//最大時間
	float maxTimer_{ 60.0f };
	//終了フラグ
	bool is_End{ false };
	//遷移演出
	TransitionPtr p_Transition;
	//
	Texture2DParameterSPtr p_Param;
	//
	GScolor m_Color{ 1.0f,1.0f,1.0f,1.0f };
	//
	int MapOrder;

	int m_Score{ 0 };

};
#endif // !CREDIT_END_H_
