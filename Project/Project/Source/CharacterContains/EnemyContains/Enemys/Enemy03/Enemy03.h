#ifndef ENEMY03_H_
#define ENEMY03_H_

#include "../Base/EnemyBase.h"

class Enemy03 : public EnemyBase
{
public:
	//コンストラクタ
	Enemy03(
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
