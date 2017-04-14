#pragma once

#include "IState.h"

// ステートのダミークラス（ステートの切り替わり時に一旦使用）
class State_Dammy : public IState {
public:
	// コンストラクタ
	State_Dammy() : mComponent({ -1, ActionType::None }) {}
	// 全状態共通の初期化
	virtual void common_init(Actor & actor, const Component comp) override{}
	// 各状態独自の初期化
	virtual void unique_init(Actor & actor) override{}
	// 入力処理
	virtual void input() override{}
	// 更新処理
	virtual void update(Actor & actor, float deltaTime) override{}
	// 更新処理
	virtual void timer(const float& deltaTime) override{}
	// 状態の変更
	virtual void change(const Component comp) override{}
	// 状態の変更
	virtual void collide(const Actor & other) override {}
	// 終了を返す
	virtual bool isEnd() override { return false; }
	// 次のステートの要素
	virtual Component next() const override { return mComponent; }
	// 終了時の処理
	virtual void end() override{}
private:
	// 要素の格納用変数
	Component mComponent;
};
