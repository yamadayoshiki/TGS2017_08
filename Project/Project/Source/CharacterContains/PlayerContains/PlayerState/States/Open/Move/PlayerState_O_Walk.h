#ifndef PLAYERSTATE_O_WALK_H_
#define PLAYERSTATE_O_WALK_H_

#include"PlayerState_O_MoveBase.h"

class PlayerState_O_Walk:public PlayerState_O_MoveBase
{
public:
	//�R���X�g���N�^
	PlayerState_O_Walk(const Player_WPtr& player, IGameManagerPtr gameManager);
	//�e��ԓƎ��̏�����
	virtual void onUniqueInit()override;
	//�X�V����
	virtual void onUpdate(float deltaTime) override;
	//�Փˏ���
	virtual void onCollide(const Actor& other, const Body::ContactSet& contactSet) override {}
	//�I������
	virtual void onEnd() override {}
	//���͏���
	virtual void onInput() override {}

};
#endif // !PLAYERSTATE_O_WALK_H_

