#ifndef PLAYERSTATE_O_IDOL_H_
#define PLAYERSTATE_O_IDOL_H_

#include"PlayerState_O_MoveBase.h"

class PlayerState_O_Idol:public PlayerState_O_MoveBase
{
public:
	//�R���X�g���N�^
	PlayerState_O_Idol(GSvector2& position, GSmatrix4& matrix, const PlayerPtr& player, IGameManagerPtr gameManager);
	//�e��ԓƎ��̏�����
	virtual void onUniqueInit()override;
	//�X�V����
	virtual void onUpdate(float deltaTime) {}
	//�Փˏ���
	virtual void onCollide(const Actor& other)override {}
	//�I������
	virtual void onEnd()override {}
	//���͏���
	virtual void onInput()override {}
};
#endif // !PLAYERSTATE_O_IDOL_H_
