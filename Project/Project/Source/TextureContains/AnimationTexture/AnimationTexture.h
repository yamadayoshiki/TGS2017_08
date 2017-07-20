#ifndef ANIMATIONTEXTURE_H_
#define ANIMATIONTEXTURE_H_

#include "../Base/Texture_Base.h"
#include "../../Utility/Animation/AnimationPtr.h"
//アニメーションテクスチャ
class AnimationTexture :public Texture_Base
{
public:
	//コンストラクタ
	AnimationTexture(
		const std::string& texName,
		const DrawManagerSPtr& drawManager,
		const DrawOrder drawOrder,
		const float cutWidth,
		const unsigned int animmationUpdateTimer);
	//コンストラクタ
	AnimationTexture(
		const std::string& texName,
		const DrawManagerSPtr& drawManager,
		const DrawOrder drawOrder);
	//デストラクタ
	~AnimationTexture();

public:
	//ループ回数の取得
	int GetLoopCount() override;
	//アニメーションの取得
	AnimationSPtr GetAnimation();
	//クローン生成
	ITexturePtr Clone(const DrawOrder drawOrder) override;

protected:
	//初期化
	void OnInitialize() override;
	//更新
	void OnUpdate(float deltaTime) override;

protected:
	AnimationSPtr p_Animation;	//アニメーション
};

#endif // !ANIMATIONTEXTURE_H_
