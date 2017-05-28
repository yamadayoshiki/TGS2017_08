#include "Sprite.h"

#include "../../Utility/Rederer2D/Renderer2D.h"

// コンストラクタ
Sprite::Sprite(IWorld * world, const IGameManagerPtr & gameManager, const GSvector2& position, const ITexturePtr & texture) :
	UI_Base(world, ActorName::UI_Sprite, position, gameManager, texture) {
	// 画像の初期化
	texture->Initialize();
	// 画像の座標の指定
	texture->GetParameter()->SetPosition(position);
	// 画像の中心の指定
	texture->GetParameter()->SetCenter(texture->GetParameter()->GetSize() / 2);
}

// 更新処理
void Sprite::onUpdate(float deltaTime){
	// 画像の更新
	p_Texture->Update(deltaTime);
}

// 描画処理
void Sprite::onDraw() const{
	// 画像の描画
	p_Texture->Draw();
}

