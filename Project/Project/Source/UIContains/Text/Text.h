#pragma once

#include "../Base/UI_Base.h"

// Spriteクラス
class Text : public UI_Base {
public:
	// コンストラクタ
	Text(IWorld* world, const IGameManagerPtr& gameManager, const GSvector2& position, const ITexturePtr& texture = std::make_shared<NullTexture>());

private:
	// 更新処理
	virtual void onUpdate(float deltaTime)override;
	// 描画処理
	virtual void onDraw()const override;
};
