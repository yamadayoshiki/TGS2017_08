#ifndef ANIMATIONTEXTURE_H_
#define ANIMATIONTEXTURE_H_

#include "../Base/Texture_Base.h"
class GameManager;
class Animation;

class AnimationTexture :public Texture_Base
{
public:
	//�R���X�g���N�^
	AnimationTexture(
		const std::string& texName,
		Renderer2D* renderer,
		Animation* animation);
	//�X�V
	virtual void Update(float deltaTime) override;

protected:
	//�e��ŗL�̏�����
	virtual void OnInitialize() override;
	//�e��ŗL�̏I������
	virtual void OnFinalize() override;

protected:
	Animation* p_Animation;
};

#endif // !ANIMATIONTEXTURE_H_
