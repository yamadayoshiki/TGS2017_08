#ifndef TEXTURE_H_
#define TEXTURE_H_

#include "../Base/Texture_Base.h"

class Texture :public Texture_Base
{
public:
	//コンストラクタ
	Texture(
		const std::string& texName,
		const DrawManagerSPtr& drawManager,
		const DrawOrder drawOrder);
	//ループ回数の取得
	int GetLoopCount() override { return 0; }
	//クローン生成
	virtual ITexturePtr Clone(const DrawOrder drawOrder) override;

public:
	//テクスチャ交換
	void ChangeTexture(const std::string& texName, const DrawOrder drawOrder);
};

#endif // !TEXTURE_H_