#ifndef ENEMYSTATEENEMY02MOVE_H_
#define ENEMYSTATEENEMY02MOVE_H_

#include "../MoveBase/EnemyStateEnemy02MoveBase.h"

//Enemy02専用Move
class EnemyStateEnemy02Move : public EnemyStateEnemy02MoveBase
{
public:
	//コンストラクタ
	EnemyStateEnemy02Move(
		const EnemyBasePtr& enemy,
		const float speed);
	// 各状態独自の初期化
	virtual void onUniqueInit()override;
	// 更新処理
	virtual void onUpdate(float deltaTime)override;
	// 衝突判定
	virtual void onCollide(const Actor & other)override {}
	// 終了時の処理
	virtual void onEnd()override {}
	// 入力処理
	virtual void onInput() override {}

protected:
	float m_Speed;		//スピード
};

#endif // !ENEMYSTATEENEMY02MOVE_H_
