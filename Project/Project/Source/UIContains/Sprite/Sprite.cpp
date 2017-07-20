#include "Sprite.h"
#include "../../Utility/Rederer2D/Renderer2D.h"
#include "../../Utility/Texture2DParameter/Texture2DParameter.h"
// コンストラクタ
Sprite::Sprite(
	IWorld * world,
	const IGameManagerPtr & gameManager,
	const DrawOrder drawOrder,
	const GSvector2& position,
	const ITexturePtr & texture,
	const std::string& usage)				//用途
	: UI_Base(
		world,
		ActorName::UI_Sprite,
		position,
		gameManager,
		drawOrder,
		texture)
	, m_Usage(usage) {
}

void Sprite::ChangeDisplayMode(const DisplayMode mode) {
	p_Texture->ChangeDisplayMode(mode);
}

std::string Sprite::GetUsage() const {
	return m_Usage;
}

