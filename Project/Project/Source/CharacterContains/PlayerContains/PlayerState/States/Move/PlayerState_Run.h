#ifndef PLAYERSTATE_RUN_H_
#define PLAYERSTATE_RUN_H_

#include"PlayerState_MoveBase.h"

//����̏��
class PlayerState_Run :public PlayerState_MoveBase
{
	//�R���X�g���N�^
	PlayerState_Run(GSvector2& pos);
	//�e��ԓƎ��̏�����
	virtual void onUniqueInit(Actor& actor)override;
	//�X�V����
	virtual void onUpdate(Actor& actor, float deltaTime) override;
	//�Փˏ���
	virtual void onCollide(Actor& other) {}
	//�I������
	virtual void onEnd() {}
	//���͏���
	virtual void onInput() {}
};

#endif // !PLAYERSTATE_RUN_H_
