#ifndef RESULT_END_H_
#define RESULT_END_H_

#include "../../Scene/ChildScene.h"

class ResultEnd :public ChildScene
{
public:
public:
	//�R���X�g���N�^
	ResultEnd();

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
#endif // !RESULT_END_H_
