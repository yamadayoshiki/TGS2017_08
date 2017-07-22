#ifndef PLAYERSTATE_CRUSH_H_
#define PLAYERSTATE_CRUSH_H_

#include"../../PlayerState.h"

class PlayerState_Crush :public PlayerState
{
public:
	//�R���X�g���N�^
	PlayerState_Crush(const Player_WPtr& player, IGameManagerPtr gameManager);
	//�e��ԓƎ��̏�����
	virtual void unique_init()override;
	//�X�V����
	virtual void update(float deltaTime)override;
	//�Փ˔���
	virtual void collide(const Actor& other, const Body::ContactSet& contactSet)override;
	//�I������
	virtual void end()override {}
	//���͏���
	virtual void input() override {}
	//���b�Z�[�W����
	virtual void handleMessage(EventMessage massege, void* param)override;
};
#endif // !PLAYERSTATE_CRUSH_H_