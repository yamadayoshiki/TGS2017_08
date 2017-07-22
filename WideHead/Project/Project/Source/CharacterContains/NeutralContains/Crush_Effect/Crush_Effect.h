#ifndef CRUSH_EFFECT_H_
#define CRUSH_EFFECT_H_

#include "../../../ActorContains/Actor/Actor.h"
#include"../../../WorldContains/IWorld.h"
#include"../../../TextureContains/AnimationTexture/AnimationTexture.h"
#include"../../../Utility/Animation/Animation.h"

class Renderer2D;

class Crush_Effect :public Actor
{
public:
	//�R���X�g���N�^
	Crush_Effect(
		IWorld* world,
		const GSvector2& position,
		IGameManagerPtr gameManager);
	//�f�X�g���N�^
	~Crush_Effect();
	//������
	virtual void onInitialize()override;
	//�X�V����
	virtual void onUpdate(float deltaTime)override;
	//�`�揈��
	virtual void onDraw()const override;
	//�Փ˔���
	virtual void onCollide(Actor& other, const Body::ContactSet& contactSet)override {}
};
#endif // !CRUSH_EFFECT_H_
