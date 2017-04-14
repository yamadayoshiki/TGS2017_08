#pragma once

#include "IStatePtr.h"
#include "IState.h"

#include <unordered_map>

class Actor;

// ステートの処理管理
class StateMgr{
public:
	// コンストラクタ
	StateMgr();
public:
	// 更新処理
	void action(Actor& actor, float deltaTime) ;
	// ステートの追加(template版)
	template <class STATE>
	void add(STATE id, const IStatePtr& state);
	// ステートの変更処理(template版)
	template <class STATE>
	void change(Actor& actor, const STATE id, const ActionType type = ActionType::None);
	// ステートの変更処理
	void change(Actor& actor, const IState::Component element);
	// 指定されたステートの場合true(template版)
	template <class STATE>
	bool currentState(STATE state);
	// 現在のステートが指定されたステートの場合true
	bool currentActionType(ActionType action_type = ActionType::None);
	// 現在の状態の要素
	IState::Component getComponent();
	// 衝突判定
	void collide(Actor& actor, const Actor& other);
private:
	// コピー禁止
	StateMgr(const StateMgr& other) = delete;
	StateMgr& operator = (const StateMgr& other) = delete;
protected:
	// ステート登録用map
	std::unordered_map<int, IStatePtr> mStates;
	// 現在のステート
	IStatePtr mCurrentState;
	// 現在の要素
	IState::Component mComponent;
};

// 指定されたステートの場合true(template版)
template<class STATE>
inline bool StateMgr::currentState(STATE state){
	return mComponent.mID == static_cast<int>(state);
}

// ステートの変更処理(template版)
template<class STATE>
inline void StateMgr::change(Actor & actor, const STATE id, const ActionType type) {
	// 前ステートの終了処理
	mCurrentState->end();
	// 要素の格納
	mComponent.mID = (int)id;
	mComponent.mType = type;
	// 実行ステートを変更
	mCurrentState = mStates[mComponent.mID];
	// 共通の初期化
	mCurrentState->common_init(actor, mComponent);
	// 固有の初期化
	mCurrentState->unique_init(actor);
}

// ステートの追加(template版)
template<class STATE>
inline void StateMgr::add(STATE id, const IStatePtr & state){
	// キーを指定して格納
	mStates[static_cast<int>(id)] = state;
}

