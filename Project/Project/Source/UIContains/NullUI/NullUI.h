#ifndef NULL_UI_H_
#define NULL_UI_H_

#include "../UI/UI.h"

// NullUI�N���X
class NullUI :public UI{
public:
	// �R���X�g���N�^
	NullUI(IWorld* world);
	// �R���X�g���N�^
	NullUI();

	// �X�V����
	virtual void onUpdate(float deltaTime) override;
	// �`�揈��
	virtual void onDraw() const override;
};

#endif // !NULL_UI_H_
