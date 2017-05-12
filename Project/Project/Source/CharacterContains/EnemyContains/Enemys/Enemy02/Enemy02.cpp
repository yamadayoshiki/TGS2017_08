#include "Enemy02.h"
#include "../../../../ActorContains/ActorName.h"
#include "../../../../TextureContains/Texture/Texture.h"
#include "../../../../Base/GameManagerContains/IGameManager.h"

//コンストラクタ
Enemy02::Enemy02(
	IWorld* world,
	const GSvector2& position,
	const IGameManagerPtr& gameManager)
	:EnemyBase(
		world,
		ActorName::Enemy_02,
		position,
		1.0f,
		gameManager,
		std::make_shared<Texture>("Enemy02", gameManager->GetRenderer2D())) {

}
//更新
void Enemy02::onUpdate(float deltaTime) {

}
//描画
void Enemy02::onDraw() const {

}
//衝突した
void Enemy02::onCollide(Actor& other) {

}