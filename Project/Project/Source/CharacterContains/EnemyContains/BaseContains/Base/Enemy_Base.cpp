#include "Enemy_Base.h"

//�R���X�g���N�^
Enemy_Base::Enemy_Base(
	const IWorldPtr& world,
	const ActorName& name,
	const GSvector2& position,
	const IGameManagerPtr& gameManager,
	const IBodyPtr& body)
	:Actor(world, name, position, gameManager, std::make_shared<NullTexture>(), body)
{
}

//�X�V
void Enemy_Base::onUpdate(float deltaTime)
{
}

//�`��
void Enemy_Base::onDraw() const
{
}

//�Փ˂���
void Enemy_Base::onCollide(Actor& other)
{
}