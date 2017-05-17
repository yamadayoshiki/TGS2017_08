#ifndef ENEMYBASE_H_
#define ENEMYBASE_H_

#include "../../../../ActorContains/State/Base/State.h"
#include "../../StateContains/StateManager/EnemyStateManager.h"
#include "../../CommandContains/CommandManagers/Interface/IEnemyCommandManagerPtr.h"

//先行宣言
class EnemyStateManager;

//エネミー基底クラス
class EnemyBase :public Actor, public std::enable_shared_from_this<EnemyBase>
{
public:
	//コンストラクタ
	EnemyBase(
		IWorld* world,
		const ActorName& name,
		const GSvector2& position,
		const float speed,
		const IGameManagerPtr& gameManager,
		const ITexturePtr& texture,
		const IBodyPtr& body = std::make_shared<DammyBody>());
	//デストラクタ
	virtual ~EnemyBase();
	//初期化
	virtual void initialize() override;
	//ステートマネージャーを取得する
	EnemyStateManager* GetStateManager();
	//コマンドマネージャーを取得する
	IEnemyCommandManagerPtr GetCommandManager();

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
	EnemyStateManager* p_StateManager;				//ステートマネージャー
	IEnemyCommandManagerPtr p_CommandManager;		//コマンドマネージャー
};
#endif