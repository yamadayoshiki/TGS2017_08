#include "Sprite.h"
#include "../../Utility/Rederer2D/Renderer2D.h"
#include "../../Utility/Texture2DParameter/Texture2DParameter.h"
// コンストラクタ
Sprite::Sprite(
	IWorld * world,
	const IGameManagerPtr & gameManager,
	const GSvector2& position,
	const ITexturePtr & texture)
	: UI_Base(
		world,
		ActorName::UI_Sprite,
		position,
		gameManager,
		texture) {
}

// 更新処理
void Sprite::onUpdate(float deltaTime) {
}

// 描画処理
void Sprite::onDraw() const {
}

