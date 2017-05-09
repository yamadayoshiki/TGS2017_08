#pragma once

#include "Transition/Transition.h"

// �V�[���؂�ւ��N���X
class SceneTransition : public Transition{
public:
	// �R���X�g���N�^
	SceneTransition(const IGameManagerPtr& gameManager);
	// �f�X�g���N�^
	~SceneTransition();

	// �J�n     
	virtual void onStart()override;
	//�X�V
	virtual void onUpdate(float deltaTime)override;
	//�`��
	virtual void onDraw() const override;
	// �I���t���O
	virtual bool isEnd() override;
private:
	// ���l
	GScolor m_Color;
};