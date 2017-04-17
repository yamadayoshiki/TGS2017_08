#ifndef PLAYER_STATE_H_
#define PLAYER_STATE_H_

#include"../../../ActorContains/State/Base/State.h"

enum class PlayerStateID;

// �e�v���C���[�X�e�[�g�̊��N���X
class PlayerState :public State
{
public:
	//�R���X�g���N�^
	PlayerState(GSvector2& pos);
	//�p�b�h����
	virtual void input()override;

protected:
	//���[�V�����ύX
	void motion_change(Actor& actor, const PlayerStateID);
	//�ړ�����
	void move(Actor& actor, float deltaTime, float speed = 1.0f);
	//�o������(�p�b�h)
	bool aweke_pad();

protected:
	//���W�̎Q��
	GSvector2		mPosition;
	//���x
	GSvector2		mVelocity;
	//��]�p�x
	float			mAngle;
};

#endif // !PLAYER_STATE_H_