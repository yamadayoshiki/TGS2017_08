#ifndef SCENETRANSITION_H_
#define SCENETRANSITION_H_
#include "Transition/Transition.h"
#include <gslib.h>
// �V�[���؂�ւ��N���X
class SceneTransition : public Transition{
public:
	// �R���X�g���N�^
	SceneTransition(const IGameManagerPtr& gameManager);
	// �f�X�g���N�^
	~SceneTransition();

	// �J�n     
	virtual void onStart()override;
	//�X�V
	virtual void onUpdate(float deltaTime)override;
	//�`��
	virtual void onDraw() const override;
	// �I���t���O
	virtual bool isEnd() override;
private:
	GScolor m_Color;	// ���l
	int m_DrawID;		//�`��ID
};

#endif // !SCENETRANSITION_H_