#pragma once

#include "IState.h"

// �X�e�[�g�̃_�~�[�N���X�i�X�e�[�g�̐؂�ւ�莞�Ɉ�U�g�p�j
class State_Dammy : public IState {
public:
	// �R���X�g���N�^
	State_Dammy() : mComponent({ -1, ActionType::None }) {}
	// �S��ԋ��ʂ̏�����
	virtual void common_init(Actor & actor, const Component comp) override{}
	// �e��ԓƎ��̏�����
	virtual void unique_init(Actor & actor) override{}
	// ���͏���
	virtual void input() override{}
	// �X�V����
	virtual void update(Actor & actor, float deltaTime) override{}
	// �X�V����
	virtual void timer(const float& deltaTime) override{}
	// ��Ԃ̕ύX
	virtual void change(const Component comp) override{}
	// ��Ԃ̕ύX
	virtual void collide(const Actor & other) override {}
	// �I����Ԃ�
	virtual bool isEnd() override { return false; }
	// ���̃X�e�[�g�̗v�f
	virtual Component next() const override { return mComponent; }
	// �I�����̏���
	virtual void end() override{}
private:
	// �v�f�̊i�[�p�ϐ�
	Component mComponent;
};
