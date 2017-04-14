#include "State.h"

// コンストラクタ
State::State() : 
	mComponent({ -1, ActionType::None }), 
	mNextComponent({ -1, ActionType::None }), 
	mTimer(0), mIsEnd(false) {}

// 全状態共通の初期化
void State::common_init(Actor & actor, const Component comp){
	// 変数の初期化
	mComponent = comp;
	mTimer = 0;
	mIsEnd = false;
}

// 入力処理
void State::input(){}

// 時間管理
void State::timer(const float& deltaTime){
	mTimer += deltaTime;
}

// ステートの変更処理
void State::change(const Component comp){
	// ステートの変更処理(template版)
	change(comp.mID, comp.mType);
}

// ステートが終了したか否か
bool State::isEnd(){
	return mIsEnd;
}

// 次のステートの要素
IState::Component State::next() const{
	return mNextComponent;
}


