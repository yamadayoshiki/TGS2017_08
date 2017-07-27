#include "ESEntry.h"
#include "../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../Base/GameManagerContains/IGameManager.h"
#include "../../../../../DrawManager/DrawOrder.h"
#include "../../../../../TextureContains/AnimationTexture/AnimationTexture.h"
#include "../../../../../Utility/Texture2DParameter/Texture2DParameter.h"
#include <GSmusic.h>
#include "../../../../../Utility/Sound/SoundName.h"
ESEntry::ESEntry(const EnemyBasePtr & enemy)
	: EnemyStateBase(enemy)
	, p_EntrySmork(std::make_shared<AnimationTexture>("Smork", enemy->GetGameMgr()->GetDrawManager(), DrawOrder::Effect_Front, 64, 8))
	, m_Timer(0) {
	p_EntrySmork->Initialize();
	p_EntrySmork->ChangeDisplayMode(DisplayMode::NonDisplay);
}

void ESEntry::unique_init() {
	m_Timer = 0;
	gsPlaySE(SE_ENEMY_CHILDAPPEARED);
	p_EntrySmork->Initialize();
	p_EntrySmork->ChangeDisplayMode(DisplayMode::Display);
	p_EntrySmork->GetParameter()->m_Position = p_Enemy.lock()->getPosition();
	p_Enemy.lock()->getTexture()->ChangeDisplayMode(DisplayMode::NonDisplay);
}

void ESEntry::update(float deltaTime) {
	p_EntrySmork->Update(deltaTime);
	if(m_Timer >= 40)
		p_Enemy.lock()->getTexture()->ChangeDisplayMode(DisplayMode::Display);

	if (p_EntrySmork->GetLoopCount() >= 1)
		change(EnemyStateName::Idle);

	m_Timer++;
}

void ESEntry::end() {
	p_EntrySmork->ChangeDisplayMode(DisplayMode::NonDisplay);
}
