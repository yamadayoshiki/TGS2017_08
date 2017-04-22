#ifndef NULLTEXTURE_H_
#define NULLTEXTURE_H_

#include "../Base/Texture_Base.h"

class NullTexture :public Texture_Base
{
public:
	//コンストラクタ
	NullTexture(
		const std::string& texName,
		Renderer2DPtr renderer)
		:Texture_Base(texName, renderer) {}
	//デフォルトコンストラクタ
	NullTexture() :Texture_Base() {}
	//更新
	virtual void Update(float deltaTime) override {}

protected:
	//各種固有の初期化
	virtual void OnInitialize() override {}
	//各種固有の終了処理
	virtual void OnFinalize() override {}
};

#endif // !NULLTEXTURE_H_
