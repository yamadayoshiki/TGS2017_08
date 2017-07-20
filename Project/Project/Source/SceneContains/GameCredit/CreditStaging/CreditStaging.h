#ifndef CREDIT_STAGING_H_
#define CREDIT_STAGING_H_

#include "../../Scene/ChildScene.h"

class CreditStaging :public ChildScene
{
public:
	//コンストラクタ
	CreditStaging();
	//デストラクタ
	~CreditStaging();

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
#endif // !CREDIT_STAGING_H_
