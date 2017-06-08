#ifndef PLAYERSTATE_IDLE_H_
#define PLAYERSTATE_IDLE_H_

#include"PlayerState_MoveBase.h"

//�ҋ@(�ʏ�)���
class PlayerState_Idle:public PlayerState_MoveBase
{
public:
	//�R���X�g���N�^
	PlayerState_Idle(const Player_WPtr& player, IGameManagerPtr gameManager);
	//�e��ԓƎ��̏�����
	virtual void onUniqueInit()override;
	//�X�V����
	virtual void onUpdate(float deltaTime){}
	//�Փˏ���
	virtual void onCollide(const Actor& other)override {}
	//�I������
	virtual void onEnd()override {}
	//���͏���
	virtual void onInput()override{}
};
#endif // !PLAYERSTATE_IDLE_H_

