#ifndef ANIMATIONTEXTURE_H_
#define ANIMATIONTEXTURE_H_

#include "../Base/Texture_Base.h"
#include "../../Utility/Animation/AnimationPtr.h"
//�A�j���[�V�����e�N�X�`��
class AnimationTexture :public Texture_Base
{
public:
	//�R���X�g���N�^
	AnimationTexture(
		const std::string& texName,
		const DrawManagerSPtr& drawManager,
		const DrawOrder drawOrder,
		const float cutWidth,
		const unsigned int animmationUpdateTimer);
	//�f�X�g���N�^
	~AnimationTexture();
	//������
	virtual void Initialize() override;
	//�X�V
	virtual void Update(float deltaTime) override;

public:
	//���[�v�񐔂̎擾
	int GetLoopCount() override;
	//�A�j���[�V�����̎擾
	AnimationSPtr GetAnimation();

protected:
	AnimationSPtr p_Animation;	//�A�j���[�V����
};

#endif // !ANIMATIONTEXTURE_H_
