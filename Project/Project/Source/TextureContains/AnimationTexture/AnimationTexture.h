#ifndef ANIMATIONTEXTURE_H_
#define ANIMATIONTEXTURE_H_

#include "../Base/Texture_Base.h"

//��s�錾
class Animation;

//�A�j���[�V�����e�N�X�`��
class AnimationTexture :public Texture_Base
{
public:
	//�R���X�g���N�^
	AnimationTexture(
		const std::string& texName,
		const Renderer2DPtr& renderer,
		Animation* animation);
	//�f�X�g���N�^
	~AnimationTexture();
	//�X�V
	virtual void Update(float deltaTime) override;
	//���[�v�񐔂̎擾
	unsigned int GetLoopCount();


protected:
	//�e��ŗL�̏�����
	virtual void OnInitialize() override;

protected:
	Animation* p_Animation;
};

#endif // !ANIMATIONTEXTURE_H_
