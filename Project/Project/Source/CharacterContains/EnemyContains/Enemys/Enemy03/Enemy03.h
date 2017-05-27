#ifndef ENEMY03_H_
#define ENEMY03_H_

#include "../Base/EnemyBase.h"

//壁沿いに動く敵
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

	//クローン生成(使用時継承先でoverride)
	virtual ActorPtr clone(const GSvector2& position, const FourDirection& front = FourDirection(FourDirectionName::None)) override;

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
