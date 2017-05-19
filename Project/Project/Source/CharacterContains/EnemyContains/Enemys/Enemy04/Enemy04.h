#ifndef ENEMY04_H_
#define ENEMY04_H_

#include "../Base/EnemyBase.h"
struct FourDirection;

class Enemy04:public EnemyBase
{
public:
	//コンストラクタ
	Enemy04(
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
};

#endif // !ENEMY04_H_
