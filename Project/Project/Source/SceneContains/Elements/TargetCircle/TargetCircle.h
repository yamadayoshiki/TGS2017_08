#ifndef TARGETCIRCLE_H_
#define TARGETCIRCLE_H_
#include "../../../ActorContains/Actor/Actor.h"
#include "../../../CharacterContains/EnemyContains/Entity/Enemys/Base/EnemyBasePtr.h"
class TargetCircle : public Actor
{
public:
	TargetCircle(IWorld * world, const IGameManagerPtr & gameManager,const EnemyBasePtr& targetEnemy);

protected:
	//初期化
	void onInitialize() override;
	//更新
	void OnLateUpdate() override;

private:
	//目標敵の位置に合わせる
	void MatchPos();

protected:
	EnemyBasePtr p_TargetEnemy;
};
#endif // !TARGETCIRCLE_H_
