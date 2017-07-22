#ifndef CRUSH_EFFECT_H_
#define CRUSH_EFFECT_H_

#include "../../../ActorContains/Actor/Actor.h"
#include"../../../WorldContains/IWorld.h"
#include"../../../TextureContains/AnimationTexture/AnimationTexture.h"
#include"../../../Utility/Animation/Animation.h"

class Renderer2D;

class Crush_Effect :public Actor
{
public:
	//コンストラクタ
	Crush_Effect(
		IWorld* world,
		const GSvector2& position,
		IGameManagerPtr gameManager);
	//デストラクタ
	~Crush_Effect();
	//初期化
	virtual void onInitialize()override;
	//更新処理
	virtual void onUpdate(float deltaTime)override;
	//描画処理
	virtual void onDraw()const override;
	//衝突判定
	virtual void onCollide(Actor& other, const Body::ContactSet& contactSet)override {}
};
#endif // !CRUSH_EFFECT_H_
