#ifndef PLAYERSTATE_IDOL_H_
#define PLAYERSTATE_IDOL_H_

#include"PlayerState_MoveBase.h"

//�ҋ@(�ʏ�)���
class PlayerState_Idol:public PlayerState_MoveBase
{
public:
	//�R���X�g���N�^
	PlayerState_Idol(GSvector2& pos);
	//�e��ԓƎ��̏�����
	virtual void onUniqueInit(Actor& actor)override;
	//�X�V����
	virtual void onUpdate(Actor& actor,float deltaTime){}
	//�Փˏ���
	virtual void onCollide(Actor& other){}
	//�I������
	virtual void onEnd(){}
	//���͏���
	virtual void onInput(){}
};
#endif // !PLAYERSTATE_IDOL_H_

