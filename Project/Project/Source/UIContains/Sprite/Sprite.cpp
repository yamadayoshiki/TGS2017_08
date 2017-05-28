#include "Sprite.h"

#include "../../Utility/Rederer2D/Renderer2D.h"

// �R���X�g���N�^
Sprite::Sprite(IWorld * world, const IGameManagerPtr & gameManager, const GSvector2& position, const ITexturePtr & texture) :
	UI_Base(world, ActorName::UI_Sprite, position, gameManager, texture) {
	// �摜�̏�����
	texture->Initialize();
	// �摜�̍��W�̎w��
	texture->GetParameter()->SetPosition(position);
	// �摜�̒��S�̎w��
	texture->GetParameter()->SetCenter(texture->GetParameter()->GetSize() / 2);
}

// �X�V����
void Sprite::onUpdate(float deltaTime){
	// �摜�̍X�V
	p_Texture->Update(deltaTime);
}

// �`�揈��
void Sprite::onDraw() const{
	// �摜�̕`��
	p_Texture->Draw();
}

