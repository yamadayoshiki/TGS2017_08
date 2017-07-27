#ifndef ENEMYGROUP_H_
#define ENEMYGROUP_H_
#include "../../../ActorContains/Actor/Actor.h"
#include "../Entity/Enemys/Base/EnemyBasePtr.h"
#include <memory>
class EnemyManager;
//エネミーグループ
class EnemyGroup : public Actor
{
public:
	//デフォルトコンストラクタ
	EnemyGroup();

public:
	//セットアップ
	void SetUp(const std::shared_ptr<EnemyManager>& enemyMgr);
	//子を削除する(死んだ子の削除)
	void removeChildren_dead() override;

private:
	//倒せる敵か否か(スマポ参照)
	bool CanDead(const EnemyBasePtr& enemy);

private:
	std::weak_ptr<EnemyManager> p_EnemyMgr;
};
#endif // !ENEMYGROUP_H_
