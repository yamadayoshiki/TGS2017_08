#ifndef PLAYER_STATE_H_
#define PLAYER_STATE_H_

#include"../../../ActorContains/State/Base/State.h"
#include"../PlayerState/PlayerStateName.h"
#include"PlayerMotion_ID.h"
#include"../../../Base/GameManagerContains/GameManager/GameManager.h"
#include"../../../Utility/InputState/InputState.h"
#include"../Player/Player.h"
#include "../Player/PlayerPtr.h"
#include"../Player/Player_Parameter.h"

class Map;

// �e�v���C���[�X�e�[�g�̊��N���X
class PlayerState :public State
{
public:
	//�R���X�g���N�^
	PlayerState(const Player_WPtr& player, const IGameManagerPtr& gameManager);
	//�p�b�h����
	virtual void input()override;

protected:
	//���[�V�����ύX
	void motion_change(const PlayerMotion_ID id);
	//�ړ�����
	void move(float deltaTime, float speed = 8.0f);
	//�A�[���X�V
	void armUpdate();
	//����p���ɂ��邩
	bool is_Scorp_Angle(const Actor& other);
	//�e�N�X�`�����O�ύX
	void TextureName_Change(const std::string& name);
	//�G�Ƃ̏Փˏ���
	void Collide(const Actor& other);
	//
	void Center_Adjustment();

protected:
	//�v���C���[�{��
	Player_WPtr			p_Player;
	//�ϊ�
	Transform&			m_TransForm;
	//�v���C���[�p�����[�^�[
	Player_Parameter&	m_Parameter;
	//��]�p�x
	float				mAngle;
	//GameManager
	IGameManagerPtr		p_GameManager;
	//InoutState
	InputStatePtr		p_Input;
	//Map
	Map&				m_Map;
	//�t���[���J�E���^�[
	float				m_FramConter{0.0f};

private:
	GSvector2			inputVelocity;
	GSvector2			m_Position;

};

#endif // !PLAYER_STATE_H_