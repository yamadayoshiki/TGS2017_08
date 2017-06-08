#ifndef PLAYERSTATE_CLOSE_H_
#define PLAYERSTATE_CLOSE_H_

#include"../../PlayerState.h"

class PlayerState_Close:public PlayerState
{
public:
	//�R���X�g���N�^
	PlayerState_Close(const Player_WPtr& player, IGameManagerPtr gameManager);
	//�e��ԓƎ��̏�����
	virtual void unique_init()override;
	//�X�V����
	virtual void update(float deltaTaime)override;
	//�Փ˔���
	virtual void collide(const Actor& other)override;
	//�I������
	virtual void end()override;
};
#endif // !PLAYERSTATE_CLOSE_H_