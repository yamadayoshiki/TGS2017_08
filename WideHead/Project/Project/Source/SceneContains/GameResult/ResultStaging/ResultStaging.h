#ifndef RESULT_STAGING_H_
#define RESULT_STAGING_H_

#include "../../Scene/ChildScene.h"

class ResultStaging :public ChildScene
{
public:
	//コンストラクタ
	ResultStaging();
	//デストラクタ
	~ResultStaging();

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
#endif // !RESULT_STAGING_H_
