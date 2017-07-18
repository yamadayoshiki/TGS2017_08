#ifndef RESULT_START_H_
#define RESULT_START_H_

#include "../../Scene/ChildScene.h"

class ResultStart :public ChildScene
{
public:
	//�R���X�g���N�^
	ResultStart();
	//�f�X�g���N�^
	~ResultStart();
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
#endif // !RESULT_START_H_
