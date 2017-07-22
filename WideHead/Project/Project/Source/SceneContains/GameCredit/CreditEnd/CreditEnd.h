#ifndef CREDIT_END_H_
#define CREDIT_END_H_

#include"../../Scene/ChildScene.h"
#include <GStype.h>
class Texture;

class CreditEnd :public ChildScene
{
public:
public:
	//コンストラクタ
	CreditEnd();

protected:
	// 開始     
	virtual void OnStart() override;
	// 更新     
	virtual void OnUpdate(float deltaTime) override;
	// 描画     
	virtual void OnDraw()const override;
	//終了
	virtual void OnEnd()override;

private:
	float timer_;
	float maxTimer_;
	GScolor m_Color;
};
#endif // !CREDIT_END_H_
