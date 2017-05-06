#include "EnemyBase.h"
#include "../../../../WorldContains/World/World.h"

//コンストラクタ
EnemyBase::EnemyBase(
	const IWorldPtr& world,
	const ActorName& name,
	const GSvector2& position,
	const float speed,
	const IGameManagerPtr& gameManager,
	const ITexturePtr& texture,
	const IBodyPtr& body)
	: Actor(world, name, position, gameManager, texture, body)
	, m_Speed(speed)
	, p_StateManager(new EnemyStateManager(shared_from_this()))
	, p_CommandManager(new EnemyCommandManager(shared_from_this())) {
}

//デストラクタ
EnemyBase::~EnemyBase() {
	delete p_StateManager;
	delete p_CommandManager;
}

//初期化
void EnemyBase::initialize() {
	//コマンドマネージャーの初期化
	p_CommandManager->Initialize();
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
EnemyCommandManager* EnemyBase::GetCommandManager() {
	return p_CommandManager;
}