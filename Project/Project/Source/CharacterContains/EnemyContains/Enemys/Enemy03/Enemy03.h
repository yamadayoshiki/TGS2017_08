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
		const FourDirection front,
		const TurnDirection turnDirection,
		const IGameManagerPtr& gameManager);
protected:
	//各種固有のコマンドの設定
	virtual void SetUpCommand() override;
	//各種固有のStateの設定
	virtual void SetUpState() override;
	//描画
	virtual void onDraw() const override;

protected:
	TurnDirection m_TurnDirection;
};

#endif
