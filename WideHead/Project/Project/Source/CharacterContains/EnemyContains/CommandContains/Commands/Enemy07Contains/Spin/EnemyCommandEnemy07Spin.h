#ifndef ENEMYCOMMANDENEMY07SPIN_H_
#define ENEMYCOMMANDENEMY07SPIN_H_

#include "../../Common/MoveContains/Straight/EnemyCommandStraight.h"

//ノコノコスピンコマンド
//指定回数以上バウンドすると死ぬ
class EnemyCommandEnemy07Spin : public EnemyCommandStraight
{
public:
	//コンストラクタ
	EnemyCommandEnemy07Spin(
		const EnemyBasePtr& enemy,
		const int limitSpringCounter);

protected:
	//正面に壁があった場合のリアクション
	virtual void HitWallReaction();

protected:
	int m_SpringCounter;		//跳ね返った回数
	int m_LimitSpringCounter;	//跳ね返る回数上限
};


#endif
