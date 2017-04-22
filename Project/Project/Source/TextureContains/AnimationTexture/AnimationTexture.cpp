#include "AnimationTexture.h"
#include "../../Utility/Animation/Animation.h"

//�R���X�g���N�^
AnimationTexture::AnimationTexture(
	const std::string& texName,
	Renderer2DPtr renderer,
	Animation* animation)
	:Texture_Base(texName, renderer)
	, p_Animation(animation) {
}

//������
void AnimationTexture::OnInitialize() {
}

//�X�V
void AnimationTexture::Update(float deltaTime) {
	//�A�j���[�V�����̍X�V
	p_Animation->Update(deltaTime);
	//�`���`�̍X�V
	p_Parameter->SetRect(*(p_Animation->GetCurrentRect()));
}

//�I��
void AnimationTexture::OnFinalize() {
	delete p_Animation;
}