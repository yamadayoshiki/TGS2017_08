#pragma once

#include "IStatePtr.h"
#include "IState.h"

#include <unordered_map>

class Actor;
enum class EventMessage;

// �X�e�[�g�̏����Ǘ�
class StateMgr {
public:
	// �R���X�g���N�^
	StateMgr();
public:
	// �X�V����
	void action(float deltaTime);
	// �X�e�[�g�̒ǉ�(template��)
	template <class STATE>
	void add(STATE id, const IStatePtr& state);
	// �X�e�[�g�̕ύX����(template��)
	template <class STATE>
	void change(const STATE id);
	// �w�肳�ꂽ�X�e�[�g�̏ꍇtrue(template��)
	template <class STATE>
	bool currentState(STATE state);
	// ���݂̏�Ԃ̗v�f
	int getID();
	// �Փ˔���
	void collide(Actor& actor, const Actor& other);
	// ���b�Z�[�W����
	void handleMessage(EventMessage message, void* param);
private:
	// �R�s�[�֎~
	StateMgr(const StateMgr& other) = delete;
	StateMgr& operator = (const StateMgr& other) = delete;
protected:
	// �X�e�[�g�o�^�pmap
	std::unordered_map<int, IStatePtr> mStates;
	// ���݂̃X�e�[�g
	IStatePtr mCurrentState;
	// ���݂̗v�f
	int m_CurrentID;
};


// �X�e�[�g�̒ǉ�(template��)
template<class STATE>
inline void StateMgr::add(STATE id, const IStatePtr & state) {
	// �L�[���w�肵�Ċi�[
	mStates[static_cast<int>(id)] = state;
}

// �X�e�[�g�̕ύX����(template��)
template<class STATE>
inline void StateMgr::change(const STATE id) {
	// �O�X�e�[�g�̏I������
	mCurrentState->end();
	// �v�f�̊i�[
	m_CurrentID = (int)id;
	// ���s�X�e�[�g��ύX
	mCurrentState = mStates[m_CurrentID];
	// ���ʂ̏�����
	mCurrentState->common_init(m_CurrentID);
	// �ŗL�̏�����
	mCurrentState->unique_init();
}

// �w�肳�ꂽ�X�e�[�g�̏ꍇtrue(template��)
template<class STATE>
inline bool StateMgr::currentState(STATE state) {
	return m_CurrentID == static_cast<int>(state);
}