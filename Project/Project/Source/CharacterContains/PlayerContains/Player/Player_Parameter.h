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
	//���W
	GSvector2 m_Position{ 0.0f,0.0f };
	//�c�@��
	int m_Remaining{ 0 };
	//�X�^�[�g�n�_
	GSvector2 m_StratPosition;
	//�R���{��
	int m_Combo{ 0 };
	//Max�R���{��
	int m_MaxCombo{ 0 };
	//�R���{�^�C�}�[
	float m_ComboTimer{ 0.0f };
	//�t���[���J�E���^�[
	float m_FrameCounter{ 0.0f };
	//�`���[�W�t���O
	bool Chargeflag{ false };
	//�X�s�[�h
	float m_Speed{5.0f};
	//�`���[�W�J�E���^�[
	float m_ChargeConter{ 0.0f };
	//�`���[�W�p���[
	int m_ChargePower{ 0 };
	//���g���C��
	int m_RetryCount{ 0 };
	//�`���[�W�{�[�i�X�R���{
	int m_BonusCombo{ 0 };

public:
	GSvector2 getPosition()const;
	void setPosition(const GSvector2& position);
	int GetRemaining() const;
	void setRemaining(int remaining);
	void addCombo();
	void comboReset();
	int  getCombo()const;
	int  getMaxCombo()const;
	float getComboCounter()const;
	int addBonus();
	void Charge(float deltaTime);
	int getChargePower();
	bool getChargeFlag()const;
	void addRetryCount();
	int getRetryCount();
};

#endif // !PLAYER_PARAMETER_H_
