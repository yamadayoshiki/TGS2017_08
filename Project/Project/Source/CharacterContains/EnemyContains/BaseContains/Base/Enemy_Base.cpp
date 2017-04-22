#include "Enemy_Base.h"

//コンストラクタ
Enemy_Base::Enemy_Base(
	const IWorldPtr& world,
	const ActorName& name,
	const GSvector2& position,
	const IGameManagerPtr& gameManager,
	const IBodyPtr& body)
	:Actor(world, name, position, gameManager, std::make_shared<NullTexture>(), body)
{
}

//更新
void Enemy_Base::onUpdate(float deltaTime)
{
}

//描画
void Enemy_Base::onDraw() const
{
}

//衝突した
void Enemy_Base::onCollide(Actor& other)
{
}