#ifndef PLAYERSTATE_ROUND_H_
#define PLAYERSTATE_ROUND_H_

#include"../../PlayerState.h"

class PlayerState_Round :public PlayerState
{
public:
	//�R���X�g���N�^
	PlayerState_Round(GSvector2& position, GSmatrix4& matirx, const PlayerPtr& player, IGameManagerPtr gameManager);
	//�e��ԓƎ��̏�����
	virtual void unique_init()override;
	//�X�V����
	virtual void update(float deltaTime)override;
	//�Փ˔���
	virtual void collide(const Actor& other)override;
	//�I������
	virtual void end()override;
	//���͏���
	virtual void input() override;
};
#endif // !PLAYERSTATE_ROUND_H_
