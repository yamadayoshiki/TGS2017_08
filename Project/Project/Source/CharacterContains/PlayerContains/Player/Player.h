#ifndef PLAYER_H_
#define PLAYER_H_

#include"../../../ActorContains/Actor/Actor.h"
#include"Player_Parameter.h"
#include"../PlayerState/PlayerStateManager.h"
#include"../../../WorldContains/IWorld.h"
#include"../Arm/ArmPtr.h"
#include"../../../Map/Map.h"
#include<memory>

class Renderer2D;

class Player :public Actor, public std::enable_shared_from_this<Player>
{
public:
	//コンストラクタ
	Player(IWorld* world, const GSvector2& position, const IGameManagerPtr& gameManager);
	//デストラクタ
	~Player();
	//
	virtual void initialize()override;
	//更新処理
	virtual void onUpdate(float deltaTime)override;
	//描画処理
	virtual void onDraw()const override;
	//衝突判定
	virtual void onCollide(Actor& other)override;
	
	//プレイヤーパラメーターの取得
	Player_Parameter getParameter();

	virtual ActorPtr clone(const GSvector2& position) override;

protected:
	//メッセージ処理
	virtual void onMessage(EventMessage message, void* param) override;

private:
	//状態管理
	PlayerStateManager*		mStateManager;
	//レンダラー
	Renderer2DPtr			p_Renderer;
	//マップデータ
	Map						p_Map;
	//プレイヤーパラメター
	Player_Parameter		m_Parameter;
	//回転
	float					angle;
	//子
	ArmPtr				child;
};
#endif // !PLAYER_H_
