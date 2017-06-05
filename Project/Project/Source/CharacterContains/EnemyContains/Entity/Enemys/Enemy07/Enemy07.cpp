#include "Enemy07.h"
#include "../../../../../TextureContains/Texture/Texture.h"
#include "../../../../../Base/GameManagerContains/IGameManager.h"
#include "../../../../../Utility/Rederer2D/Renderer2D.h"
#include "../../../../../ActorContains/Body/OrientedBoundingBox.h"

//コンストラクタ
Enemy07::Enemy07(
	IWorld * world,
	const GSvector2 & position,
	const FourDirection front,
	const IGameManagerPtr & gameManager)
	: EnemyBase(
		world,
		ActorName::Enemy_06,
		position,
		front,
		10,
		gameManager,
		std::make_shared<Texture>("Enemy02", gameManager->GetRenderer2D()),
		std::make_shared<OrientedBoundingBox>(GSvector2(0.0f, 0.0f), -90.0f, GSvector2(1.0f, 1.0f))) {
}

//デストラクタ
Enemy07::~Enemy07() {
}

//クローン生成
ActorPtr Enemy07::clone(const GSvector2 & position, const FourDirection & front) {
	return std::make_shared<Enemy07>(p_World, position, front, p_GameManager);
}

//各種固有のコマンドの設定
void Enemy07::SetUpCommand() {
}

//各種固有のStateの設定
void Enemy07::SetUpState()
{
}

//描画
void Enemy07::onDraw() const
{
}