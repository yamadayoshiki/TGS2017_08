#ifndef ENEMY11_H_
#define ENEMY11_H_
#include "../Base/EnemyBase.h"

//突っ込む敵
class Enemy11 : public EnemyBase
{
public:
	//コンストラクタ
	Enemy11(
		IWorld* world,
		const GSvector2& position,
		const FourDirection front,
		const IGameManagerPtr& gameManager);
	//デストラクタ
	~Enemy11();
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

#endif // !ENEMY11_H_
