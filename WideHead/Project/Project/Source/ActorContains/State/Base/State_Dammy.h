#pragma once

#include "IState.h"

// �X�e�[�g�̃_�~�[�N���X�i�X�e�[�g�̐؂�ւ�莞�Ɉ�U�g�p�j
class State_Dammy : public IState {
public:
	// �R���X�g���N�^
	State_Dammy() : m_ID(-1) {}
	// �S��ԋ��ʂ̏�����
	virtual void common_init(const int id) override {}
	// �e��ԓƎ��̏�����
	virtual void unique_init() override {}
	// ���͏���
	virtual void input() override {}
	// �X�V����
	virtual void update(float deltaTime) override {}
	// �X�V����
	virtual void timer(const float& deltaTime) override {}
	// ��Ԃ̕ύX
	virtual void change_int(const int id) override {}
	// ��Ԃ̕ύX
	virtual void collide(const Actor & other, const Body::ContactSet& contactSet) override {}
	// �I����Ԃ�
	virtual bool isEnd() override { return false; }
	// ���̃X�e�[�g�̗v�f
	virtual int next() const override { return m_ID; }
	// �I�����̏���
	virtual void end() override {}
	// IState ����Čp������܂���
	virtual void addChild(const ActorName& name, const ActorPtr& child) override {}
	// ���b�Z�[�W����
	virtual void handleMessage(EventMessage message, void* param) override {};

private:
	// �X�e�[�g
	int m_ID;

};
