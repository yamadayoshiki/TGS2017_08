#include "TargetCircle.h"
#include "../../../CharacterContains/EnemyContains/Entity/Enemys/Base/EnemyBase.h"
#include <GSvector2.h>
#include "../../../Base/GameManagerContains/IGameManager.h"
#include "../../../TextureContains/Texture/Texture.h"
#include "../../../DrawManager/DrawOrder.h"
#include "../../../Utility/Texture2DParameter/Texture2DParameter.h"
TargetCircle::TargetCircle(IWorld * world, const IGameManagerPtr & gameManager, const EnemyBasePtr & targetEnemy)
	: Actor(world, ActorName::UI_Sprite, GSvector2(0.0f, 0.0f), gameManager, std::make_shared<Texture>("TargetBlock", gameManager->GetDrawManager(), DrawOrder::UI))
	, p_TargetEnemy(targetEnemy) {
	p_Texture->GetParameter()->m_Center += GSvector2(0.0f, 32.0f);
}


void TargetCircle::onInitialize() {
	MatchPos();
}

void TargetCircle::OnLateUpdate() {
	if (p_TargetEnemy->GetDead() == true) {
		dead();
		return;
	}

	MatchPos();
}

void TargetCircle::MatchPos() {
	setPosition(p_TargetEnemy->getPosition());
}
