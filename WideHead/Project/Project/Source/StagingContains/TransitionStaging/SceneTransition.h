#ifndef SCENETRANSITION_H_
#define SCENETRANSITION_H_
#include "Transition/Transition.h"
#include <gslib.h>
class Texture;
// �V�[���؂�ւ��N���X
class SceneTransition : public Transition {
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
	// �I��
	virtual void onEnd() override;
	// �I���t���O
	virtual bool isEnd() override;
private:
	GScolor m_Color;	// ���l
	std::shared_ptr<Texture> p_Texture;
};

#endif // !SCENETRANSITION_H_