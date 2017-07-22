#ifndef PLAYERSTATE_CRUSH_AFTER_H_
#define PLAYERSTATE_CRUSH_AFTER_H_

#include"../../PlayerState.h"

class PlayerState_Crush_After :public PlayerState
{
public:
	//�R���X�g���N�^
	PlayerState_Crush_After(const Player_WPtr& player, IGameManagerPtr gameManager);
	//�e��ԓƎ��̏�����
	virtual void unique_init()override;
	//�X�V����
	virtual void update(float deltaTime)override;
	//�Փ˔���
	virtual void collide(const Actor& other, const Body::ContactSet& contactSet)override {}
	//�I������
	virtual void end()override {}
	//���͏���
	virtual void input() override {}

private:
	//�t���[���J�E���^�[
	float m_FrameCounter{ 0.0f };
};
#endif // !PLAYERSTATE_CRUSH_AFTER_H_
