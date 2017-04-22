#include "StateMgr.h"

#include "State_Dammy.h"

// �R���X�g���N�^
StateMgr::StateMgr()
	: mCurrentState(std::make_shared<State_Dammy>())
	, m_CurrentID(0){
}

// �X�V����
void StateMgr::action(Actor& actor, float deltaTime) {
	// ���͏���
	mCurrentState->input();
	// ���ԍX�V����
	mCurrentState->timer(deltaTime);
	// �X�V����
	mCurrentState->update(actor, deltaTime);
	// �I�����肪true�ɂȂ����ꍇ�X�e�[�g��ύX
	if (mCurrentState->isEnd()) change(actor, mCurrentState->next());
}

// �Փ˔���
void StateMgr::collide(Actor& actor, const Actor & other) {
	// �Փ˔���
	mCurrentState->collide(other);

	// �I�����肪true�ɂȂ����ꍇ�X�e�[�g��ύX
	if (mCurrentState->isEnd()) change(actor, mCurrentState->next());
}

// ���݂̏�Ԃ̗v�f
int StateMgr::getID() {
	return m_CurrentID;
}