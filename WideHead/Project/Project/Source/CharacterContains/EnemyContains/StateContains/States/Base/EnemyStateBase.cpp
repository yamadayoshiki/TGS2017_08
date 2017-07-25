#include "EnemyStateBase.h"
#include "../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../Utility/MathSupport/MathSupport.h"
#include "../../../CommandContains/CommandManagers/Interface/IECommandMgr.h"
#include "../../../../../Define/Def_Float.h"
#include "../../../../../WorldContains/IWorld.h"
#include "../../../../../Map/Map.h"
#include "../../../../../Define/Def_GSvector2.h"
#include "../../../../../WorldContains/EventMessage/EventMessage.h"

//コンストラクタ
EnemyStateBase::EnemyStateBase(const EnemyBasePtr& enemy)
	: p_Enemy(enemy) {
}

// 入力処理
void EnemyStateBase::input() {
}

//メッセージ処理
void EnemyStateBase::handleMessage(EventMessage message, void * param) {
	switch (message)
	{
	case EventMessage::ENEMY_COMMAND_DEAD:
		change(EnemyStateName::Dead);
		return;
	}
	//各種固有のメッセージ処理
	OnHandleMessage(message, param);
}

//移動処理
void EnemyStateBase::ForwardMove(float deltaTime, float speed) {
	//移動ベクトルを算出
	GSvector2 move = GetVelocity(deltaTime, speed);

	//入力がない場合はreturn
	if (move == GSVECTOR2_ZERO)
		return;

	//移動ベクトル方向に向きを変換,本体に設定
	p_Enemy.lock()->setAngle(MathSupport::GetVec2ToVec2Angle(move));

	//移動後座標計算
	move = p_Enemy.lock()->getPosition() + move;

	//本体に座標を設定
	p_Enemy.lock()->setPosition(move);
}

//注視移動処理
void EnemyStateBase::RegardMove(FourDirection regardDirection, float deltaTime, float speed) {
	//移動ベクトルを算出
	GSvector2 move = GetVelocity(deltaTime, speed);

	//入力がない場合はreturn
	if (move == GSVECTOR2_ZERO)
		return;

	//移動後座標計算
	move = p_Enemy.lock()->getPosition() + move;

	//本体に座標を設定
	p_Enemy.lock()->setPosition(move);
}

/*
//注視移動処理(CLAMPあり)
PushDirection EnemyStateBase::RegardMoveClamp(FourDirection regardDirection, float deltaTime, float speed) {
//結果変数
FourDirection result;

//移動ベクトルを算出
GSvector2 move = GetVelocity(deltaTime, speed);

//入力がない場合はreturn
if (move == GSVECTOR2_ZERO)
return;

//移動後座標計算
move = p_Enemy->getPosition() + move;

//CLAMP処理
move = p_Enemy->getWorld()->GetMap().PushForPlayer(p_Enemy->getPosition(), move);

//本体に座標を設定
p_Enemy->setPosition(move);
}
*/

//ステートの変更処理
void EnemyStateBase::Change(const EnemyStateName name, void * param) {
	change(name);
}

//移動ベクトル算出
GSvector2 EnemyStateBase::GetVelocity(float deltaTime, float speed) {
	//目標地点までのベクトル
	GSvector2 toTarget = p_Enemy.lock()->GetCommandManager()->GetCommandVector();

	//入力がない場合はreturn
	if (toTarget.length() <= FLOAT_EPSILON)
		return GSVECTOR2_ZERO;

	//移動ベクトルを算出
	GSvector2 move = toTarget.getNormalized() * speed * deltaTime;
	if (move.length() > toTarget.length())
		move = toTarget;

	return move;
}
/*
//回転処理
void EnemyStateBase::Rotate(float deltaTime, float speed) {
//目標回転角度
float targetRotateAngle = p_Enemy->GetCommandManager()->GetCommandRotateAngle();

//入力がない場合はreturn
if (abs(targetRotateAngle) <= FLOAT_EPSILON)
return;

//回転角度を算出
float rotate = targetRotateAngle = CLAMP(targetRotateAngle, -speed*deltaTime, speed*deltaTime);

//本体に回転を設定
p_Enemy->setAngle(p_Enemy->SetDirection())
}
*/