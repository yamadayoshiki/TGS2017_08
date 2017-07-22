#ifndef TEXTURE2DPARAMFACTORY_H_
#define TEXTURE2DPARAMFACTORY_H_
#include <iostream>
#include "../Texture2DParameterPtr.h"
#include "../../Rederer2D/Renderer2DPtr.h"
//2Dテクスチャ工場
class Texture2DParamFactory
{
public:
	//コンストラクタ
	Texture2DParamFactory(const Renderer2DPtr& renderer);
	//デストラクタ
	~Texture2DParamFactory();
	//パラメータの取得
	Texture2DParameter* GetDefaultTexture2DParam(
		const std::string texName);

private:
	Renderer2DPtr p_Renderer;	//レンダラー
};
#endif // !TEXTURE2DPARAMFACTORY_H_