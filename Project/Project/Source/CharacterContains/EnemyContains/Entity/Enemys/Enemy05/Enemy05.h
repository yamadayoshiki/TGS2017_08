#ifndef ENEMY05_H_
#define ENEMY05_H_

#include "../Base/EnemyBase.h"

//直線を往復する敵
class Enemy05 : public EnemyBase
{
public:
	//コンストラクタ
	Enemy05(
		IWorld* world,
		const GSvector2& position,
		const FourDirection front,
		const IGameManagerPtr& gameManager);

	//クローン生成
	virtual ActorPtr clone(
		const GSvector2& position, 
		const FourDirection& front = FourDirection(FourDirectionName::None)) override;

protected:
	//各種固有のコマンドの設定
	virtual void SetUpCommand() override;
	//各種固有のStateの設定
	virtual void SetUpState() override;
	//描画
	virtual void onDraw() const override;
};

#endif // !ENEMY05_H_

