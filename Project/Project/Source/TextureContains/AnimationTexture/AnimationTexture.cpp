#include "AnimationTexture.h"
#include "../../Utility/Animation/Animation.h"

//コンストラクタ
AnimationTexture::AnimationTexture(
	const std::string& texName,
	Renderer2DPtr renderer,
	Animation* animation)
	:Texture_Base(texName, renderer)
	, p_Animation(animation) {
}

//初期化
void AnimationTexture::OnInitialize() {
}

//更新
void AnimationTexture::Update(float deltaTime) {
	//アニメーションの更新
	p_Animation->Update(deltaTime);
	//描画矩形の更新
	p_Parameter->SetRect(*(p_Animation->GetCurrentRect()));
}

//終了
void AnimationTexture::OnFinalize() {
	delete p_Animation;
}