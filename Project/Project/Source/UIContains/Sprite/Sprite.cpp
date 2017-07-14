#include "Sprite.h"
#include "../../Utility/Rederer2D/Renderer2D.h"
#include "../../Utility/Texture2DParameter/Texture2DParameter.h"
// �R���X�g���N�^
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

// �X�V����
void Sprite::onUpdate(float deltaTime) {
}

// �`�揈��
void Sprite::onDraw() const {
}

