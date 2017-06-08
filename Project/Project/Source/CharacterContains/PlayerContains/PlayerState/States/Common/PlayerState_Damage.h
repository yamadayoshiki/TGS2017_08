#ifndef PLAYERSTATE_DAMAGE_H_
#define PLAYERSTATE_DAMAGE_H_

#include"../../PlayerState.h"

class PlayerState_Damage :public PlayerState
{
public:
	//�R���X�g���N�^
	PlayerState_Damage(const Player_WPtr& player, IGameManagerPtr gameManager);
	//�e��ԓƎ��̏�����
	virtual void unique_init()override;
	//�X�V����
	virtual void update(float deltaTaime)override;
	//�Փ˔���
	virtual void collide(const Actor& other)override;
	//�I������
	virtual void end()override;
	//���͏���
	virtual void input() override;
};
#endif // !PLAYERSTATE_DAMAGE_H_

