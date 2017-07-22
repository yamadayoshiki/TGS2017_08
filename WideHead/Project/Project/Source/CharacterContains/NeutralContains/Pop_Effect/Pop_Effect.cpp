#include "Pop_Effect.h"
#include"../../../Base/GameManagerContains/GameManager/GameManager.h"
#include"../../../Utility/Rederer2D/Renderer2D.h"
#include"../../../ActorContains/Transform/Transform.h"
#include"../../../Utility/Texture2DParameter/Texture2DParameter.h"
Pop_Effect::Pop_Effect(
	IWorld * world,
	const GSvector2 & position,
	IGameManagerPtr gameManager)
	:Actor(
		world,
		ActorName::Explosion,
		position,
		gameManager,
		std::make_shared<AnimationTexture>("Pop", p_GameManager->GetDrawManager(), DrawOrder::Effect_Front, 64, 3)) {
}

//�f�X�g���N�^
Pop_Effect::~Pop_Effect() {
}

//������
void Pop_Effect::onInitialize() {
	p_Texture->GetParameter()->m_Center = { 32.0f,32.0f };
}

//�X�V����
void Pop_Effect::onUpdate(float deltaTime)
{
	if (p_Texture->GetLoopCount() >= 1) {
		//���S
		dead();
	}
}

//�`�揈��
void Pop_Effect::onDraw()const {
}
