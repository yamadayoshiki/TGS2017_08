#ifndef PLAYERSTATE_DEAD_H_
#define PLAYERSTATE_DEAD_H_

#include"../../PlayerState.h"

class PlayerState_Dead:public PlayerState 
{
public:
	//�R���X�g���N�^
	PlayerState_Dead(const Player_WPtr& player, IGameManagerPtr gameManager);
	//�e��ԓƎ��̏�����
	virtual void unique_init()override;
	//�X�V����
	virtual void update(float deltaTaime)override;
	//�Փ˔���
	virtual void collide(const Actor& other, const Body::ContactSet& contactSet)override{}
	//�I������
	virtual void end()override;
	//���͏���
	virtual void input() override{}
};
#endif // !PLAYERSTATE_DEAD_H_
