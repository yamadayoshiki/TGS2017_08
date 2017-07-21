#include "EnemyStateRushPreliminary.h"
#include "../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../../TextureContains/ITexture.h"
//コンストラクタ
EnemyStateRushPreliminary::EnemyStateRushPreliminary(
	const EnemyBasePtr& enemy,
	const int loop)
	:EnemyStateAttackBase(enemy)
	, m_Loop(loop) {
}

// 各状態独自の初期化
void EnemyStateRushPreliminary::onUniqueInit() {
	//テクスチャ切替
	p_Enemy.lock()->Settexture("RushPreliminary");
}
// 更新
void EnemyStateRushPreliminary::onUpdate(float deltaTime) {
	if (p_Enemy.lock()->getTexture()->GetLoopCount() >= m_Loop) {
		change(EnemyStateName::Rush);
	}
}
// 衝突判定
void EnemyStateRushPreliminary::onCollide(const Actor & other, const Body::ContactSet& contactSet) {}

// 終了時の処理
void EnemyStateRushPreliminary::onEnd() {
}