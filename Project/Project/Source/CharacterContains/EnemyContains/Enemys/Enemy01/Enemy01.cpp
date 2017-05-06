#include "Enemy01.h"
#include "../../../../ActorContains/ActorName.h"
#include "../../../../TextureContains/Texture/Texture.h"
#include "../../../../Base/GameManagerContains/IGameManager.h"

//�R���X�g���N�^
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

//�X�V
void Enemy01::onUpdate(float deltaTime) {

}

//�`��
void Enemy01::onDraw() const {

}

//�Փ˂���
void Enemy01::onCollide(Actor& other) {

}