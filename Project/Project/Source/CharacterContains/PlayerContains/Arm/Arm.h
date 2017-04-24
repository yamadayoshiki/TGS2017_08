#ifndef ARM_H_
#define ARM_H_

#include"../../../ActorContains/Actor/Actor.h"
#include"../../../WorldContains/IWorld.h"

class Arm:public Actor
{
public:
	//コンストラクタ
	Arm(const IWorldPtr& world, GSvector2& position, GSmatrix4& matrix, IGameManagerPtr gameManager);
	//デストラクタ
	~Arm();
	//更新処理
	virtual void onUpdate(float deltaTime)override;
	//描画処理
	virtual void onDraw()const override;
	//衝突判定
	virtual void onCollide(Actor& other)override;
	//衝突していたら返す
	bool is_Hit();
	//座標の設定
	void setPosition(GSvector2 position);
	//行列
	void setMatrix(GSmatrix4 matrix);
	//回転角度
	void setAngle(float angle);

private:
	//回転
	float		m_Angle;
	//
	bool		mHitFlag {false};
};
#endif // !ARM_H_
