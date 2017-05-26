#ifndef ENEMYSTATEMOVEREPELMOVE_H_
#define ENEMYSTATEMOVEREPELMOVE_H_

#include "../Base/EnemyStateMoveRepelBase.h"

class EnemyStateMoveRepelMove : public EnemyStateMoveRepelBase
{
public:
	//コンストラクタ
	EnemyStateMoveRepelMove(const EnemyBasePtr& enemy,
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

#endif // !ENEMYSTATEMOVEREPELMOVE_H_
