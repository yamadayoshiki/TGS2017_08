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

//�f�X�g���N�^
AnimationTexture::~AnimationTexture() {
	p_Animation.reset();
}

//������
void AnimationTexture::Initialize() {
	p_Animation->Initialize();
	p_Parameter->m_Rect = *p_Animation->GetCurrentRect();
}

//�X�V
void AnimationTexture::Update(float deltaTime) {
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
