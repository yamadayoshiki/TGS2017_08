#ifndef PLAYERSTATE_CLOSE_H_
#define PLAYERSTATE_CLOSE_H_

#include"../../PlayerState.h"

class PlayerState_Close:public PlayerState
{
public:
	//�R���X�g���N�^
	PlayerState_Close(GSvector2& positon, GSmatrix4& matrix, IGameManagerPtr gameManager);
	//�e��ԓƎ��̏�����
	virtual void unique_init(Actor& actor)override;
	//�X�V����
	virtual void update(Actor& actor, float deltaTaime)override;
	//�Փ˔���
	virtual void collide(const Actor& other)override;
	//�I������
	virtual void end()override;
};
#endif // !PLAYERSTATE_CLOSE_H_