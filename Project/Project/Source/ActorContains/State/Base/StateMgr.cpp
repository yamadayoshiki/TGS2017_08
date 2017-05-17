#include "StateMgr.h"

#include "State_Dammy.h"

// コンストラクタ
StateMgr::StateMgr()
	: mCurrentState(std::make_shared<State_Dammy>())
	, m_CurrentID(0) {
}

// 更新処理
void StateMgr::action(float deltaTime) {
	// 入力処理
	mCurrentState->input();
	// 時間更新処理
	mCurrentState->timer(deltaTime);
	// 更新処理
	mCurrentState->update(deltaTime);
	// 終了判定がtrueになった場合ステートを変更
	if (mCurrentState->isEnd()) change(mCurrentState->next());
}

// 衝突判定
void StateMgr::collide(Actor& actor, const Actor & other) {
	// 衝突判定
	mCurrentState->collide(other);

	// 終了判定がtrueになった場合ステートを変更
	if (mCurrentState->isEnd()) change(mCurrentState->next());
}

// メッセージ処理
void StateMgr::handleMessage(EventMessage message, void* param) {
	//メッセージ処理
	mCurrentState->handleMessage(message,param);

	// 終了判定がtrueになった場合ステートを変更
	if (mCurrentState->isEnd()) change(mCurrentState->next());
}

// 現在の状態の要素
int StateMgr::getID() {
	return m_CurrentID;
}