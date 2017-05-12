#ifndef ENMYCOMMANDSTRAIGHT_H_
#define ENMYCOMMANDSTRAIGHT_H_

#include "../Base/EnemyCommandBase.h"

//直進クラス
class EnemyCommandStraight :public EnemyCommandBase
{
public:
	//コンストラクタ
	EnemyCommandStraight(const EnemyBasePtr& enemy, GSvector2 velocity);
	//更新
	virtual void Update(float deltaTime) override;
	//終了
	virtual void Finalize() override;

protected:
	//各種固有の初期化
	virtual void OnInitialize() override;
	//正面に壁があった場合のリアクション
	virtual void HitWallReaction();
	//折り返す
	void TurnBack();
};

#endif // !ENMYCOMMANDSTRAIGHT_H_
