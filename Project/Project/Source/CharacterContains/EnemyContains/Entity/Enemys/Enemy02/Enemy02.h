#ifndef ENEMY02_H_
#define ENEMY02_H_

#include "../Base/EnemyBase.h"

//他の同種が死ぬと回転
class Enemy02 : public EnemyBase
{
public:
	//コンストラクタ
	Enemy02(
		IWorld* world,
		const GSvector2& position,
		const FourDirection front,
		const FourDirection turnDirection,
		const IGameManagerPtr& gameManager);

	//csvで生成(使用時継承先でoverride)
	virtual ActorPtr CsvGenerate(const int x, const int y, const int csvparam) override;

protected:
	//各種固有のコマンドの設定
	virtual void SetUpCommand() override;
	//各種固有のStateの設定
	virtual void SetUpState() override;
	//描画
	virtual void onDraw() const override;

protected:
	FourDirection m_TurnDirection;
};

#endif