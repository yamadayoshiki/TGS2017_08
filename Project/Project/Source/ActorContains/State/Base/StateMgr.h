#pragma once

#include "IStatePtr.h"
#include "IState.h"

#include <unordered_map>

class Actor;
enum class EventMessage;

// ステートの処理管理
class StateMgr {
public:
	// コンストラクタ
	StateMgr();
public:
	// 更新処理
	void action(float deltaTime);
	// ステートの追加(template版)
	template <class STATE>
	void add(STATE id, const IStatePtr& state);
	// ステートの変更処理(template版)
	template <class STATE>
	void change(const STATE id);
	// 指定されたステートの場合true(template版)
	template <class STATE>
	bool currentState(STATE state);
	// 現在の状態の要素
	int getID();
	// 衝突判定
	void collide(Actor& actor, const Actor& other);
	// メッセージ処理
	void handleMessage(EventMessage message, void* param);
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
	int m_CurrentID;
};


// ステートの追加(template版)
template<class STATE>
inline void StateMgr::add(STATE id, const IStatePtr & state) {
	// キーを指定して格納
	mStates[static_cast<int>(id)] = state;
}

// ステートの変更処理(template版)
template<class STATE>
inline void StateMgr::change(const STATE id) {
	// 前ステートの終了処理
	mCurrentState->end();
	// 要素の格納
	m_CurrentID = (int)id;
	// 実行ステートを変更
	mCurrentState = mStates[m_CurrentID];
	// 共通の初期化
	mCurrentState->common_init(m_CurrentID);
	// 固有の初期化
	mCurrentState->unique_init();
}

// 指定されたステートの場合true(template版)
template<class STATE>
inline bool StateMgr::currentState(STATE state) {
	return m_CurrentID == static_cast<int>(state);
}