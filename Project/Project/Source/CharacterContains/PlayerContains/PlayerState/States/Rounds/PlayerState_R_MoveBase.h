#ifndef PLAYERSTATE_R_MOVEBASE_H_
#define PLAYERSTATE_R_MOVEBASE_H_

#include"../../PlayerState.h"

class PlayerState_R_MoveBase :public PlayerState
{
public:
	//�R���X�g���N�^
	PlayerState_R_MoveBase(GSvector2& position, GSmatrix4& matirx, const PlayerPtr& player, IGameManagerPtr gameManager);
	//�e��ԓƎ��̏�����
	virtual void unique_init()override;
	//�X�V����
	virtual void update(float deltaTaime)override;
	//�Փ˔���
	virtual void collide(const Actor& other)override;
	//�I������
	virtual void end()override;
	//���͏���
	virtual void input() override;

protected:
	//�e��Ԃ̏�����
	virtual void onUniqueInit() = 0;
	// �X�V����
	virtual void onUpdate(float deltaTime) = 0;
	// �Փ˔���
	virtual void onCollide(const Actor & other) = 0;
	// �I�����̏���
	virtual void onEnd() = 0;
	// ���͏���
	virtual void onInput() = 0;
};
#endif // !PLAYERSTATE_R_MOVEBASE_H_