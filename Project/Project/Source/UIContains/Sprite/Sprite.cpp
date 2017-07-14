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
	// �摜�̏�����
	texture->Initialize();
	// �摜�̍��W�̎w��
	texture->GetParameter()->m_Position = position;
	// �摜�̒��S�̎w��
	texture->GetParameter()->m_Center = { texture->GetParameter()->m_Rect.right / 2,texture->GetParameter()->m_Rect.bottom / 2 };
}

// �X�V����
void Sprite::onUpdate(float deltaTime) {
	// �摜�̍X�V
	p_Texture->Update(deltaTime);
}

// �`�揈��
void Sprite::onDraw() const {
}

