#ifndef PLAYERSTATE_WALK_H_
#define PLAYERSTATE_WALK_H_

#include"PlayerState_MoveBase.h"

//�����̏��
class PlayerState_Walk :public PlayerState_MoveBase
{
public:
	//�R���X�g���N�^
	PlayerState_Walk(const Player_WPtr& player, IGameManagerPtr gameManager);
	//�e��ԓƎ��̏�����
	virtual void onUniqueInit()override;
	//�X�V����
	virtual void onUpdate(float deltaTime) override;
	//�Փˏ���
	virtual void onCollide(const Actor& other) override {}
	//�I������
	virtual void onEnd() override {}
	//���͏���
	virtual void onInput() override {}
};
#endif // !PLAYERSTATE_WALK_H_

