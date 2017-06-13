#ifndef CHARGE_H_
#define CHARGE_H_


#include"../../../ActorContains/Actor/Actor.h"
#include"../../../WorldContains/IWorld.h"
#include"../../../TextureContains/AnimationTexture/AnimationTexture.h"
#include"../../../Utility/Animation/Animation.h"

#include<string>

class Renderer2D;

//チャージエフェクトクラス
class Charge :public Actor
{
public:
	//コンストラクタ
	Charge(IWorld* world, const GSvector2& position, const IGameManagerPtr& gameManager);
	//デストラクタ
	~Charge();
	//初期化
	virtual void initialize()override;
	//更新処理
	virtual void onUpdate(float deltaTime)override;
	//描画処理
	virtual void onDraw()const override;
	//衝突判定
	virtual void onCollide(Actor& other)override{}

private:
	//レンダラー
	Renderer2DPtr			p_Renderer;
	AnimationTexture*		p_AnimationTexture;
	Animation*				p_Animation;
	std::string				m_Name;
};
#endif // !CHARGE_H_
