#include "Neutral_Explosion.h"
#include"../../../Base/GameManagerContains/GameManager/GameManager.h"
#include"../../../Utility/Rederer2D/Renderer2D.h"
#include"../../../ActorContains/Transform/Transform.h"
#include"../../../Utility/Texture2DParameter/Texture2DParameter.h"
//�R���X�g���N�^
Neutral_Explosion::Neutral_Explosion(
	IWorld* world,
	const GSvector2& position,
	IGameManagerPtr gameManager)
	:Actor(
		world,
		ActorName::Explosion,
		position,
		gameManager,
		std::make_shared<AnimationTexture>("Explosion", gameManager->GetDrawManager(), DrawOrder::Effect_Front, 64, 1)) {
}

//�f�X�g���N�^
Neutral_Explosion::~Neutral_Explosion() {
}

//������
void Neutral_Explosion::onInitialize() {
	p_Texture->GetParameter()->m_Center = { 32.0f,32.0f };
}

//�X�V����
void Neutral_Explosion::onUpdate(float deltaTime)
{
	if (p_Texture->GetLoopCount() >= 1) {
		//���S
		dead();
	}
}

//�`�揈��
void Neutral_Explosion::onDraw()const {
}