#ifndef ENEMY04_H_
#define ENEMY04_H_

#include "../Base/EnemyBase.h"

struct FourDirection;

//3回挟まれる(離される)と1マス移動
class Enemy04 :public EnemyBase
{
public:
	//コンストラクタ
	Enemy04(
		IWorld* world,
		const GSvector2& position,
		const FourDirection& front,
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
};

#endif