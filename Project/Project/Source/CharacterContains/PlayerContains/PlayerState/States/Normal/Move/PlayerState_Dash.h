#ifndef PALYERSTATE_DASH_H_
#define PALYERSTATE_DASH_H_

#include"../../../PlayerState.h"

class PlayerState_Dash:public PlayerState
{
public:
	//�R���X�g���N�^
	PlayerState_Dash(const Player_WPtr& player, IGameManagerPtr gameManager);
	//�e��ԓƎ��̏�����
	virtual void unique_init()override;
	//�X�V����
	virtual void update(float deltaTaime)override;
	//�Փ˔���
	virtual void collide(const Actor& other, const Body::ContactSet& contactSet)override;
	//�I������
	virtual void end()override {}
	//���͏���
	virtual void input()override;

private:
	//�t���[���J�E���^�[
	float				m_FramConter{ 0.0f };
	//�G���h�n�_
	GSvector2	endPos;
	//��_�Ԃ̋���
	float	m_Distance;
	//�����x�N�g��
	GSvector2	m_Direction;
	//�X�s�[�h
	float		speed;
	//�A�[�����J���Ă��邩�H
	bool		m_Flag{false};
};
#endif // !PALYERSTATE_DASH_H_

