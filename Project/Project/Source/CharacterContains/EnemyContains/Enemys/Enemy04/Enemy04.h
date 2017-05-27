#ifndef ENEMY04_H_
#define ENEMY04_H_

#include "../Base/EnemyBase.h"

struct FourDirection;

//3回挟まれる(離される)と1マス移動
class Enemy04:public EnemyBase
{
public:
	//コンストラクタ
	Enemy04(
		IWorld* world,
		const GSvector2& position,
		const FourDirection& front,
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
};

#endif