#include "Enemy03.h"
#include "../../../../ActorContains/ActorName.h"
#include "../../../../TextureContains/Texture/Texture.h"
#include "../../../../Base/GameManagerContains/IGameManager.h"

//�R���X�g���N�^
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

//�X�V
void Enemy03::onUpdate(float deltaTime) {

}

//�`��
void Enemy03::onDraw() const {

}

//�Փ˂���
void Enemy03::onCollide(Actor& other) {

}