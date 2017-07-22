#ifndef RESPAWM_H_
#define RESPAWN_H_

#include"../../../ActorContains/Actor/Actor.h"
#include"../../../WorldContains/IWorld.h"
#include"../../../TextureContains/AnimationTexture/AnimationTexture.h"
#include"../../../Utility/Animation/Animation.h"

class Respawn :public Actor
{
public:
	//�R���X�g���N�^
	Respawn(IWorld* world,
		const GSvector2& position,
		IGameManagerPtr gameManager,
		const DrawOrder order = DrawOrder::Effect_Front);
	//�f�X�g���N�^
	~Respawn();
	//������
	virtual void onInitialize()override;
	//�X�V����
	virtual void onUpdate(float deltaTime)override;
	//�`�揈��
	virtual void onDraw()const override;
	//�Փ˔���
	virtual void onCollide(Actor& other, const Body::ContactSet& contactSet)override {}
};
#endif // !RESPAWM_H_
