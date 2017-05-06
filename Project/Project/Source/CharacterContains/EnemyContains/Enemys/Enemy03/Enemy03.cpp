#include "Enemy03.h"
#include "../../../../ActorContains/ActorName.h"
#include "../../../../TextureContains/Texture/Texture.h"
#include "../../../../Base/GameManagerContains/IGameManager.h"

//コンストラクタ
Enemy03::Enemy03(
	const IWorldPtr& world,
	const GSvector2& position,
	const IGameManagerPtr& gameManager)
	:EnemyBase(
		world,
		ActorName::Enemy_03,
		position,
		1.0f,
		gameManager,
		std::make_shared<Texture>("Enemy03", gameManager->GetRenderer2D())) {
}

//更新
void Enemy03::onUpdate(float deltaTime) {

}

//描画
void Enemy03::onDraw() const {

}

//衝突した
void Enemy03::onCollide(Actor& other) {

}