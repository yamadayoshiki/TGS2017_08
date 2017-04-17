#ifndef PLAYER_H_
#define PLAYER_H_

#include"../../../ActorContains/Actor/Actor.h"
#include"../PlayerState/PlayerStateManager.h"
#include"../../../WorldContains/IWorld.h"

class Player :public Actor
{
public:
	//コンストラクタ
	Player(IWorld& world,const GSvector2& pos);
	//デストラクタ
	~Player();
	//更新処理
	virtual void onUpdate(float deltaTime)override;
	//描画処理
	virtual void onDraw()const override;
	//衝突判定
	virtual void onCollide(Actor& other)override;

private:
	//状態管理
	PlayerStateManager* mStateManager;
};
#endif // !PLAYER_H_
