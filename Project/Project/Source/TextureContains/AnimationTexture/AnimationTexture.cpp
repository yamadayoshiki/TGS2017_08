#include "AnimationTexture.h"
#include "../../Utility/Animation/Animation.h"

//コンストラクタ
AnimationTexture::AnimationTexture(
	const std::string& texName,
	const Renderer2DPtr& renderer,
	Animation* animation)
	:Texture_Base(texName, renderer)
	, p_Animation(animation) {
}

AnimationTexture::~AnimationTexture(){
	delete p_Animation;
}

//初期化
void AnimationTexture::OnInitialize() {
	p_Parameter->SetRect(*p_Animation->GetCurrentRect());
	p_Animation->Initialize();
}

//更新
void AnimationTexture::Update(float deltaTime) {
	//アニメーションの更新
	p_Animation->Update(deltaTime);
	//描画矩形の更新
	p_Parameter->SetRect(*(p_Animation->GetCurrentRect()));
}

//ループ回数の取得
unsigned int AnimationTexture::GetLoopCount() {
	return p_Animation->GetLoopCount();
}

//テクスチャの名前とアニメーションの設定
void AnimationTexture::setName_Animation(const std::string& name, Animation* animation)
{
	m_TexName = name;
	p_Animation = animation;
	p_Animation->Initialize();
}