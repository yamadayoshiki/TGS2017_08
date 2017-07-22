#ifndef RESULT_STAGING_H_
#define RESULT_STAGING_H_

#include "../../Scene/ChildScene.h"

class ResultStaging :public ChildScene
{
public:
	//�R���X�g���N�^
	ResultStaging();
	//�f�X�g���N�^
	~ResultStaging();

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
#endif // !RESULT_STAGING_H_
