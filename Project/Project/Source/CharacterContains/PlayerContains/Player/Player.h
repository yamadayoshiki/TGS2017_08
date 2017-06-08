#ifndef PLAYER_H_
#define PLAYER_H_

#include"../../../ActorContains/Actor/Actor.h"
#include"Player_Parameter.h"
#include"../PlayerState/PlayerStateManager.h"
#include"../../../WorldContains/IWorld.h"
#include"../Arm/ArmPtr.h"
#include"../../../Map/Map.h"
#include"../../../TextureContains/AnimationTexture/AnimationTexture.h"

#include<memory>
#include<string>

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
	Player_Parameter& getParameter();
	//テクスチャ・アニメーションの名前の設定
	void setName_Animation(const std::string& name);
	//アニメーションのループ回数を取得
	unsigned int GetLoopCount();

	virtual ActorPtr clone(const GSvector2& position, const FourDirection& front = FourDirection(FourDirectionName::None)) override;

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
	Player_Parameter&		m_Parameter;
	//アニメーションテクスチャ
	AnimationTexture*		p_AnimationTexture;
	//アニメーション
	Animation*				m_Animation;
	//フレーム数
	float					m_FraemConter;
	//名前
	std::string				m_Name;
};
#endif // !PLAYER_H_
