#pragma once

#include "../Base/UI_Base.h"

// Sprite�N���X
class Sprite : public UI_Base {
public:
	// �R���X�g���N�^
	Sprite(
		IWorld* world,
		const IGameManagerPtr& gameManager,
		const DrawOrder drawOrder,
		const GSvector2& position,
		const ITexturePtr& texture,
		const std::string& usage);				//�p�r

public:
	void ChangeDisplayMode(const DisplayMode mode) override;

public:
	//�p�r�̎擾
	std::string GetUsage() const;

private:
	std::string m_Usage;								//�p�r
};