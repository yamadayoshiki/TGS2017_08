#ifndef PLAYERSTATE_A_IDOL_H_
#define PLAYERSTATE_A_IDOL_H_

#include"PlayerState_A_MoveBase.h"

class PlayerState_A_Idol:public PlayerState_A_MoveBase
{
public:
	//�R���X�g���N�^
	PlayerState_A_Idol(GSvector2& position, GSmatrix4& matrix, IGameManager* gameManager);
	//�e��ԓƎ��̏�����
	virtual void onUniqueInit(Actor& actor)override;
	//�X�V����
	virtual void onUpdate(Actor& actor, float deltaTime) {}
	//�Փˏ���
	virtual void onCollide(const Actor& other)override {}
	//�I������
	virtual void onEnd()override {}
	//���͏���
	virtual void onInput()override {}
};
#endif // !PLAYERSTATE_A_IDOL_H_
