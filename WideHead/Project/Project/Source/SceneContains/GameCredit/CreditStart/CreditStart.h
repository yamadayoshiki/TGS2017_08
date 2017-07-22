#ifndef CREDIT_START_H_
#define CREDIT_STSRT_H_

#include "../../Scene/ChildScene.h"

class CreditStart :public ChildScene
{
public:
	//コンストラクタ
	CreditStart();
	//デストラクタ
	~CreditStart();

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
};
#endif // !CREDIT_START_H_
