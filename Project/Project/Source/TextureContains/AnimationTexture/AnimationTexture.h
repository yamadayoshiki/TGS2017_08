#ifndef ANIMATIONTEXTURE_H_
#define ANIMATIONTEXTURE_H_

#include "../Base/Texture_Base.h"

//先行宣言
class Animation;

//アニメーションテクスチャ
class AnimationTexture :public Texture_Base
{
public:
	//コンストラクタ
	AnimationTexture(
		const std::string& texName,
		const Renderer2DPtr& renderer,
		Animation* animation);
	//デストラクタ
	~AnimationTexture();
	//更新
	virtual void Update(float deltaTime) override;
	//ループ回数の取得
	unsigned int GetLoopCount();


protected:
	//各種固有の初期化
	virtual void OnInitialize() override;

protected:
	Animation* p_Animation;
};

#endif // !ANIMATIONTEXTURE_H_
