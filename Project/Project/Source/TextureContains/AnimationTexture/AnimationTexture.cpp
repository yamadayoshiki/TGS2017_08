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

//デストラクタ
AnimationTexture::~AnimationTexture() {
	p_Animation.reset();
}

//初期化
void AnimationTexture::Initialize() {
	p_Animation->Initialize();
	p_Parameter->m_Rect = *p_Animation->GetCurrentRect();
}

//更新
void AnimationTexture::Update(float deltaTime) {
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
