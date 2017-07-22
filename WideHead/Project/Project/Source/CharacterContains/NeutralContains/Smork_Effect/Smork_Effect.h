#ifndef SMORK_EFFECT_H_
#define SMORK_EFFECT_H_


#include"../../../ActorContains/Actor/Actor.h"
#include"../../../WorldContains/IWorld.h"
#include"../../../TextureContains/AnimationTexture/AnimationTexture.h"
#include"../../../Utility/Animation/Animation.h"

class Renderer2D;

class Smork_Effect :public Actor
{
public:
	//コンストラクタ
	Smork_Effect(
		IWorld* world,
		const GSvector2& position,
		IGameManagerPtr gameManager);
	//デストラクタ
	~Smork_Effect();
	//初期化
	virtual void onInitialize()override;
	//更新処理
	virtual void onUpdate(float deltaTime)override;
	//描画処理
	virtual void onDraw()const override;
	//衝突判定
	virtual void onCollide(Actor& other, const Body::ContactSet& contactSet)override {}
};
#endif // !SMORK_EFFECT_H_
