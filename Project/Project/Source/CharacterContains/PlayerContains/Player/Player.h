#ifndef PLAYER_H_
#define PLAYER_H_

#include"../../../ActorContains/Actor/Actor.h"
#include"../PlayerState/PlayerStateManager.h"
#include"../../../WorldContains/IWorld.h"

class Player :public Actor
{
public:
	//�R���X�g���N�^
	Player(IWorld& world,const GSvector2& pos);
	//�f�X�g���N�^
	~Player();
	//�X�V����
	virtual void onUpdate(float deltaTime)override;
	//�`�揈��
	virtual void onDraw()const override;
	//�Փ˔���
	virtual void onCollide(Actor& other)override;

private:
	//��ԊǗ�
	PlayerStateManager* mStateManager;
};
#endif // !PLAYER_H_
