#ifndef ENEMY12_H_
#define ENEMY12_H_
#include "../Base/EnemyBase.h"

//子機を生成するエネミー
class Enemy12 : public EnemyBase
{
public:
	//コンストラクタ
	Enemy12(
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