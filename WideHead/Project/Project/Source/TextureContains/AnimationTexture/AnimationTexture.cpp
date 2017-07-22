#include "AnimationTexture.h"
#include "../../Utility/Animation/Animation.h"
#include "../../Utility/Texture2DParameter/Texture2DParameter.h"

//�R���X�g���N�^
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

//�f�X�g���N�^
AnimationTexture::~AnimationTexture() {
}

//������
void AnimationTexture::OnInitialize() {
	p_Animation->Initialize();
	p_Parameter->m_Rect = *p_Animation->GetCurrentRect();
}

//�X�V
void AnimationTexture::OnUpdate(float deltaTime) {
	//�A�j���[�V�����̍X�V
	p_Animation->Update(deltaTime);
	//�`���`�̍X�V
	p_Parameter->m_Rect = *(p_Animation->GetCurrentRect());
}

//���[�v�񐔂̎擾
int AnimationTexture::GetLoopCount() {
	return p_Animation->GetLoopCount();
}

//�A�j���[�V�����̎擾
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
