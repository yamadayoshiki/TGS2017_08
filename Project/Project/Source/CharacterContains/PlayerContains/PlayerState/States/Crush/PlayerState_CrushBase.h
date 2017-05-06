#ifndef PLAYERSTATE_CRUSH_BASE_H_
#define PLAYERSTATE_CRUSH_BASE_H_

#include"../../PlayerState.h"
#include"../../PlayerStateName.h"

class PlayerState_CrushBase :public PlayerState
{
public:
	//�R���X�g���N�^
	PlayerState_CrushBase(GSvector2& position, GSmatrix4& matrix, const PlayerPtr& player, IGameManagerPtr gameManager);
	//�e��ԓƎ��̏�����
	virtual void unique_init()override;
	//�X�V����
	virtual void update(float deltaTime)override;
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

protected:
	float		m_FrameCounter;
};
#endif // !PLAYERSTATE_CRUSH_BASE_H_