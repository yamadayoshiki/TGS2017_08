#pragma once

#include "IState.h"
#include "../../Actor/Actor.h"

// �e�v���C���[�X�e�[�g�̊��N���X
class State : public IState
{
public:
	// �R���X�g���N�^
	State();
	// �S��ԋ��ʂ̏�����
	virtual void common_init(Actor& actor, const int id) override;
	// ���͏���
	virtual void input() override;
	// ���ԊǗ�
	virtual void timer(const float& deltaTime) override;
	// �X�e�[�g�̕ύX����
	void change_int(const int id) override;
	// �X�e�[�g�̕ύX����(template��)
	template <class STATE>
	void change(const STATE id);
	// �X�e�[�g���I���������ۂ�
	virtual bool isEnd() override;
	// ���̃X�e�[�g�̗v�f
	virtual int next() const override;
	// �q�̒ǉ�
	virtual void addChild(const ActorName& name, const ActorPtr& child) override;

protected:
	// �X�e�[�g�̗v�f
	int m_ID;
	// ���X�e�[�g�̗v�f
	int m_NextID;
	// �X�e�[�g���I���������ۂ�
	bool m_IsEnd;
	// �^�C�}�[
	float m_Timer;
	// �q���X�g
	std::unordered_map<ActorName, ActorPtr> m_Children;
};

// �X�e�[�g�̕ύX����(template��)
template<class STATE>
inline void State::change(const STATE id) {
	if (m_ID == static_cast<int>(id)) return;
	// ���̃X�e�[�g���̊i�[
	m_NextID = static_cast<int>(id);
	// �X�e�[�g�̏I��������true�ɕύX
	m_IsEnd = true;
}