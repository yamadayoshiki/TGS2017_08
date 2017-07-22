#ifndef CREDIT_STAGING_H_
#define CREDIT_STAGING_H_

#include "../../Scene/ChildScene.h"

class CreditStaging :public ChildScene
{
public:
	//�R���X�g���N�^
	CreditStaging();
	//�f�X�g���N�^
	~CreditStaging();

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
#endif // !CREDIT_STAGING_H_
