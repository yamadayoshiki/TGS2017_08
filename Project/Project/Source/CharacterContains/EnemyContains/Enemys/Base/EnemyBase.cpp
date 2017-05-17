#include "EnemyBase.h"
#include "../../../../WorldContains/World/World.h"
#include "../../../../WorldContains/EventMessage/EventMessage.h"
#include "../../CommandContains/CommandManagers/Interface/IEnemyCommandManager.h"

//コンストラクタ
EnemyBase::EnemyBase(
	IWorld* world,
	const ActorName& name,
	const GSvector2& position,
	const float speed,
	const IGameManagerPtr& gameManager,
	const ITexturePtr& texture,
	const IBodyPtr& body)
	: Actor(world, name, position, gameManager, texture, body)
	, m_Speed(speed) {
}

//デストラクタ
EnemyBase::~EnemyBase() {
	delete p_StateManager;
}

//初期化
void EnemyBase::initialize() {
	//各種固有のコマンドの設定
	SetUpCommand();
	//各種固有のStateの設定
	SetUpState();
}

//更新
void EnemyBase::onUpdate(float deltaTime) {
	//コマンド情報の更新
	p_CommandManager->Update(deltaTime);

	//状態管理の更新
	p_StateManager->action(deltaTime);

	//地形との衝突判定

}

//描画
void EnemyBase::onDraw() const {

}

//衝突した
void EnemyBase::onCollide(Actor& other) {
	//状態ごとの衝突判定
	p_StateManager->collide(*this, other);
}

//ステートマネージャーを取得する
EnemyStateManager* EnemyBase::GetStateManager() {
	return p_StateManager;
}

//コマンドマネージャーを取得する
IEnemyCommandManagerPtr EnemyBase::GetCommandManager() {
	return p_CommandManager;
}

//メッセージ処理
void EnemyBase::onMessage(EventMessage message, void* param) {
	//メッセージ処理
	p_StateManager->handleMessage(message, param);
}