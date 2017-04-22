#ifndef PLAYERSTATE_A_MOVEBASE_H_
#define PLAYERSTATE_A_MOVEBASE_H_

#include"../../../PlayerState.h"

class PlayerState_A_MoveBase:public PlayerState
{
public:
	//�R���X�g���N�^
	PlayerState_A_MoveBase(GSvector2& position,GSmatrix4& matirx,IGameManagerPtr gameManager);
	//�e��ԓƎ��̏�����
	virtual void unique_init(Actor& actor)override;
	//�X�V����
	virtual void update(Actor& actor, float deltaTaime)override;
	//�Փ˔���
	virtual void collide(const Actor& other)override;
	//�I������
	virtual void end()override;
	//���͏���
	virtual void input() override;

protected:
	//�e��Ԃ̏�����
	virtual void onUniqueInit(Actor& actor) = 0;
	// �X�V����
	virtual void onUpdate(Actor & actor, float deltaTime) = 0;
	// �Փ˔���
	virtual void onCollide(const Actor & other) = 0;
	// �I�����̏���
	virtual void onEnd() = 0;
	// ���͏���
	virtual void onInput() = 0;
};
#endif // !PLAYERSTATE_A_MOVEBASE_H_

