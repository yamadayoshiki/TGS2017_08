#ifndef REPEL_EFFECT_H_
#define REPEL_EFFECT_H_

#include"../../../ActorContains/Actor/Actor.h"
#include"../../../WorldContains/IWorld.h"
#include"../../../TextureContains/AnimationTexture/AnimationTexture.h"
#include"../../../Utility/Animation/Animation.h"

class Renderer2D;

class Repel_Effect :public Actor
{
public:
	//コンストラクタ
	Repel_Effect(
		IWorld* world,
		const GSvector2& position,
		IGameManagerPtr gameManager);
	//デストラクタ
	~Repel_Effect();
	//初期化
	virtual void initialize()override;
	//更新処理
	virtual void onUpdate(float deltaTime)override;
	//描画処理
	virtual void onDraw()const override;
	//衝突判定
	virtual void onCollide(Actor& other)override {}

private:
	//レンダラー
	Renderer2DPtr			p_Renderer;
	AnimationTexture*		p_AnimationTexture;
};
#endif // !REPEL_EFFECT_H_
