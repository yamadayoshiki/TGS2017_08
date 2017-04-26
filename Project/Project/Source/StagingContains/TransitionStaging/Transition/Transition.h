#pragma once

#include "../../../Utility/Texture2DParameter/Texture2DParameter.h"

//�V�[���C���^�[�t�F�C�X
class Transition
{
public:
	//�R���X�g���N�^
	Transition(Texture2DParameter* parameter);
	//�f�t�H���g�R���X�g���N�^
	//Transition();
	// ���z�f�X�g���N�^     
	virtual ~Transition();
	// �J�n     
	virtual void start();
	// �X�V     
	virtual void update(float deltaTime);

protected:
	//�X�V
	virtual void onUpdate(float deltaTime);
	//�`��
	virtual void onDraw() const;

protected:
	bool m_IsEnd;					//�I���t���O
	//IGameManager* p_GameManager;	//�Q�[���}�l�[�W���[
};
