#include "Sprite.h"
#include "../../Utility/Rederer2D/Renderer2D.h"
#include "../../Utility/Texture2DParameter/Texture2DParameter.h"
// �R���X�g���N�^
Sprite::Sprite(
	IWorld * world,
	const IGameManagerPtr & gameManager,
	const DrawOrder drawOrder,
	const GSvector2& position,
	const ITexturePtr & texture,
	const std::string& usage)				//�p�r
	: UI_Base(
		world,
		ActorName::UI_Sprite,
		position,
		gameManager,
		drawOrder,
		texture)
	, m_Usage(usage) {
}

// �X�V����
void Sprite::onUpdate(float deltaTime) {
}

// �`�揈��
void Sprite::onDraw() const {
}

void Sprite::ChangeDisplayMode(const DisplayMode mode) {
	p_Texture->ChangeDisplayMode(mode);
}

std::string Sprite::GetUsage() const {
	return m_Usage;
}

