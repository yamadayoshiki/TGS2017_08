#ifndef CREDIT_END_H_
#define CREDIT_END_H_

#include"../../Scene/ChildScene.h"
#include <GStype.h>
class Texture;

class CreditEnd :public ChildScene
{
public:
public:
	//�R���X�g���N�^
	CreditEnd();

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
	float maxTimer_;
	GScolor m_Color;
};
#endif // !CREDIT_END_H_
