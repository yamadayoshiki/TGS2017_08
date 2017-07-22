#include "TargetEnemySprite.h"
#include "../ZoomSprite/ZoomSprite.h"
#include "../../../TextureContains/Texture/Texture.h"
#include "../../../Base/GameManagerContains/IGameManager.h"
TargetEnemySprite::TargetEnemySprite(
	IWorld * world,
	const GSvector2 & position,
	const IGameManagerPtr & gameManager,
	const ITexturePtr & targetEnemy,
	const float rateOfTime)
	: AnimationSpriteBase(world, position, gameManager)
	, m_OffsetPos(GSvector2(-315, 0)) {
	p_DownTarget = std::make_shared<ZoomSprite>(world, position, gameManager, std::make_shared<Texture>("Kokuti", gameManager->GetDrawManager(), DrawOrder::PauseBack));
	p_TargetEnemy = std::make_shared<ZoomSprite>(world, position, gameManager, targetEnemy->Clone(DrawOrder::PauseBack), GSvector2(3.0f, 3.0f), GSvector2(2.0f, 2.0f));
	p_DownTarget->initialize();
	p_TargetEnemy->initialize();

	p_TargetEnemy->setPosition(p_DownTarget->getPosition() + p_DownTarget->GetScale() * m_OffsetPos);
}

void TargetEnemySprite::onUpdate(float deltaTime) {
	p_DownTarget->update(deltaTime);
	p_TargetEnemy->update(deltaTime);

	p_TargetEnemy->setPosition(p_DownTarget->getPosition() + p_DownTarget->GetScale() * m_OffsetPos);

	p_DownTarget->LateUpdate();
	p_TargetEnemy->LateUpdate();
}

void TargetEnemySprite::ChangeDisplayMode(const DisplayMode mode) {
	p_DownTarget->ChangeDisplayMode(mode);
	p_TargetEnemy->ChangeDisplayMode(mode);
}

bool TargetEnemySprite::IsEnd() const {
	return p_DownTarget->IsEnd();
}
