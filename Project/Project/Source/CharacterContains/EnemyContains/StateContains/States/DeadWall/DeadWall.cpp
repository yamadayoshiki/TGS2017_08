#include "DeadWall.h"
#include"../../../Entity/Enemys/Base/EnemyBase.h"
#include"../../../../../WorldContains/IWorld.h"
#include"../../../../../WorldContains/EventMessage/EventMessage.h"
#include"../../../../../Wall/BreakWall.h"
#include"../../../../../Map/MapType.h"
#include"../../../../../Map/Map.h"


//�R���X�g���N�^
DeadWall::DeadWall(const EnemyBasePtr & enemy) :EnemyStateBase(enemy)
{

}
// �e��ԓƎ��̏�����
void DeadWall::unique_init()
{
	p_Enemy.lock()->getWorld()->sendMessage(EventMessage::MapDataUpdate);
}
// �X�V����
void DeadWall::update(float deltaTime)
{
	p_Enemy.lock()->dead();

	p_Enemy.lock()->getWorld()->GetMap()->SetcsvParameter(p_Enemy.lock()->getPosition(),0,MapType::Double,p_Enemy.lock()->getWorld());
}
// �Փ˔���
void DeadWall::collide(const Actor & other)
{

}
// �I�����̏���
void DeadWall::end()
{

}
