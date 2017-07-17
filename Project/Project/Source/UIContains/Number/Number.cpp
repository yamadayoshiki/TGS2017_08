#include "Number.h"
#include "../../TextureContains/NumberTexture/NumberTexture.h"
Number::Number(
	IWorld * world,
	const IGameManagerPtr & gameManager,
	const DrawOrder drawOrder,
	const ITexturePtr & texture,
	const std::string& usage)
	: UI_Base(
		world,
		ActorName::UI_Number,
		GSvector2(0.0f, 0.0f),
		gameManager,
		drawOrder,
		texture)
	, m_Usage(usage) {
	p_NumberTexture = std::dynamic_pointer_cast<NumberTexture>(p_Texture);
	p_NumberTexture->SetNumber(0);
}

void Number::ChangeDisplayMode(const DisplayMode mode){
	p_NumberTexture->ChangeDisplayMode(mode);
}

std::string Number::GetUsage() const {
	return m_Usage;
}

void Number::SetNum(const int num) {
	p_NumberTexture->SetNumber(num);
}
