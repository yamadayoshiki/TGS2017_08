#ifndef PLAYER_STATE_MOVEBASE_H_
#define PLAYER_STATE_MOVEBASE_H_

#include"../../../PlayerState.h"
#include"../../../PlayerStateName.h"

//�ړ��N���X�̃x�[�X
class PlayerState_MoveBase :public PlayerState
{
public:
	//�R���X�g���N�^
	PlayerState_MoveBase(const Player_WPtr& player, IGameManagerPtr gameManager);
	//�e��ԓƎ��̏�����
	virtual void unique_init()override;
	//�X�V����
	virtual void update(float deltaTaime)override;
	//�Փ˔���
	virtual void collide(const Actor& other, const Body::ContactSet& contactSet)override;
	//�I������
	virtual void end()override;
	//���͏���
	virtual void input() override;

protected:
	//�e��Ԃ̏�����
	virtual void onUniqueInit() = 0;
	// �X�V����
	virtual void onUpdate(float deltaTime) = 0;
	// �Փ˔���
	virtual void onCollide(const Actor & other, const Body::ContactSet& contactSet) = 0;
	// �I�����̏���
	virtual void onEnd() = 0;
	// ���͏���
	virtual void onInput() = 0;
};

#endif // !PLAYER_STATE_MOVEBASE_H_

