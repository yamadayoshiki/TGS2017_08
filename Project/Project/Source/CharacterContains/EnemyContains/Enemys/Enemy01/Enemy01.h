#ifndef ENEMY01_H_
#define ENEMY01_H_

#include "../Base/EnemyBase.h"

class Enemy01 : public EnemyBase
{
public:
	//コンストラクタ
	Enemy01(
		const IWorldPtr& world,
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
