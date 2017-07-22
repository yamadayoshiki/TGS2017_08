#pragma once

#include "../Base/UI_Base.h"

// Spriteクラス
class Sprite : public UI_Base {
public:
	// コンストラクタ
	Sprite(
		IWorld* world,
		const IGameManagerPtr& gameManager,
		const DrawOrder drawOrder,
		const GSvector2& position,
		const ITexturePtr& texture,
		const std::string& usage);				//用途

public:
	void ChangeDisplayMode(const DisplayMode mode) override;

public:
	//用途の取得
	std::string GetUsage() const;

private:
	std::string m_Usage;								//用途
};