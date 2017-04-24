#include "Enemy_Base.h"
#include "../../StateManager/Enemy_StateManager.h"

//�R���X�g���N�^
Enemy_Base::Enemy_Base(
	const IWorldPtr& world,
	const ActorName& name,
	const GSvector2& position,
	const IGameManagerPtr& gameManager,
	const ITexturePtr& texture,
	const IBodyPtr& body)
	: Actor(world, name, position, gameManager, texture, body)
	, p_Enemy_StateManager(new Enemy_StateManager()) {
}

//�X�V
void Enemy_Base::onUpdate(float deltaTime) {

}
//�`��
void Enemy_Base::onDraw() const {

}
//�Փ˂���
void Enemy_Base::onCollide(Actor& other) {

}