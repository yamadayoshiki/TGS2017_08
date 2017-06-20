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
		IGameManagerPtr gameManager);
	//�f�X�g���N�^
	~Respawn();
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
#endif // !RESPAWM_H_
