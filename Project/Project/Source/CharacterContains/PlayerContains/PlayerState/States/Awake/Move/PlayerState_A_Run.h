#ifndef PLAYERSTATE_A_RUN_H_
#define PLAYERSTATE_A_RUN_H_

#include"PlayerState_A_MoveBase.h"

class PlayerState_A_Run:public PlayerState_A_MoveBase
{
public:
	//�R���X�g���N�^
	PlayerState_A_Run(GSvector2& position, GSmatrix4& matrix, IGameManager* gameManager);
	//�e��ԓƎ��̏�����
	virtual void onUniqueInit(Actor& actor)override;
	//�X�V����
	virtual void onUpdate(Actor& actor, float deltaTime) override;
	//�Փˏ���
	virtual void onCollide(const Actor& other) override {}
	//�I������
	virtual void onEnd() override {}
	//���͏���
	virtual void onInput() override {}
};
#endif // !PLAYERSTATE_A_RUN_H_
