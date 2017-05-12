#ifndef ENEMY02_H_
#define ENEMY02_H_

#include "../Base/EnemyBase.h"

class Enemy02 : public EnemyBase
{
	//コンストラクタ
	Enemy02(
		IWorld* world,
		const GSvector2& position,
		const IGameManagerPtr& gameManager);
protected:
	//更新
	virtual void onUpdate(float deltaTime) override;
	//描画
	virtual void onDraw() const override;
	//衝突した
	virtual void onCollide(Actor& other) override;
};

#endif