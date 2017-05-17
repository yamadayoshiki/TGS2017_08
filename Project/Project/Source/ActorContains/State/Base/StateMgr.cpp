#include "StateMgr.h"

#include "State_Dammy.h"

// �R���X�g���N�^
StateMgr::StateMgr()
	: mCurrentState(std::make_shared<State_Dammy>())
	, m_CurrentID(0) {
}

// �X�V����
void StateMgr::action(float deltaTime) {
	// ���͏���
	mCurrentState->input();
	// ���ԍX�V����
	mCurrentState->timer(deltaTime);
	// �X�V����
	mCurrentState->update(deltaTime);
	// �I�����肪true�ɂȂ����ꍇ�X�e�[�g��ύX
	if (mCurrentState->isEnd()) change(mCurrentState->next());
}

// �Փ˔���
void StateMgr::collide(Actor& actor, const Actor & other) {
	// �Փ˔���
	mCurrentState->collide(other);

	// �I�����肪true�ɂȂ����ꍇ�X�e�[�g��ύX
	if (mCurrentState->isEnd()) change(mCurrentState->next());
}

// ���b�Z�[�W����
void StateMgr::handleMessage(EventMessage message, void* param) {
	//���b�Z�[�W����
	mCurrentState->handleMessage(message,param);

	// �I�����肪true�ɂȂ����ꍇ�X�e�[�g��ύX
	if (mCurrentState->isEnd()) change(mCurrentState->next());
}

// ���݂̏�Ԃ̗v�f
int StateMgr::getID() {
	return m_CurrentID;
}