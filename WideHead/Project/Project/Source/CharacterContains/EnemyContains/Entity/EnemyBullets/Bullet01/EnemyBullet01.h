#ifndef ENEMYBULLET01_H_
#define ENEMYBULLET01_H_

#include "../../Enemys/Base/EnemyBase.h"

//直進弾
class EnemyBullet01 : public EnemyBase
{
public:
	//コンストラクタ
	EnemyBullet01(
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
};

#endif // !ENEMYBULLET01_H_
