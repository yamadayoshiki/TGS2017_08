#ifndef TRANSITIONMANAGER_H_
#define TRANSITIONMANAGER_H_
#include "../TransitionPtr.h"
#include <functional>
#include <stack>
//�V�[���C���^�[�t�F�C�X
class TransitionManager
{
public:
	// �R���X�g���N�^
	TransitionManager();
	// �f�t�H���g�R���X�g���N�^
	//TransitionManager();
	// �ǉ�
	void addTransition( const TransitionPtr& transition);
	// �X�V����
	void update(float deltaTime);
	// 
	void change();
protected:
	std::stack<TransitionPtr> m_Transitions;
};
#endif // !TRANSITIONMANAGER_H_