#ifndef ENEMY01_H_
#define ENEMY01_H_

#include "../Base/EnemyBase.h"

//追跡する敵
class Enemy01 : public EnemyBase
{
public:
	//コンストラクタ
	Enemy01(
		IWorld* world,
		const GSvector2& position,
		const FourDirection front,
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
