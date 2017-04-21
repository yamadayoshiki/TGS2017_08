#ifndef PLAYER_H_
#define PLAYER_H_

#include"../../../ActorContains/Actor/Actor.h"
#include"../PlayerState/PlayerStateManager.h"
#include"../../../WorldContains/IWorld.h"
#include<memory>

class Renderer2D;

class Player :public Actor
{
public:
	//コンストラクタ
	Player(IWorld* world,const GSvector2& position,IGameManager* gameManager);
	//デストラクタ
	~Player();
	//更新処理
	virtual void onUpdate(float deltaTime)override;
	//描画処理
	virtual void onDraw()const override;
	//衝突判定
	virtual void onCollide(Actor& other)override;

private:
	//ゲーム管理者
	IGameManager*			p_GameManager;
	//状態管理
	PlayerStateManager*		mStateManager;
	//レンダラー
	Renderer2D*				p_Renderer;
	//回転
	float angle;
};
#endif // !PLAYER_H_
