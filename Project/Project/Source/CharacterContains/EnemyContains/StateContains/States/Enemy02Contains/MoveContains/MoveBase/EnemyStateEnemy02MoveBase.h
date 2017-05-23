#ifndef ENEMYSTATEENEMY02MOVEBASE_H_
#define ENEMYSTATEENEMY02MOVEBASE_H_

#include "../../../MoveContains/MoveBase/EnemyStateMoveBase.h"

//Enemy02専用移動基底クラス
class EnemyStateEnemy02MoveBase : public EnemyStateMoveBase
{
public:
	// コンストラクタ
	EnemyStateEnemy02MoveBase(const EnemyBasePtr& enemy);
	//メッセージ処理
	virtual void handleMessage(EventMessage message, void* param) override;

protected:
	// 各状態独自の初期化
	virtual void onUniqueInit() = 0;
	// 更新処理
	virtual void onUpdate(float deltaTime) = 0;
	// 衝突判定
	virtual void onCollide(const Actor & other) = 0;
	// 終了時の処理
	virtual void onEnd() = 0;
	// 入力処理
	virtual void onInput() = 0;
};

#endif // !ENEMYSTATEENEMY02MOVEBASE_H_
