#ifndef ENEMYBASE_H_
#define ENEMYBASE_H_

#include "../../../../../ActorContains/State/Base/State.h"
#include "../../../CommandContains/CommandManagers/Interface/IEnemyCommandManagerPtr.h"
#include "../../../../../ActorContains/HitPoint/HitPoint.h"
#include "../../../../../Utility/FourDirection/FourDirection.h"
#include "../../../../../ActorContains/Actor/Actor.h"
#include "../../../PlayerWatch/PlayerWatchPtr.h"
#include "../../../StateContains/StateManager/EnemyStateManagerPtr.h"
#include "../../../../../Map/MapType.h"
#include <map>

//エネミー基底クラス
class EnemyBase :public Actor, public std::enable_shared_from_this<EnemyBase>
{
public:
	//コンストラクタ
	EnemyBase(
		IWorld* world,													//ワールド
		const ActorName& name,											//名前
		const GSvector2& position,										//座標
		const FourDirection front,										//向き
		const int maxHp,												//ヒットポイント
		const MapType type,												//移動マップタイプ
		const IGameManagerPtr& gameManager,								//ゲームマネージャ
		const ITexturePtr& texture,										//テクスチャ
		const IBodyPtr& body = std::make_shared<Body::NullBody>());			//衝突判定図形

																			//デストラクタ
	virtual ~EnemyBase();
	//初期化
	virtual void initialize() override;
	//ステートマネージャーを取得する
	EnemyStateManager* GetStateManager();
	//コマンドマネージャーを取得する
	IEnemyCommandManager* GetCommandManager();
	//ヒットポイントを取得する
	HitPoint& GetHitPoint();
	//倒せるか倒せないか
	bool CanDead();
	//プレイヤー監視クラスを取得する
	const PlayerWatch* GetPlayerWatch() const;
	//向きを取得
	FourDirection GetDirection() const;
	//向きを設定
	void SetDirection(FourDirection dir);
	//移動マップタイプを取得
	MapType GetMapType() const override;

	//テクスチャの切り替え
	void Settexture(const std::string textureName);

protected:
	//各種固有のコマンドの設定
	virtual void SetUpCommand() {}
	//各種固有のStateの設定
	virtual void SetUpState() {}
	//更新
	virtual void onUpdate(float deltaTime) override;
	//描画
	virtual void onDraw() const override;
	//衝突した
	virtual void onCollide(Actor& other) override;
	//メッセージ処理
	virtual void onMessage(EventMessage message, void* param) override;

protected:
	MapType m_MapType;								//移動マップタイプ
	HitPoint m_HitPoint;							//ヒットポイント
	PlayerWatchUPtr p_PlayerWatch;					//プレイヤー監視
	EnemyStateManagerUPtr p_StateManager;			//ステートマネージャー
	IEnemyCommandManagerUPtr p_CommandManager;		//コマンドマネージャー

	std::map < std::string, ITexturePtr > m_TextureMap;	//テクスチャ切り替えようマップ

	FourDirection m_FourDirection;					//向き
};
#endif