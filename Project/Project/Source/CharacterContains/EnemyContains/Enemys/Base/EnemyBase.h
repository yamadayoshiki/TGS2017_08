#ifndef ENEMYBASE_H_
#define ENEMYBASE_H_

#include "../../../../ActorContains/State/Base/State.h"
#include "../../StateContains/StateManager/EnemyStateManager.h"
#include "../../CommandContains/CommandManager/EnemyCommandManager.h"

//先行宣言
class EnemyStateManager;

//エネミー基底クラス
class EnemyBase :public Actor, std::enable_shared_from_this<EnemyBase>
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
	EnemyCommandManager* GetCommandManager();

protected:
	//更新
	virtual void onUpdate(float deltaTime) override;
	//描画
	virtual void onDraw() const override;
	//衝突した
	virtual void onCollide(Actor& other) override;

protected:
	float m_Speed;								//スピード
	EnemyStateManager* p_StateManager;			//ステートマネージャー
	EnemyCommandManager* p_CommandManager;		//コマンドマネージャー
};
#endif