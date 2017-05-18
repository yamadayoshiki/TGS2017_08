#ifndef ENEMY01_H_
#define ENEMY01_H_

#include "../Base/EnemyBase.h"

struct FourDirection;

class Enemy01 : public EnemyBase
{
public:
	//コンストラクタ
	Enemy01(
		IWorld* world,
		const GSvector2& position,
		FourDirection& front,
		const IGameManagerPtr& gameManager);

protected:
	//各種固有のコマンドの設定
	virtual void SetUpCommand() override;
	//各種固有のStateの設定
	virtual void SetUpState() override;
	//描画
	virtual void onDraw() const override;
	//衝突した
	virtual void onCollide(Actor& other) override;
};

#endif
