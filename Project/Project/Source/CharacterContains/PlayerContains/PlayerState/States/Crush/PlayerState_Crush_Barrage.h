#ifndef PLAYERSTATE_CRUSH_BARRAGE_H_
#define PLAYERSTATE_CRUSH_BARRAGE_H_

#include"PlayerState_CrushBase.h"

class PlayerState_Crush_Barrage:public PlayerState_CrushBase
{
public:
	//�R���X�g���N�^
	PlayerState_Crush_Barrage(const PlayerPtr& player, IGameManagerPtr gameManager);
	//�e��ԓƎ��̏�����
	virtual void onUniqueInit()override;
	//�X�V����
	virtual void onUpdate(float deltaTime)override;
	//�Փˏ���
	virtual void onCollide(const Actor& other)override {}
	//�I������
	virtual void onEnd()override {}
	//���͏���
	virtual void onInput()override {}
};
#endif // !PLAYERSTATE_CRUSH_BARRAGE_H_

