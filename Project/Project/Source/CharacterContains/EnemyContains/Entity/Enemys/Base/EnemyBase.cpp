#include "EnemyBase.h"
#include "../../../StateContains/StateManager/EnemyStateManager.h"
#include "../../../../../WorldContains/World/World.h"
#include "../../../../../WorldContains/EventMessage/EventMessage.h"
#include "../../../CommandContains/CommandManagers/Interface/IEnemyCommandManager.h"
#include "../../../PlayerWatch/PlayerWatch.h"
#include "../../../../../DrawManager/DisplayMode.h"

//コンストラクタ
EnemyBase::EnemyBase(
	IWorld* world,
	const ActorName& name,
	const GSvector2& position,
	const FourDirection front,
	const int maxHp,
	const MapType type,
	const IGameManagerPtr& gameManager,
	const ITexturePtr& texture,
	const Body::MotionType motionType,
	const Body::BodyDataName dataName)
	: Actor(world, name, position, gameManager, texture, motionType,dataName)
	, m_HitPoint(maxHp)
	, m_FourDirection(front)
	, m_MapType(type) {
	SetDirection(m_FourDirection);
	p_Texture->ChangeDisplayMode(DisplayMode::NonDisplay);
}

//デストラクタ
EnemyBase::~EnemyBase() {
	p_StateManager.reset();
	p_CommandManager.reset();
	p_PlayerWatch.reset();
}

//初期化
void EnemyBase::onInitialize() {
	//プレイヤー監視
	p_PlayerWatch.reset(new PlayerWatch(shared_from_this()));
	//各種固有のコマンドの設定
	SetUpCommand();
	//各種固有のStateの設定
	SetUpState();
	//表示モード
	p_Texture->ChangeDisplayMode(DisplayMode::Display);
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
void EnemyBase::onCollide(Actor& other, const Body::ContactSet& contactSet) {
	//状態ごとの衝突判定
	p_StateManager->collide(*this, other,contactSet);
}

//ステートマネージャーを取得する
EnemyStateManager* EnemyBase::GetStateManager() {
	return p_StateManager.get();
}

//コマンドマネージャーを取得する
IEnemyCommandManager* EnemyBase::GetCommandManager() {
	return p_CommandManager.get();
}

//ヒットポイントを取得する
HitPoint & EnemyBase::GetHitPoint() {
	return m_HitPoint;
}

//倒せるか倒せないか
bool EnemyBase::CanDead() {
	return m_HitPoint.CanDead();
}

//プレイヤー監視クラスを取得する
const PlayerWatch* EnemyBase::GetPlayerWatch()const {
	return p_PlayerWatch.get();
}

//向きを取得
FourDirection EnemyBase::GetDirection() const {
	return m_FourDirection;
}

//向きを設定
void EnemyBase::SetDirection(FourDirection dir) {
	m_FourDirection = dir;
	setAngle(m_FourDirection.GetAngle());
}

//移動マップタイプを取得
MapType EnemyBase::GetMapType() const {
	return m_MapType;
}

//テクスチャの切り替え
void EnemyBase::Settexture(const std::string textureName) {
	p_Texture = m_TextureMap[textureName];
	p_Texture->Initialize();
}

//メッセージ処理
void EnemyBase::onMessage(EventMessage message, void* param) {
	//メッセージ処理
	p_CommandManager->handleMessage(message, param);
	p_StateManager->handleMessage(message, param);
}