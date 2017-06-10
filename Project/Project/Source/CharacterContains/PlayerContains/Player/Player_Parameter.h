#ifndef PLAYER_PARAMETER_H_
#define PLAYER_PARAMETER_H_

#include "../../../Utility/Rederer2D/Renderer2DPtr.h"
#include"../../../Utility/Animation/Animation.h"
#include<gslib.h>

//�v���C���[�p�����[�^�[
struct Player_Parameter
{
public:
	Player_Parameter();
	//�c�@��
	int m_Remaining{ 0 };
	//�X�^�[�g�n�_
	GSvector2 m_StratPosition;
	//�R���{��
	int m_Combo{ 0 };
	//�t���[���J�E���^�[
	float m_FrameCounter{ 0.0f };
	//�t���O
	bool flag{ false };
	//�X�s�[�h
	float m_Speed{8.0f};
	//�`���[�W�J�E���^�[
	float m_ChargeConter{ 0.0f };
	//�`���[�W�p���[
	int m_ChargePower{ 0 };

public:
	void DrawRemaining(const Renderer2DPtr& renderer);
	void DrawCombo(const Renderer2DPtr& renderer);
	void setRemaining(int remaining);
	void addCombo();
	void comboReset(float deltaTime);
	int addBonus();
	void Charge(float deltaTime);
	int getChargePower();
};

#endif // !PLAYER_PARAMETER_H_
