#include "EnemyGroup.h"
#include "EnemyManager.h"
#include "../Entity/Enemys/Base/EnemyBase.h"
EnemyGroup::EnemyGroup()
	: p_EnemyMgr(std::weak_ptr<EnemyManager>()) {
}

void EnemyGroup::SetUp(const std::shared_ptr<EnemyManager>& enemyMgr) {
	p_EnemyMgr = enemyMgr;
}

void EnemyGroup::removeChildren_dead() {
	/*/
	removeChildren([&](Actor& child)
	{
		if (child.GetDead())
		{
			//p_EnemyMgr.lock()->DecreaseSurviverSum(1);
			return true;
		}
	});
	//*/
	std::vector<std::forward_list<ActorPtr>::iterator> removeItr;
	for (auto itr = m_children.begin(); itr != m_children.end(); itr++)
	{
		if ((*itr)->GetDead() == true)
		{
			if (CanDead(std::dynamic_pointer_cast<EnemyBase>(*itr)))
				p_EnemyMgr.lock()->DecreaseSurviverSum(1);

			removeItr.push_back(itr);
		}
	}
	for (auto itr = removeItr.begin(); itr != removeItr.end(); itr++)
		m_children.remove(*(*itr));

	eachChildren([](Actor& child) { child.removeChildren_dead(); });
}

bool EnemyGroup::CanDead(const EnemyBasePtr & enemy) {
	if (enemy->getName() == ActorName::BreakWall) return false;
	return enemy->CanDead();
}
