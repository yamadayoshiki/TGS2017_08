#include "Enemy01.h"
#include "../../../../ActorContains/ActorName.h"
#include "../../../../TextureContains/Texture/Texture.h"
#include "../../../../Base/GameManagerContains/IGameManager.h"

//コンストラクタ
Enemy01::Enemy01(
	const IWorldPtr& world,
	const GSvector2& position,
	const IGameManagerPtr& gameManager)
	:EnemyBase(
		world,
		ActorName::Enemy_01,
		position,
		1.0f,
		gameManager,
		std::make_shared<Texture>("Enemy01",gameManager->GetRenderer2D())) {
}

//更新
void Enemy01::onUpdate(float deltaTime) {

}

//描画
void Enemy01::onDraw() const {

}

//衝突した
void Enemy01::onCollide(Actor& other) {

}