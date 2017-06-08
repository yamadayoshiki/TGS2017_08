#ifndef PLAYERSTATE_SWICH_H_
#define PLAYERSTATE_SWICH_H_

#include"../../PlayerState.h"

class PlayerState_Swich : public PlayerState
{
public:
	//�R���X�g���N�^
	PlayerState_Swich(const Player_WPtr& player, IGameManagerPtr gameManager);
	//�e��ԓƎ��̏�����
	virtual void unique_init()override;
	//�X�V����
	virtual void update(float deltaTaime)override;
	//�Փ˔���
	virtual void collide(const Actor& other)override;
	//�I������
	virtual void end()override {}
	//���b�Z�[�W����
	virtual void handleMessage(EventMessage message, void* param)override;
private:
	bool		m_Flag;
};
#endif // !PLAYERSTATE_SWICH_H_