#ifndef PLAYERSTATE_CRUSH_HOLD_H_
#define PLAYERSTATE_CRUSH_HOLD_H_

#include"PlayerState_CrushBase.h"

class PlayerState_Crush_Hold:public PlayerState_CrushBase
{
public:
	//�R���X�g���N�^
	PlayerState_Crush_Hold(GSvector2& position, GSmatrix4& matrix, IGameManagerPtr gameManager);
	//�e��ԓƎ��̏�����
	virtual void onUniqueInit(Actor& actor)override;
	//�X�V����
	virtual void onUpdate(Actor& actor, float deltaTime)override;
	//�Փˏ���
	virtual void onCollide(const Actor& other)override {}
	//�I������
	virtual void onEnd()override {}
	//���͏���
	virtual void onInput()override {}
};
#endif // !PLAYERSTATE_CRUSH_HOLD_H_