#ifndef CHARGE_H_
#define CHARGE_H_


#include"../../../ActorContains/Actor/Actor.h"
#include"../../../WorldContains/IWorld.h"
#include"../../../TextureContains/AnimationTexture/AnimationTexture.h"
#include"../../../Utility/Animation/Animation.h"
#include"../../../CharacterContains/PlayerContains/Player/PlayerPtr.h"

#include<string>

class Renderer2D;

//チャージエフェクトクラス
class Charge :public Actor
{
private:
	enum Charge_Stage
	{
		Zero,	//0番目
		Frist,	//1段階目
		Second,	//2段階目
		Third,	//3段階目
	};
public:
	//コンストラクタ
	Charge(IWorld* world, const GSvector2& position, const IGameManagerPtr& gameManager, const Player_WPtr& player);
	//デストラクタ
	~Charge();
	//初期化
	virtual void onInitialize()override;
	//更新処理
	virtual void onUpdate(float deltaTime)override;
	//描画処理
	virtual void onDraw()const override;
	//衝突判定
	virtual void onCollide(Actor& other, const Body::ContactSet& contactSet)override {}

private:
	//チャージ段階の更新
	void ChargeUpdate();

private:
	//レンダラー
	Player_WPtr				p_Player;
	AnimationTexture*		p_AnimationTexture;
	//Animation*				p_Animation;
	std::string				m_CurrrentName;
	std::string				m_PreviosName;
	Charge_Stage			m_Charge_Stage;
};
#endif // !CHARGE_H_
