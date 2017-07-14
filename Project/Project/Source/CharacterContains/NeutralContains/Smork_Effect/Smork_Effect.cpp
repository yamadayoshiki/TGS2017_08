#include "Smork_Effect.h"
#include"../../../Base/GameManagerContains/GameManager/GameManager.h"
#include"../../../Utility/Rederer2D/Renderer2D.h"
#include"../../../ActorContains/Transform/Transform.h"
#include"../../../Utility/Sound/SoundName.h"
#include "../../../Utility/Texture2DParameter/Texture2DParameter.h"

Smork_Effect::Smork_Effect(
	IWorld * world,
	const GSvector2 & position,
	IGameManagerPtr gameManager)
	:Actor(world, ActorName::Explosion, position, gameManager,
		std::make_shared<AnimationTexture>("BlockBreak", p_GameManager->GetDrawManager(), DrawOrder::UI_Front1, 252, 3)) {
}

//デストラクタ
Smork_Effect::~Smork_Effect() {
}

//初期化
void Smork_Effect::initialize() {
	gsPlaySE(SE_BLOCK_BREAK);
	p_Transform->m_Angle -= 90;
	p_Texture->GetParameter()->m_Center = { 126.0f, 126.0f };
}

//更新処理
void Smork_Effect::onUpdate(float deltaTime)
{
	if (p_Texture->GetLoopCount() >= 1) {
		//死亡
		dead();
	}
}

//描画処理
void Smork_Effect::onDraw()const
{
}
