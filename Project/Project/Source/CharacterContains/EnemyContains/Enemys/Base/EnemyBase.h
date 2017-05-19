#ifndef ENEMYBASE_H_
#define ENEMYBASE_H_

#include "../../../../ActorContains/State/Base/State.h"
#include "../../StateContains/StateManager/EnemyStateManager.h"
#include "../../CommandContains/CommandManagers/Interface/IEnemyCommandManagerPtr.h"
#include "../../../../ActorContains/HitPoint/HitPoint.h"

//先行宣言
class EnemyStateManager;

//エネミー基底クラス
class EnemyBase :public Actor, public std::enable_shared_from_this<EnemyBase>
{
public:
	//コンストラクタ
	EnemyBase(
		IWorld* world,													//ワールド
		const ActorName& name,											//名前
		const GSvector2& position,										//座標
		const float speed,												//移動速度
		const int maxHp,												//ヒットポイント
		const IGameManagerPtr& gameManager,								//ゲームマネージャ
		const ITexturePtr& texture,										//テクスチャ
		const IBodyPtr& body = std::make_shared<DammyBody>());			//衝突判定図形
																		//デストラクタ
	virtual ~EnemyBase();
	//初期化
	virtual void initialize() override;
	//ステートマネージャーを取得する
	EnemyStateManager* GetStateManager();
	//コマンドマネージャーを取得する
	IEnemyCommandManagerPtr GetCommandManager();
	//ヒットポイントを取得する
	HitPoint& GetHitPoint();

protected:
	//各種固有のコマンドの設定
	virtual void SetUpCommand() = 0;
	//各種固有のStateの設定
	virtual void SetUpState() = 0;
	//更新
	virtual void onUpdate(float deltaTime) override;
	//描画
	virtual void onDraw() const override;
	//衝突した
	virtual void onCollide(Actor& other) override;
	//メッセージ処理
	virtual void onMessage(EventMessage message, void* param) override;

protected:
	float m_Speed;									//スピード
	HitPoint m_HitPoint;							//ヒットポイント
	EnemyStateManager* p_StateManager;				//ステートマネージャー
	IEnemyCommandManagerPtr p_CommandManager;		//コマンドマネージャー
};
#endif