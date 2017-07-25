#include "EnemyManager.h"
#include "../Entity/Enemys/Base/EnemyBase.h"
#include "../../../TextureContains/ITexture.h"
#include "../../../DrawManager/DrawOrder.h"
#include <GSvector2.h>
#include <algorithm>
#include <iterator>
#include "EnemyGroup.h"

EnemyManager::EnemyManager()
	: Actor(ActorName::EnemyManager)
	, m_SurviverSum(0) {
	m_TagetEnemyTextures.clear();
	m_Enemys.clear();
	m_Enemys[EnemyGroupName::Enemy09] = std::make_shared<EnemyGroup>();
	m_Enemys[EnemyGroupName::Normal] = std::make_shared<EnemyGroup>();
	m_Enemys[EnemyGroupName::Offensive] = std::make_shared<EnemyGroup>();
	m_Enemys[EnemyGroupName::Invincible] = std::make_shared<EnemyGroup>();
	m_Enemys[EnemyGroupName::BreakWall] = std::make_shared<EnemyGroup>();

	clearChildren();

	m_children.push_front(m_Enemys[EnemyGroupName::Enemy09]);
	m_children.push_front(m_Enemys[EnemyGroupName::Normal]);
	m_children.push_front(m_Enemys[EnemyGroupName::Offensive]);
	m_children.push_front(m_Enemys[EnemyGroupName::Invincible]);
	m_children.push_front(m_Enemys[EnemyGroupName::BreakWall]);

}

void EnemyManager::addChild(const ActorPtr & child) {
	child->initialize();
	//“¢”°‰Â”\“G‚©
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
	std::dynamic_pointer_cast<Actor>(child);
	//ƒOƒ‹[ƒv•ª‚¯
	switch (child->getName())
	{
	case ActorName::Enemy_09:
		m_Enemys[EnemyGroupName::Enemy09]->addChildNonInit(child);
		return;

	case ActorName::Enemy_07:
		m_Enemys[EnemyGroupName::Offensive]->addChildNonInit(child);
		return;

	case ActorName::BreakWall:
		m_Enemys[EnemyGroupName::BreakWall]->addChildNonInit(child);
		return;

	}
	if (isTarget == false) {
		m_Enemys[EnemyGroupName::Invincible]->addChildNonInit(child);
		return;
	}

	else {
		m_Enemys[EnemyGroupName::Normal]->addChildNonInit(child);
	}

}

void EnemyManager::SetUp(IWorld * world, const IGameManagerPtr & gameManager) {
	p_World = world;
	p_GameManager = gameManager;
	for (auto itr = m_Enemys.begin(); itr != m_Enemys.end(); itr++){
		itr->second->SetUp(shared_from_this());
	}
}

//Õ“Ë
void EnemyManager::EnemyCollide() {
	m_Enemys[EnemyGroupName::Enemy09]->collideChildren(*m_Enemys[EnemyGroupName::Enemy09]);
	m_Enemys[EnemyGroupName::Offensive]->collideChildren(*m_Enemys[EnemyGroupName::Enemy09]);
	m_Enemys[EnemyGroupName::Offensive]->collideChildren(*m_Enemys[EnemyGroupName::Normal]);
	m_Enemys[EnemyGroupName::Offensive]->collideChildren(*m_Enemys[EnemyGroupName::Offensive]);
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

//“¢”°‰Â”\“G‚Ì”‚ÌŒ¸ŽZ
void EnemyManager::DecreaseSurviverSum(int num){
	m_SurviverSum -= num;
}

bool EnemyManager::CanDead(const EnemyBasePtr& enemy) {
	if (enemy->getName() == ActorName::BreakWall) return false;
	return enemy->CanDead();
}

bool EnemyManager::CanDead(const EnemyBase & enemy) {
	if (enemy.getName() == ActorName::BreakWall) return false;
	return enemy.CanDead();
}