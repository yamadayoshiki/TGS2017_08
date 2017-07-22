#pragma once

#include "IState.h"

// ステートのダミークラス（ステートの切り替わり時に一旦使用）
class State_Dammy : public IState {
public:
	// コンストラクタ
	State_Dammy() : m_ID(-1) {}
	// 全状態共通の初期化
	virtual void common_init(const int id) override {}
	// 各状態独自の初期化
	virtual void unique_init() override {}
	// 入力処理
	virtual void input() override {}
	// 更新処理
	virtual void update(float deltaTime) override {}
	// 更新処理
	virtual void timer(const float& deltaTime) override {}
	// 状態の変更
	virtual void change_int(const int id) override {}
	// 状態の変更
	virtual void collide(const Actor & other, const Body::ContactSet& contactSet) override {}
	// 終了を返す
	virtual bool isEnd() override { return false; }
	// 次のステートの要素
	virtual int next() const override { return m_ID; }
	// 終了時の処理
	virtual void end() override {}
	// IState を介して継承されました
	virtual void addChild(const ActorName& name, const ActorPtr& child) override {}
	// メッセージ処理
	virtual void handleMessage(EventMessage message, void* param) override {};

private:
	// ステート
	int m_ID;

};
