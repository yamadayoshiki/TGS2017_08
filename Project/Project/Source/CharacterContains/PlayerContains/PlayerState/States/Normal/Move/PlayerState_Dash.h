#ifndef PALYERSTATE_DASH_H_
#define PALYERSTATE_DASH_H_

#include"PlayerState_MoveBase.h"

class PlayerState_Dash:public PlayerState_MoveBase
{
public:
	//�R���X�g���N�^
	PlayerState_Dash(const PlayerPtr& player, IGameManagerPtr gameManager);
	//�e��ԓƎ��̏�����
	virtual void onUniqueInit()override;
	//�X�V����
	virtual void onUpdate(float deltaTime) override;
	//�Փˏ���
	virtual void onCollide(const Actor& other) override;
	//�I������
	virtual void onEnd() override {}
	//���͏���
	virtual void onInput() override {}

private:
	//�t���[���J�E���^�[
	float		m_FrameCounter{ 0.0f };
	//�i����
	GSvector2	m_distance;
	//�����x�N�g��
	GSvector2	m_Direction;
};
#endif // !PALYERSTATE_DASH_H_

