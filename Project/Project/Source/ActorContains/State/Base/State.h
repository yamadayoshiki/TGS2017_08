#pragma once

#include "IState.h"
#include "../../Actor/Actor.h"

// 各プレイヤーステートの基底クラス
class State : public IState {
public:
	// コンストラクタ
	State();
	// 全状態共通の初期化
	virtual void common_init(Actor& actor, const Component comp) override;
	// 入力処理
	virtual void input() override;
	// 時間管理
	virtual void timer(const float& deltaTime) override;
	// ステートの変更処理
	virtual void change(const Component comp) override;
	// ステートの変更処理(template版)
	template <class STATE>
	void change(const STATE id, const ActionType type = ActionType::None);
	// ステートが終了したか否か
	virtual bool isEnd() override;
	// 次のステートの要素
	virtual Component next() const override;
protected:
	// ステートの要素
	Component mComponent;
	// ステートの要素
	Component mNextComponent;
	// ステートが終了したか否か
	bool mIsEnd;
	// タイマー
	float mTimer;
};

// ステートの変更処理(template版)
template<class STATE>
inline void State::change(const STATE id, const ActionType type){
	if (mComponent.mID == static_cast<int>(id)) return;
	// 次のステート情報の格納
	mNextComponent.mID = static_cast<int>(id);
	mNextComponent.mType = type;
	// ステートの終了条件をtrueに変更
	mIsEnd = true;
}
