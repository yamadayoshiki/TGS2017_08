#ifndef CREDIT_START_H_
#define CREDIT_STSRT_H_

#include "../../Scene/ChildScene.h"

class CreditStart :public ChildScene
{
public:
	//�R���X�g���N�^
	CreditStart();
	//�f�X�g���N�^
	~CreditStart();

protected:
	// �J�n     
	virtual void OnStart() override;
	// �X�V     
	virtual void OnUpdate(float deltaTime) override;
	// �`��     
	virtual void OnDraw()const override;
	//�I��
	virtual void OnEnd()override;

private:
	float timer_;
};
#endif // !CREDIT_START_H_
