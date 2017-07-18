#ifndef CREDIT_START_H_
#define CREDIT_STSRT_H_

#include"../../../WorldContains/IWorldPtr.h"
#include"../../../Base/GameManagerContains/IGameManagerPtr.h"
#include"../../IScene.h"
#include"../../../TextureContains/ITexturePtr.h"

class CreditStart :public IScene
{
public:
	//コンストラクタ
	CreditStart(IWorld* world, const IGameManagerPtr& gameManager);

protected:
	// セットアップ
	virtual void SetUp() override {}
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
	// 子の設定
	void SetUpChild(ChildScene& child)override {}

private:
	//ワールド
	IWorldPtr p_World;
	//ゲームマネージャー
	IGameManagerPtr p_GameManager;
	//テクスチャ
	ITexturePtr p_Texture;
	//タイマー
	float timer_{ 0.0f };
	//終了フラグ
	bool is_End{ false };
};
#endif // !CREDIT_START_H_
