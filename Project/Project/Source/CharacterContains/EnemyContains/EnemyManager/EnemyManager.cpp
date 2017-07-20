#include "EnemyManager.h"
#include "../Entity/Enemys/Base/EnemyBase.h"
#include "../../../TextureContains/ITexture.h"
#include "../../../DrawManager/DrawOrder.h"
#include <GSvector2.h>
#include <algorithm>
#include <iterator>

EnemyManager::EnemyManager()
	: Actor(ActorName::EnemyManager)
	, m_SurviverSum(0) {
	m_TagetEnemyTextures.clear();
	m_Enemys.clear();
	m_Enemys[EnemyGroup::Enemy09] = std::make_shared<Actor>();
	m_Enemys[EnemyGroup::Normal] = std::make_shared<Actor>();
	m_Enemys[EnemyGroup::Offensive] = std::make_shared<Actor>();
	m_Enemys[EnemyGroup::Invincible] = std::make_shared<Actor>();
	m_Enemys[EnemyGroup::BreakWall] = std::make_shared<Actor>();


	m_children.push_front(m_Enemys[EnemyGroup::Enemy09]);
	m_children.push_front(m_Enemys[EnemyGroup::Normal]);
	m_children.push_front(m_Enemys[EnemyGroup::Offensive]);
	m_children.push_front(m_Enemys[EnemyGroup::Invincible]);
	m_children.push_front(m_Enemys[EnemyGroup::BreakWall]);

}

void EnemyManager::addChild(const ActorPtr & child) {
	child->initialize();
	//討伐可能敵か
	bool isTarget = CanDead(std::dynamic_pointer_cast<EnemyBase>(child));
	if (isTarget == true) {
		m_SurviverSum++;
		for (auto itr = m_TagetEnemyTextures.begin(); itr != m_TagetEnemyTextures.end(); itr++)
		{
			if (itr->m_Name == child->getName())
				goto SKIP;
		}
		TagetEnemy l_Result(child->getName(), child->getTexture());
		m_TagetEnemyTextures.push_back(l_Result);
	}
SKIP:
	//グループ分け
	switch (child->getName())
	{
	case ActorName::Enemy_09:
		m_Enemys[EnemyGroup::Enemy09]->addChildNonInit(child);
		return;

	case ActorName::Enemy_07:
		m_Enemys[EnemyGroup::Offensive]->addChildNonInit(child);
		return;

	case ActorName::BreakWall:
		m_Enemys[EnemyGroup::BreakWall]->addChildNonInit(child);
		return;

	}
	if (isTarget == false) {
		m_Enemys[EnemyGroup::Invincible]->addChildNonInit(child);
		return;
	}

	else {
		m_Enemys[EnemyGroup::Normal]->addChildNonInit(child);
	}

}

void EnemyManager::removeChildren_dead() {
	//討伐可能敵か
	eachChildren([&](Actor& child)
	{
		child.removeChildren([&](Actor& childchild)
		{
			if (childchild.GetDead() == true)
			{
				if (CanDead(*dynamic_cast<EnemyBase*>(&childchild)) == true)
				{
					m_SurviverSum--;
				}
				return true;
			}
		});
		child.eachChildren([](Actor& childchild) {childchild.removeChildren_dead(); });
	});
}

void EnemyManager::SetUp(IWorld * world, const IGameManagerPtr & gameManager) {
	p_World = world;
	p_GameManager = gameManager;
}

//衝突
void EnemyManager::EnemyCollide() {
	m_Enemys[EnemyGroup::Enemy09]->collideChildren(*m_Enemys[EnemyGroup::Enemy09]);
	m_Enemys[EnemyGroup::Offensive]->collideChildren(*m_Enemys[EnemyGroup::Enemy09]);
	m_Enemys[EnemyGroup::Offensive]->collideChildren(*m_Enemys[EnemyGroup::Normal]);
	m_Enemys[EnemyGroup::Offensive]->collideChildren(*m_Enemys[EnemyGroup::Offensive]);
}

int EnemyManager::GetSurviverSum() const {
	return m_SurviverSum;
}

void EnemyManager::GetTagetEnemyTextures(std::vector<ITexturePtr>& out) {
	out.clear();
	for (auto itr = m_TagetEnemyTextures.begin(); itr != m_TagetEnemyTextures.end(); itr++)
	{
		ITexturePtr l_Result = itr->p_Texture.lock()->Clone(DrawOrder::UI_Front1);
		l_Result->ChangeDisplayMode(DisplayMode::NonDisplay);
		out.push_back(l_Result);
	}
}

int EnemyManager::GetNumTagetEnemyTextures() {
	return m_TagetEnemyTextures.size();
}

bool EnemyManager::CanDead(const EnemyBasePtr& enemy) {
	if (enemy->getName() == ActorName::BreakWall) return false;
	return enemy->CanDead();
}

bool EnemyManager::CanDead(const EnemyBase & enemy) {
	if (enemy.getName() == ActorName::BreakWall) return false;
	return enemy.CanDead();
}