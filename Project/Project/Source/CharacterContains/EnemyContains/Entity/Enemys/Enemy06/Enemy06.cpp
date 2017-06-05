#include "Enemy06.h"
#include "../../../../../TextureContains/Texture/Texture.h"
#include "../../../../../Base/GameManagerContains/IGameManager.h"
#include "../../../../../Utility/Rederer2D/Renderer2D.h"
#include "../../../../../ActorContains/Body/OrientedBoundingBox.h"

//コンストラクタ
Enemy06::Enemy06(
	IWorld * world,
	const GSvector2 & position,
	const FourDirection front,
	const IGameManagerPtr & gameManager)
	:EnemyBase(
		world,
		ActorName::Enemy_06,
		position,
		front,
		10,
		gameManager,
		std::make_shared<Texture>("Enemy02", gameManager->GetRenderer2D()),
		std::make_shared<OrientedBoundingBox>(GSvector2(0.0f, 0.0f), -90.0f, GSvector2(1.0f, 1.0f))) {
}

//クローン生成
ActorPtr Enemy06::clone(const GSvector2 & position, const FourDirection & front) {
	return std::make_shared<Enemy06>(p_World, position, front, p_GameManager);
}

//各種固有のコマンドの設定
void Enemy06::SetUpCommand() {

}

//各種固有のStateの設定
void Enemy06::SetUpState() {
}

//描画
void Enemy06::onDraw() const {
}