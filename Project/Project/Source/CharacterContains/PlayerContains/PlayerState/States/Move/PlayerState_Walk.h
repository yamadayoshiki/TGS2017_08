#ifndef PLAYERSTATE_WALK_H_
#define PLAYERSTATE_WALK_H_

#include"PlayerState_MoveBase.h"

//�����̏��
class PlayerState_Walk:public PlayerState_MoveBase
{
public:
	//�R���X�g���N�^
	PlayerState_Walk(GSvector2& pos);
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
#endif // !PLAYERSTATE_WALK_H_

