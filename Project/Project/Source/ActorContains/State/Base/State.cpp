#include "State.h"

// �R���X�g���N�^
State::State() : 
	mComponent({ -1, ActionType::None }), 
	mNextComponent({ -1, ActionType::None }), 
	mTimer(0), mIsEnd(false) {}

// �S��ԋ��ʂ̏�����
void State::common_init(Actor & actor, const Component comp){
	// �ϐ��̏�����
	mComponent = comp;
	mTimer = 0;
	mIsEnd = false;
}

// ���͏���
void State::input(){}

// ���ԊǗ�
void State::timer(const float& deltaTime){
	mTimer += deltaTime;
}

// �X�e�[�g�̕ύX����
void State::change(const Component comp){
	// �X�e�[�g�̕ύX����(template��)
	change(comp.mID, comp.mType);
}

// �X�e�[�g���I���������ۂ�
bool State::isEnd(){
	return mIsEnd;
}

// ���̃X�e�[�g�̗v�f
IState::Component State::next() const{
	return mNextComponent;
}


