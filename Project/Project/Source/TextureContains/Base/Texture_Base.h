#ifndef TEXTURE_BASE_H_
#define TEXTURE_BASE_H_

#include "../ITexture.h"
#include <iostream>

#include "../../Base/GameManagerContains/IGameManagerPtr.h"

class Texture2DParameter;

class Texture_Base :public ITexture
{
public:
	//コンストラクタ
	Texture_Base(
		std::string texName,
		IGameManagerPtr gameManager);
	//初期化
	virtual void Initialize() = 0;
	//更新
	virtual void Update(float deltaTime) = 0;
	//描画
	virtual void Draw() = 0;
	//終了
	virtual void Finalize() = 0;

protected:
	unsigned int m_TexID;
	IGameManagerPtr p_GameManager;
	Texture2DParameter* p_Parameter;
};

#endif // !TEXTURE_BASE_H_
