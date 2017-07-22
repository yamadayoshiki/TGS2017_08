#include "AnimationTexture.h"
#include "../../Utility/Animation/Animation.h"
#include "../../Utility/Texture2DParameter/Texture2DParameter.h"

//コンストラクタ
AnimationTexture::AnimationTexture(
	const std::string & texName,
	const DrawManagerSPtr & drawManager,
	const DrawOrder drawOrder,
	const float cutWidth,
	const unsigned int animmationUpdateTimer)
	: Texture_Base(texName, drawManager, drawOrder) {
	p_Animation = std::make_shared<Animation>(p_Parameter->m_Rect, cutWidth, animmationUpdateTimer);
	p_Parameter->m_Center = GSvector2(cutWidth / 2, p_Parameter->m_Rect.bottom / 2);
}

AnimationTexture::AnimationTexture(const std::string & texName, const DrawManagerSPtr & drawManager, const DrawOrder drawOrder)
	: Texture_Base(texName, drawManager, drawOrder) {
}

//デストラクタ
AnimationTexture::~AnimationTexture() {
}

//初期化
void AnimationTexture::OnInitialize() {
	p_Animation->Initialize();
	p_Parameter->m_Rect = *p_Animation->GetCurrentRect();
}

//更新
void AnimationTexture::OnUpdate(float deltaTime) {
	//アニメーションの更新
	p_Animation->Update(deltaTime);
	//描画矩形の更新
	p_Parameter->m_Rect = *(p_Animation->GetCurrentRect());
}

//ループ回数の取得
int AnimationTexture::GetLoopCount() {
	return p_Animation->GetLoopCount();
}

//アニメーションの取得
AnimationSPtr AnimationTexture::GetAnimation() {
	return p_Animation;
}

ITexturePtr AnimationTexture::Clone(const DrawOrder drawOrder) {
	std::shared_ptr<AnimationTexture> result = std::make_shared<AnimationTexture>(m_TexName, p_DrawManager.lock(), drawOrder);
	result->p_Animation = p_Animation->Clone();
	result->p_Parameter->Copy(p_Parameter);
	result->m_StopFlag = m_StopFlag;
	return result;
}
