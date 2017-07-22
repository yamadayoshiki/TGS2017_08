#include "GamePlayReady.h"
#include "../../Elements/ZoomSprite/ZoomSprite.h"
#include "../../../Define/Def_Nagano.h"
#include "../../../TextureContains/Texture/Texture.h"
#include "../../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../../WorldContains/World/World.h"
#include "../../../DrawManager/DisplayMode.h"
#include "../../../CharacterContains/EnemyContains/EnemyManager/EnemyManager.h"
#include "../../Elements/TargetEnemySprite/TargetEnemySprite.h"
#include "../GamePlay.h"
#include "../../../UIContains/Number/Number.h"

GamePlayReady::GamePlayReady()
	: m_CurIndex(0) {
}

void GamePlayReady::OnStart() {
	std::dynamic_pointer_cast<GamePlay>(p_Parent.lock())->GetPlayerRemainingUI().lock()->SetNum(p_GameManager->GetPlayerParameter().GetRemaining());

	m_CurIndex = 0;

	//world‚É’Ç‰Á‚¹‚¸
	m_SpriteVector.push_back(std::make_shared<ZoomSprite>(p_World.get(), SCREEN_SIZE / 2, p_GameManager, std::make_shared<Texture>("StageTitle" + std::to_string(p_GameManager->get_MapOrder()), p_GameManager->GetDrawManager(), DrawOrder::PauseBack)));

	std::vector<ITexturePtr> enemyTextures;
	std::dynamic_pointer_cast<EnemyManager>(p_World->findActor(ActorName::EnemyManager))->GetTagetEnemyTextures(enemyTextures);
	for (auto itr = enemyTextures.begin(); itr != enemyTextures.end(); itr++)
		m_SpriteVector.push_back(std::make_shared<TargetEnemySprite>(p_World.get(), SCREEN_SIZE / 2, p_GameManager, *itr));

	m_SpriteVector.push_back(std::make_shared<ZoomSprite>(p_World.get(), SCREEN_SIZE / 2, p_GameManager, std::make_shared<Texture>("PlayStartLogo", p_GameManager->GetDrawManager(), DrawOrder::PauseBack)));

	for (auto itr = m_SpriteVector.begin(); itr != m_SpriteVector.end(); itr++)
		(*itr)->ChangeDisplayMode(DisplayMode::NonDisplay);

	m_SpriteVector[m_CurIndex]->ChangeDisplayMode(DisplayMode::Display);
}

void GamePlayReady::OnUpdate(float deltaTime) {
	if (m_CurIndex < 0) {
		Change(SceneName::Play);
		return;
	}
	p_Parent.lock()->StopWorld();

	m_SpriteVector[m_CurIndex]->update(deltaTime);
	m_SpriteVector[m_CurIndex]->LateUpdate();

	if (m_SpriteVector[m_CurIndex]->IsEnd() == true)
		ChangeSprite();
}

void GamePlayReady::OnDraw() const {
}

void GamePlayReady::OnEnd() {
	p_Parent.lock()->Restart();
	std::vector < std::shared_ptr<AnimationSpriteBase >> a;
	m_SpriteVector.swap(a);
	m_SpriteVector.clear();
}

void GamePlayReady::ChangeSprite() {
	m_SpriteVector[m_CurIndex]->ChangeDisplayMode(DisplayMode::NonDisplay);
	m_CurIndex += 1;
	if (m_SpriteVector.size() <= m_CurIndex) {
		m_CurIndex = -1;
		return;
	}
	m_SpriteVector[m_CurIndex]->ChangeDisplayMode(DisplayMode::Display);
}
