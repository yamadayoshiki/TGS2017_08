#ifndef ENEMY_COMMONSTATE_RUSHPRELIMINARY_H_
#define ENEMY_COMMONSTATE_RUSHPRELIMINARY_H_

#include "../AttackBase/Enemy_CommonState_AttackBase.h"

class Enemy_CommonState_RushPreliminary :public Enemy_CommonState_AttackBase
{
public:
	//コンストラクタ
	Enemy_CommonState_RushPreliminary(GSvector2& pos, GSmatrix4& mat);
protected:
	// 各状態独自の初期化
	virtual void onUniqueInit(Actor & actor) override;
	// 更新処理
	virtual void onUpdate(Actor & actor, float deltaTime) override;
	// 衝突判定
	virtual void onCollide(const Actor & other) override;
	// 終了時の処理
	virtual void onEnd() override;
	// 入力処理
	virtual void onInput() override;
};
#endif // !ENEMY_COMMONSTATE_RUSHPRELIMINARY_H_
