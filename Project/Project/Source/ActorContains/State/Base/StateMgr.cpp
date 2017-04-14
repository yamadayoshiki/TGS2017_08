#include "StateMgr.h"

#include "State_Dammy.h"

// コンストラクタ
StateMgr::StateMgr() : mCurrentState(std::make_shared<State_Dammy>()), mComponent(){}

// 更新処理
void StateMgr::action(Actor& actor, float deltaTime) {
	// 入力処理
	mCurrentState->input();
	// 時間更新処理
	mCurrentState->timer(deltaTime);
	// 更新処理
	mCurrentState->update(actor, deltaTime);
	// 終了判定がtrueになった場合ステートを変更
	if (mCurrentState->isEnd()) change(actor, mCurrentState->next());
}

// 衝突判定
void StateMgr::collide(Actor& actor, const Actor & other){
	// 衝突判定
	mCurrentState->collide(other);

	// 終了判定がtrueになった場合ステートを変更
	if (mCurrentState->isEnd()) change(actor, mCurrentState->next());
}

// 現在のステートが指定されたステートの場合true
bool StateMgr::currentActionType(ActionType action_type){
	return mComponent.mType == action_type;
}

// 現在の状態の要素
IState::Component StateMgr::getComponent(){
	return mComponent;
}

// ステートの変更処理
void StateMgr::change(Actor & actor, const IState::Component element){
	// ステートの変更処理(template版)
	change(actor, element.mID, element.mType);
}



