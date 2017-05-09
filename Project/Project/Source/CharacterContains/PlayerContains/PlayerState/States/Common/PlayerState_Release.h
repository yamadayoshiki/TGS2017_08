#ifndef PLAYERSTATE_RELEASE_H_
#define PLAYERSTATE_RELEASE_H_

#include"../../PlayerState.h"

class PlayerState_Release:public PlayerState
{
public:
	//�R���X�g���N�^
	PlayerState_Release(GSvector2& position, GSmatrix4& matrix, const PlayerPtr& player, IGameManagerPtr gameManager);
	//�e��ԓƎ��̏�����
	virtual void unique_init()override;
	//�X�V����
	virtual void update(float deltaTaime)override;
	//�Փ˔���
	virtual void collide(const Actor& other)override;
	//�I������
	virtual void end()override {}
};
#endif // !PLAYERSTATE_RELEASE_H_

