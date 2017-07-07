#ifndef SMORK_EFFECT_H_
#define SMORK_EFFECT_H_


#include"../../../ActorContains/Actor/Actor.h"
#include"../../../WorldContains/IWorld.h"
#include"../../../TextureContains/AnimationTexture/AnimationTexture.h"
#include"../../../Utility/Animation/Animation.h"

class Renderer2D;

class Smork_Effect :public Actor
{
public:
	//�R���X�g���N�^
	Smork_Effect(
		IWorld* world,
		const GSvector2& position,
		IGameManagerPtr gameManager);
	//�f�X�g���N�^
	~Smork_Effect();
	//������
	virtual void initialize()override;
	//�X�V����
	virtual void onUpdate(float deltaTime)override;
	//�`�揈��
	virtual void onDraw()const override;
	//�Փ˔���
	virtual void onCollide(Actor& other)override {}

private:
	//�����_���[
	Renderer2DPtr			p_Renderer;
	AnimationTexture*		p_AnimationTexture;
};
#endif // !SMORK_EFFECT_H_
