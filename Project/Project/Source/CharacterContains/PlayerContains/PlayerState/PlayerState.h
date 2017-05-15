#ifndef PLAYER_STATE_H_
#define PLAYER_STATE_H_

#include"../../../ActorContains/State/Base/State.h"
#include"../PlayerState/PlayerStateName.h"
#include"../../../Base/GameManagerContains/GameManager/GameManager.h"
#include"../../../Utility/InputState/InputState.h"
#include"../Arm/Arm.h"
#include"../Arm/ArmPtr.h"
#include"../Player/Player.h"
#include "../Player/PlayerPtr.h"

#include <unordered_map>

// �e�v���C���[�X�e�[�g�̊��N���X
class PlayerState :public State
{
public:
	//�R���X�g���N�^
	PlayerState(const PlayerPtr& player, const IGameManagerPtr& gameManager);
	//�p�b�h����
	virtual void input()override;

protected:
	//���[�V�����ύX
	//void motion_change(Actor& actor, const PlayerStateID);
	//�ړ�����
	void move(float deltaTime, float speed = 1.0f);
	//�A�[���X�V
	void armUpdate();

protected:
	//�v���C���[�{��
	PlayerPtr			p_Player;
	//�ϊ�
	Transform			m_TransForm;
	//��]�p�x
	float				mAngle;
	//GameManager
	IGameManagerPtr		p_GameManager;
	//InoutState
	InputStatePtr		p_Input;

private:
	GSvector2			inputVelocity;
	GSvector2			m_Position;

};

#endif // !PLAYER_STATE_H_