#ifndef PLAYERSTATE_IDOL_H_
#define PLAYERSTATE_IDOL_H_

#include"PlayerState_MoveBase.h"

//�ҋ@(�ʏ�)���
class PlayerState_Idol:public PlayerState_MoveBase
{
public:
	//�R���X�g���N�^
	PlayerState_Idol(GSvector2& position,GSmatrix4& matrix, const PlayerPtr& player, IGameManagerPtr gameManager);
	//�e��ԓƎ��̏�����
	virtual void onUniqueInit()override;
	//�X�V����
	virtual void onUpdate(float deltaTime){}
	//�Փˏ���
	virtual void onCollide(const Actor& other)override {}
	//�I������
	virtual void onEnd()override {}
	//���͏���
	virtual void onInput()override{}
};
#endif // !PLAYERSTATE_IDOL_H_

