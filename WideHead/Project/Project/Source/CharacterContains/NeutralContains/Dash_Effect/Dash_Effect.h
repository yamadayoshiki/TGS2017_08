#ifndef DASH_EFFECT_H_
#define DASH_EFFECT_H_

#include "../../../ActorContains/Actor/Actor.h"
#include"../../../WorldContains/IWorld.h"
#include"../../../TextureContains/AnimationTexture/AnimationTexture.h"
#include"../../../Utility/Animation/Animation.h"
#include"../../../CharacterContains/PlayerContains/Player/PlayerPtr.h"


class Dash_Effect :public Actor
{
public:
	//�R���X�g���N�^
	Dash_Effect(
		IWorld* world,
		const GSvector2& position,
		const GSvector2& endposition,
		IGameManagerPtr gameManager,
		const Player_WPtr& player);
	//�f�X�g���N�^
	~Dash_Effect();
	//������
	virtual void onInitialize()override;
	//�X�V����
	virtual void onUpdate(float deltaTime)override;
	//�`�揈��
	virtual void onDraw()const override;
	//�Փ˔���
	virtual void onCollide(Actor& other, const Body::ContactSet& contactSet)override;

private:
	Player_WPtr	p_Player;

	GSvector2 m_EndPosition;

	float m_Speed;
};
#endif // !DASH_EFFECT_H_
