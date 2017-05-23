#ifndef ENEMY05_H_
#define ENEMY05_H_

#include "../Base/EnemyBase.h"

//エネミー05
class Enemy05 : public EnemyBase
{
public:
	//コンストラクタ
	Enemy05(
		IWorld* world,
		const GSvector2& position,
		const FourDirection front,
		const IGameManagerPtr& gameManager);

protected:
	//各種固有のコマンドの設定
	virtual void SetUpCommand() override;
	//各種固有のStateの設定
	virtual void SetUpState() override;
	//描画
	virtual void onDraw() const override;
};

#endif // !ENEMY05_H_

