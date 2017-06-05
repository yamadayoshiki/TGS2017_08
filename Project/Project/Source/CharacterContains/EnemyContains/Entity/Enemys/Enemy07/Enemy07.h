#ifndef ENEMY07_H_
#define ENEMY07_H_

#include "../Base/EnemyBase.h"

//ノコノコ
class Enemy07 : public EnemyBase
{
public:
	//コンストラクタ
	Enemy07(
		IWorld* world,
		const GSvector2& position,
		const FourDirection front,
		const IGameManagerPtr& gameManager);
	//デストラクタ
	~Enemy07();
	//クローン生成(使用時継承先でoverride)
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

#endif // !ENEMY07_H_
