#ifndef PLAYER_STATE_H_
#define PLAYER_STATE_H_

#include"../../../ActorContains/State/Base/State.h"
#include"../PlayerState/PlayerStateName.h"
#include"../../../Base/GameManagerContains/GameManager/GameManager.h"
#include"../../../Utility/InputState/InputState.h"
#include"../Arm/Arm.h"
#include"../Arm/ArmPtr.h"

#include <unordered_map>

// �e�v���C���[�X�e�[�g�̊��N���X
class PlayerState :public State
{
public:
	//�R���X�g���N�^
	PlayerState(GSvector2& position, GSmatrix4& matrix, IGameManagerPtr gameManager);
	//�p�b�h����
	virtual void input()override;

protected:
	//���[�V�����ύX
	//void motion_change(Actor& actor, const PlayerStateID);
	//�ړ�����
	void move(Actor& actor, float deltaTime, float speed = 1.0f);
	//���ޏ���
	void Rounds(const Actor& actor);

protected:
	//���W�̎Q��
	GSvector2&			mPosition;
	//�s��
	GSmatrix4&			mMatrix;
	//���x
	GSvector2			mVelocity;
	//��]�p�x
	float				mAngle;
	//GameManager
	IGameManagerPtr		p_GameManager;
	//InoutState
	InputStatePtr		p_Input;
	//
	ArmPtr				p_Arm;

};

#endif // !PLAYER_STATE_H_