#include "Enemy01.h"
//コンストラクタ
#include "../../../../ActorContains/ActorName.h"
#include "../../../../TextureContains/Texture/Texture.h"
#include "../../../../ActorContains/Body/OrientedBoundingBox.h"
//描画
#include "../../../../Base/GameManagerContains/IGameManager.h"
#include "../../../../Utility/Rederer2D/Renderer2D.h"
//Command
#include "../../../../Utility/FourDirection/FourDirection.h"
//CommandContains
#include "../../CommandContains/CommandManagers/Nomal/EnemyCommandManagerNormal.h"
#include "../../CommandContains/Commands/EnemyCommandName.h"
#include "../../CommandContains/Commands/Enemy01Contains/Detour/EnemyCommandEnemy01Detour.h"
#include "../../CommandContains/Commands/Enemy01Contains/Straight/EnemyCommandEnemy01Straight.h"
//State
#include "../../StateContains/States/MoveRepelContains/Idle/EnemyStateMoveRepelIdle.h"
#include "../../StateContains/States/MoveRepelContains/Move/EnemyStateMoveRepelMove.h"
#include "../../StateContains/States/Stop/EnemyStateStop.h"
#include "../../StateContains/States/Repel/EnemyStateRepel.h"

//コンストラクタ
Enemy01::Enemy01(
	IWorld* world,
	const GSvector2& position,
	const FourDirection front,
	const IGameManagerPtr& gameManager)
	:EnemyBase(
		world,
		ActorName::Enemy_01,
		position,
		front,
		1.0f,
		0,
		gameManager,
		std::make_shared<Texture>("Enemy01", gameManager->GetRenderer2D()),
		std::make_shared<OrientedBoundingBox>(GSvector2(0.0f, 0.0f), -90.0f, GSvector2(1.0f, 1.0f))) {
}

//クローン生成(使用時継承先でoverride)
ActorPtr Enemy01::clone(const GSvector2 & position, const FourDirection & front)
{
	return std::make_shared<Enemy01>(p_World, position, front, p_GameManager);
}

//各種固有のコマンドの設定
void Enemy01::SetUpCommand() {
	//生成
	p_CommandManager = std::make_shared<EnemyCommandManagerNormal>(shared_from_this());
	//Command追加
	p_CommandManager->AddDic(EnemyCommandName::Straight, std::make_shared<EnemyCommandEnemy01Straight>(shared_from_this()));
	p_CommandManager->AddDic(EnemyCommandName::AlongWallMoveShoest, std::make_shared<EnemyCommandEnemy01Detour>(shared_from_this()));
	//初期Command設定
	p_CommandManager->Change(EnemyCommandName::Straight);
}

//各種固有のStateの設定
void Enemy01::SetUpState() {
	//生成
	p_StateManager = new EnemyStateManager();
	//State追加
	p_StateManager->add(EnemyStateName::Idle, std::make_shared<EnemyStateMoveRepelIdle>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Move, std::make_shared<EnemyStateMoveRepelMove>(shared_from_this(), 4.0f));
	p_StateManager->add(EnemyStateName::Stop, std::make_shared<EnemyStateStop>(shared_from_this(), 120));
	p_StateManager->add(EnemyStateName::Repel, std::make_shared<EnemyStateRepel>(shared_from_this()));
	//初期State設定
	p_StateManager->change(EnemyStateName::Idle);
}

//描画
void Enemy01::onDraw() const {
	//p_Body->transform(getTransform())->draw();

	Texture2DParameter param;
	param.SetPosition(m_Transform.m_Position);
	param.SetCenter({ 16.0f, 16.0f });
	param.SetRect(*p_GameManager->GetRenderer2D()->GetTextureRect("Enemy01"));
	param.SetScale({ 1.0f , 1.0f });
	param.SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });
	p_GameManager->GetRenderer2D()->DrawTexture("Enemy01", param);
}