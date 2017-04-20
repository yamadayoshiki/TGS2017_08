#ifndef ENEMY_BASESTATE_H_
#define ENEMY_BASESTATE_H_

#include <gslib.h>
#include "../../../../ActorContains/State/Base/State.h"

/*�p����Ŏg������*/
#include "../../EnemyStateName.h"

//�e�G�l�~�[�X�e�[�g�̊��N���X
class Enemy_BaseState :public State
{
public:
	//�R���X�g���N�^
	Enemy_BaseState(GSvector2& position, GSmatrix4& rotate);
	// ���͏���
	virtual void input() override;
protected:
	//�ړ�����
	void Move(Actor& actor, float deltaTime, float speed = 1.0f);

protected:
	//���W�̎Q��
	GSvector2& m_Position;
	//�s��̎Q��
	GSmatrix4& m_Rotate;
	//���x
	GSvector2 m_Velocity;
	//��]�p�x
	float m_Angle;
};

#endif // !ENEMYBASE_STATE_H_
