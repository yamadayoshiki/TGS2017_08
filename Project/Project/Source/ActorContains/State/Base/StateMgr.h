#pragma once

#include "IStatePtr.h"
#include "IState.h"

#include <unordered_map>

class Actor;

// �X�e�[�g�̏����Ǘ�
class StateMgr{
public:
	// �R���X�g���N�^
	StateMgr();
public:
	// �X�V����
	void action(Actor& actor, float deltaTime) ;
	// �X�e�[�g�̒ǉ�(template��)
	template <class STATE>
	void add(STATE id, const IStatePtr& state);
	// �X�e�[�g�̕ύX����(template��)
	template <class STATE>
	void change(Actor& actor, const STATE id, const ActionType type = ActionType::None);
	// �X�e�[�g�̕ύX����
	void change(Actor& actor, const IState::Component element);
	// �w�肳�ꂽ�X�e�[�g�̏ꍇtrue(template��)
	template <class STATE>
	bool currentState(STATE state);
	// ���݂̃X�e�[�g���w�肳�ꂽ�X�e�[�g�̏ꍇtrue
	bool currentActionType(ActionType action_type = ActionType::None);
	// ���݂̏�Ԃ̗v�f
	IState::Component getComponent();
	// �Փ˔���
	void collide(Actor& actor, const Actor& other);
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
	IState::Component mComponent;
};

// �w�肳�ꂽ�X�e�[�g�̏ꍇtrue(template��)
template<class STATE>
inline bool StateMgr::currentState(STATE state){
	return mComponent.mID == static_cast<int>(state);
}

// �X�e�[�g�̕ύX����(template��)
template<class STATE>
inline void StateMgr::change(Actor & actor, const STATE id, const ActionType type) {
	// �O�X�e�[�g�̏I������
	mCurrentState->end();
	// �v�f�̊i�[
	mComponent.mID = (int)id;
	mComponent.mType = type;
	// ���s�X�e�[�g��ύX
	mCurrentState = mStates[mComponent.mID];
	// ���ʂ̏�����
	mCurrentState->common_init(actor, mComponent);
	// �ŗL�̏�����
	mCurrentState->unique_init(actor);
}

// �X�e�[�g�̒ǉ�(template��)
template<class STATE>
inline void StateMgr::add(STATE id, const IStatePtr & state){
	// �L�[���w�肵�Ċi�[
	mStates[static_cast<int>(id)] = state;
}

