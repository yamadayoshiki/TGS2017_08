#pragma once

#include "Transition/Transition.h"

// シーン切り替えクラス
class SceneTransition : public Transition{
public:
	// コンストラクタ
	SceneTransition(const IGameManagerPtr& gameManager);
	// デストラクタ
	~SceneTransition();

	// 開始     
	virtual void onStart()override;
	//更新
	virtual void onUpdate(float deltaTime)override;
	//描画
	virtual void onDraw() const override;
	// 終了フラグ
	virtual bool isEnd() override;
private:
	// α値
	GScolor m_Color;
};