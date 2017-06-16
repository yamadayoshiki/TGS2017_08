#include "DeadWall.h"
#include"../../../Entity/Enemys/Base/EnemyBase.h"
#include"../../../../../WorldContains/IWorld.h"
#include"../../../../../WorldContains/EventMessage/EventMessage.h"
#include"../../../../../Wall/BreakWall.h"
#include"../../../../../Map/MapType.h"
#include"../../../../../Map/Map.h"


//コンストラクタ
DeadWall::DeadWall(const EnemyBasePtr & enemy) :EnemyStateBase(enemy)
{

}
// 各状態独自の初期化
void DeadWall::unique_init()
{
	p_Enemy.lock()->getWorld()->sendMessage(EventMessage::MapDataUpdate);
}
// 更新処理
void DeadWall::update(float deltaTime)
{
	p_Enemy.lock()->dead();

	p_Enemy.lock()->getWorld()->GetMap()->SetcsvParameter(p_Enemy.lock()->getPosition(),0,MapType::Double,p_Enemy.lock()->getWorld());
}
// 衝突判定
void DeadWall::collide(const Actor & other)
{

}
// 終了時の処理
void DeadWall::end()
{

}
