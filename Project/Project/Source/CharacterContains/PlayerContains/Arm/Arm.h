#ifndef ARM_H_
#define ARM_H_

#include"../../../ActorContains/Actor/Actor.h"
#include"../../../WorldContains/IWorld.h"

class Arm:public Actor
{
public:
	//�R���X�g���N�^
	Arm(IWorld* world, GSvector2& position,IGameManagerPtr gameManager);
	//�f�X�g���N�^
	~Arm();
	//�X�V����
	virtual void onUpdate(float deltaTime)override;
	//�`�揈��
	virtual void onDraw()const override;
	//�Փ˔���
	virtual void onCollide(Actor& other, const Body::ContactSet& contactSet)override;
	//�Փ˔���
	//bool isCollide(const Actor& other);

private:
	//��]
	float		m_Angle;
	//
	bool		mHitFlag {false};
};
#endif // !ARM_H_
