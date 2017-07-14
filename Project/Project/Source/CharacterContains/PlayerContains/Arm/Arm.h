#ifndef ARM_H_
#define ARM_H_

#include"../../../ActorContains/Actor/Actor.h"
#include"../../../WorldContains/IWorld.h"

class Arm:public Actor
{
public:
	//コンストラクタ
	Arm(IWorld* world, GSvector2& position,IGameManagerPtr gameManager);
	//デストラクタ
	~Arm();
	//更新処理
	virtual void onUpdate(float deltaTime)override;
	//描画処理
	virtual void onDraw()const override;
	//衝突判定
	virtual void onCollide(Actor& other, const Body::ContactSet& contactSet)override;
	//衝突判定
	//bool isCollide(const Actor& other);

private:
	//回転
	float		m_Angle;
	//
	bool		mHitFlag {false};
};
#endif // !ARM_H_
