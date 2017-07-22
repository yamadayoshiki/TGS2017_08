#include "Neutral_Explosion.h"
#include"../../../Base/GameManagerContains/GameManager/GameManager.h"
#include"../../../Utility/Rederer2D/Renderer2D.h"
#include"../../../ActorContains/Transform/Transform.h"
#include"../../../Utility/Texture2DParameter/Texture2DParameter.h"
//コンストラクタ
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

//デストラクタ
Neutral_Explosion::~Neutral_Explosion() {
}

//初期化
void Neutral_Explosion::onInitialize() {
	p_Texture->GetParameter()->m_Center = { 32.0f,32.0f };
}

//更新処理
void Neutral_Explosion::onUpdate(float deltaTime)
{
	if (p_Texture->GetLoopCount() >= 1) {
		//死亡
		dead();
	}
}

//描画処理
void Neutral_Explosion::onDraw()const {
}