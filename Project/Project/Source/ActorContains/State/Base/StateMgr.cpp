#include "StateMgr.h"

#include "State_Dammy.h"

// �R���X�g���N�^
StateMgr::StateMgr() : mCurrentState(std::make_shared<State_Dammy>()), mComponent(){}

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
void StateMgr::collide(Actor& actor, const Actor & other){
	// �Փ˔���
	mCurrentState->collide(other);

	// �I�����肪true�ɂȂ����ꍇ�X�e�[�g��ύX
	if (mCurrentState->isEnd()) change(actor, mCurrentState->next());
}

// ���݂̃X�e�[�g���w�肳�ꂽ�X�e�[�g�̏ꍇtrue
bool StateMgr::currentActionType(ActionType action_type){
	return mComponent.mType == action_type;
}

// ���݂̏�Ԃ̗v�f
IState::Component StateMgr::getComponent(){
	return mComponent;
}

// �X�e�[�g�̕ύX����
void StateMgr::change(Actor & actor, const IState::Component element){
	// �X�e�[�g�̕ύX����(template��)
	change(actor, element.mID, element.mType);
}



