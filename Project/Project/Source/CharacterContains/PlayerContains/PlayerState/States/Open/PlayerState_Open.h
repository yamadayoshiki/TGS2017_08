#ifndef PLAYERSTATE_OPEN_H_
#define PLAYERSTATE_OPEN_H_

#include"../../PlayerState.h"

//�A�[�����
class PlayerState_Open:public  PlayerState
{
public:
	//�R���X�g���N�^
	PlayerState_Open(GSvector2& positon,GSmatrix4& matrix,IGameManagerPtr gameManager);
	//�e��ԓƎ��̏�����
	virtual void unique_init(Actor& actor)override;
	//�X�V����
	virtual void update(Actor& actor, float deltaTaime)override;
	//�Փ˔���
	virtual void collide(const Actor& other)override;
	//�I������
	virtual void end()override;
};
#endif // !PLAYERSTATE_OPEN_H_
