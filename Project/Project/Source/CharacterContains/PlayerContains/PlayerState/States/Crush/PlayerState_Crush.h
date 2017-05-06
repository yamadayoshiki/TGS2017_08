#ifndef PLAYERSTATE_CRUSH_H_
#define PLAYERSTATE_CRUSH_H_

#include"PlayerState_CrushBase.h"

class PlayerState_Crush:public PlayerState_CrushBase
{
public:
	//�R���X�g���N�^
	PlayerState_Crush(GSvector2& position, GSmatrix4& matrix, const PlayerPtr& player, IGameManagerPtr gameManager);
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
#endif // !PLAYERSTATE_CRUSH_H_