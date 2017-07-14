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
	// 画像の初期化
	texture->Initialize();
	// 画像の座標の指定
	texture->GetParameter()->m_Position = position;
	// 画像の中心の指定
	texture->GetParameter()->m_Center = { texture->GetParameter()->m_Rect.right / 2,texture->GetParameter()->m_Rect.bottom / 2 };
}

// 更新処理
void Sprite::onUpdate(float deltaTime) {
	// 画像の更新
	p_Texture->Update(deltaTime);
}

// 描画処理
void Sprite::onDraw() const {
}

