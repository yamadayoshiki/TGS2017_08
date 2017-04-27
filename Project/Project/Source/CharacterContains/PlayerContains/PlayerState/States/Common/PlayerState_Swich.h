#ifndef PLAYERSTATE_SWICH_H_
#define PLAYERSTATE_SWICH_H_

#include"../../PlayerState.h"

class PlayerState_Swich : public PlayerState
{
public:
	//�R���X�g���N�^
	PlayerState_Swich(GSvector2& position, GSmatrix4& matrix, IGameManagerPtr gameManager);
	//�e��ԓƎ��̏�����
	virtual void unique_init(Actor& actor)override;
	//�X�V����
	virtual void update(Actor& actor, float deltaTaime)override;
	//�Փ˔���
	virtual void collide(const Actor& other)override;
	//�I������
	virtual void end()override{}
private:
	bool		m_Flag{ false };
};
#endif // !PLAYERSTATE_SWICH_H_