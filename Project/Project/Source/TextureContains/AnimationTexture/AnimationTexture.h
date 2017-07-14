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
	//デストラクタ
	~AnimationTexture();
	//初期化
	virtual void Initialize() override;
	//更新
	virtual void Update(float deltaTime) override;

public:
	//ループ回数の取得
	int GetLoopCount() override;
	//アニメーションの取得
	AnimationSPtr GetAnimation();

protected:
	AnimationSPtr p_Animation;	//アニメーション
};

#endif // !ANIMATIONTEXTURE_H_
