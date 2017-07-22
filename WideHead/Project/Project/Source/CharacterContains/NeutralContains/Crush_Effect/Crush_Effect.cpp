#include "Crush_Effect.h"
#include"../../../Base/GameManagerContains/GameManager/GameManager.h"
#include"../../../Utility/Rederer2D/Renderer2D.h"
#include"../../../ActorContains/Transform/Transform.h"
#include "../../../Utility/Texture2DParameter/Texture2DParameter.h"

//�R���X�g���N�^
Crush_Effect::Crush_Effect(IWorld * world, const GSvector2 & position, IGameManagerPtr gameManager)
	:Actor(world, ActorName::Crush, position, gameManager, std::make_shared<AnimationTexture>("Crush", gameManager->GetDrawManager(), DrawOrder::Effect_Front, 32, 3)) {
}

//�f�X�g���N�^
Crush_Effect::~Crush_Effect() {
}

//������
void Crush_Effect::onInitialize() {
	p_Texture->GetParameter()->m_Center = { 16.0f,16.0f };
}

//�X�V����
void Crush_Effect::onUpdate(float deltaTime)
{
	if (p_Texture->GetLoopCount() >= 1) {
		//���S
		dead();
	}
}

//�`�揈��
void Crush_Effect::onDraw()const {

}