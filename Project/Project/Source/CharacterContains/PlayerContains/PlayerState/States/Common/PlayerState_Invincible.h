#ifndef PLAYERSTATE_INVINCIBLE_H_
#define PLAYERSTATE_INVINCIBLE_H_

#include"../../PlayerState.h"

class PlayerState_Invincible:public PlayerState
{
public:
	//�R���X�g���N�^
	PlayerState_Invincible(const Player_WPtr& player, IGameManagerPtr gameManager);
	//�e��ԓƎ��̏�����
	virtual void unique_init()override;
	//�X�V����
	virtual void update(float deltaTaime)override;
	//�Փ˔���
	virtual void collide(const Actor& other)override;
	//�I������
	virtual void end()override{}
	//���͏���
	virtual void input() override;

private:
	float		m_FramConter{ 0.0f };
};
#endif // !PLAYERSTATE_INVINCIBLE_H_
