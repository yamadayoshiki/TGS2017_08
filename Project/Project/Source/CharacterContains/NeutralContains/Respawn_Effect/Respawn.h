#ifndef RESPAWM_H_
#define RESPAWN_H_

#include"../../../ActorContains/Actor/Actor.h"
#include"../../../WorldContains/IWorld.h"
#include"../../../TextureContains/AnimationTexture/AnimationTexture.h"
#include"../../../Utility/Animation/Animation.h"

class Respawn :public Actor
{
public:
	//コンストラクタ
	Respawn(IWorld* world,
		const GSvector2& position,
		IGameManagerPtr gameManager);
	//デストラクタ
	~Respawn();
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
#endif // !RESPAWM_H_
