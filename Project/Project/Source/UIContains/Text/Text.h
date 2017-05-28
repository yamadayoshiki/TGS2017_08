#pragma once

#include "../Base/UI_Base.h"

// Sprite�N���X
class Text : public UI_Base {
public:
	// �R���X�g���N�^
	Text(IWorld* world, const IGameManagerPtr& gameManager, const GSvector2& position, const ITexturePtr& texture = std::make_shared<NullTexture>());

private:
	// �X�V����
	virtual void onUpdate(float deltaTime)override;
	// �`�揈��
	virtual void onDraw()const override;
};
