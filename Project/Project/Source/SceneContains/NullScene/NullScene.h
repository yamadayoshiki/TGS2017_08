#ifndef NULLSCENE_H_ 
#define NULLSCENE_H_ 

#include "../IScene.h"

// 空のシーン 
class NullScene : public IScene
{
public:
	// デフォルトコンストラクタ
	NullScene() {}
	// 開始     
	void Start() override {}
	// 更新     
	void Update(float deltaTime)override {}
	// 描画     
	void Draw() const override {}
	// 終了しているか？     
	bool IsEnd() const override { return false; }
	// 次のシーンを返す     
	SceneName Next() const override { return SceneName::None; }
	// 終了     
	void End()override {}
	// 名前の設定
	void SetName(const SceneName& name) override {}
	// 名前の取得
	SceneName GetName() override { return SceneName::None; }
	// 子の設定
	void SetUpChild(ChildScene& child)override {}
};

#endif