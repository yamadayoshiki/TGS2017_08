#pragma once

#include "IState.h"
#include "../../Actor/Actor.h"

// �e�v���C���[�X�e�[�g�̊��N���X
class State : public IState {
public:
	// �R���X�g���N�^
	State();
	// �S��ԋ��ʂ̏�����
	virtual void common_init(Actor& actor, const Component comp) override;
	// ���͏���
	virtual void input() override;
	// ���ԊǗ�
	virtual void timer(const float& deltaTime) override;
	// �X�e�[�g�̕ύX����
	virtual void change(const Component comp) override;
	// �X�e�[�g�̕ύX����(template��)
	template <class STATE>
	void change(const STATE id, const ActionType type = ActionType::None);
	// �X�e�[�g���I���������ۂ�
	virtual bool isEnd() override;
	// ���̃X�e�[�g�̗v�f
	virtual Component next() const override;
protected:
	// �X�e�[�g�̗v�f
	Component mComponent;
	// �X�e�[�g�̗v�f
	Component mNextComponent;
	// �X�e�[�g���I���������ۂ�
	bool mIsEnd;
	// �^�C�}�[
	float mTimer;
};

// �X�e�[�g�̕ύX����(template��)
template<class STATE>
inline void State::change(const STATE id, const ActionType type){
	if (mComponent.mID == static_cast<int>(id)) return;
	// ���̃X�e�[�g���̊i�[
	mNextComponent.mID = static_cast<int>(id);
	mNextComponent.mType = type;
	// �X�e�[�g�̏I��������true�ɕύX
	mIsEnd = true;
}
