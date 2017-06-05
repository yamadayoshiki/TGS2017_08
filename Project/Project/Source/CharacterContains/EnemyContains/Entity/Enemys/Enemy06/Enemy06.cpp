#include "Enemy06.h"
#include "../../../../../TextureContains/Texture/Texture.h"
#include "../../../../../Base/GameManagerContains/IGameManager.h"
#include "../../../../../Utility/Rederer2D/Renderer2D.h"
#include "../../../../../ActorContains/Body/OrientedBoundingBox.h"

//�R���X�g���N�^
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

//�N���[������
ActorPtr Enemy06::clone(const GSvector2 & position, const FourDirection & front) {
	return std::make_shared<Enemy06>(p_World, position, front, p_GameManager);
}

//�e��ŗL�̃R�}���h�̐ݒ�
void Enemy06::SetUpCommand() {

}

//�e��ŗL��State�̐ݒ�
void Enemy06::SetUpState() {
}

//�`��
void Enemy06::onDraw() const {
}