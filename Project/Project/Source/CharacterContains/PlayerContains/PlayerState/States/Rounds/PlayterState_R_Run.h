#ifndef PLAYERSTATE_R_RUN_H_
#define PLAYERSTATE_R_RUN_H_

#include"PlayerState_R_MoveBase.h"

class PlayerState_R_Run :public PlayerState_R_MoveBase
{
public:
	//�R���X�g���N�^
	PlayerState_R_Run(GSvector2& position, GSmatrix4& matrix, const PlayerPtr& player, IGameManagerPtr gameManager);
	//�e��ԓƎ��̏�����
	virtual void onUniqueInit()override;
	//�X�V����
	virtual void onUpdate(float deltaTime) override;
	//�Փˏ���
	virtual void onCollide(const Actor& other) override {}
	//�I������
	virtual void onEnd() override {}
	//���͏���
	virtual void onInput() override {}
};
#endif // !PLAYERSTATE_R_RUN_H_
