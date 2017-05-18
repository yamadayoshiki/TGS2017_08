#include "EnemyStateBase.h"
#include "../../../Enemys/Base/EnemyBase.h"
#include "../../../../../Utility/MathSupport/MathSupport.h"
#include "../../../CommandContains/CommandManagers/Interface/IEnemyCommandManager.h"

//コンストラクタ
EnemyStateBase::EnemyStateBase(const EnemyBasePtr& enemy)
	: p_Enemy(enemy) {
}

// 入力処理
void EnemyStateBase::input() {
}

//移動処理
void EnemyStateBase::Move(float deltaTime, float speed)
{
	//目的地までのベクトル
	GSvector2 targetVector = p_Enemy->GetCommandManager()->GetCommandVector();

	//入力がない場合はreturn
	if (targetVector == GSvector2(0.0f, 0.0f))
		return;

	//移動ベクトルを算出
	GSvector2 move = targetVector.getNormalized() * speed * deltaTime;
	if (move.length() > targetVector.length())
		move = targetVector;

	//移動ベクトル方向に向きを変換,本体に設定
	p_Enemy->setAngle(MathSupport::GetVec2ToVec2Angle(move));

	//移動後座標計算
	move = p_Enemy->getPosition() + move;

	//本体に座標を設定
	p_Enemy->setPosition(move);
}

//回転処理
void EnemyStateBase::Rotate(float deltaTime)
{
	//入力がない場合はreturn
	if (p_Enemy->GetCommandManager()->GetCommandRotateAngle() != 0)
		return;

	//回転
}