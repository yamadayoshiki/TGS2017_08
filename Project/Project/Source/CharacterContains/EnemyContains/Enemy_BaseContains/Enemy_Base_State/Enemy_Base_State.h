#ifndef ENEMY_BASE_STATE_H_
#define ENEMY_BASE_STATE_H_

#include <gslib.h>
#include "../../../../ActorContains/State/Base/State.h"

//�e�G�l�~�[�X�e�[�g�̊��N���X
class Enemy_Base_State :public State
{
public:
	//�R���X�g���N�^
	Enemy_Base_State(GSvector2& position);

protected:
	//�ړ�����
	void Move(Actor& actor, float deltaTime, float speed = 1.0f);

protected:
	//���W�̎Q��
	GSvector2& m_Position;
	//���x
	GSvector2 m_Velocity;
	//��]�p�x
	float m_Angle;
};

#endif // !ENEMYBASE_STATE_H_
