#include "Enemy02.h"
#include "../../../../ActorContains/ActorName.h"
#include "../../../../TextureContains/Texture/Texture.h"
#include "../../../../Base/GameManagerContains/IGameManager.h"
#include "../../../../Utility/Rederer2D/Renderer2D.h"
#include "../../../../Utility/FourDirection/FourDirection.h"

//CommandContains
#include "../../CommandContains/CommandManagers/Nomal/EnemyCommandManagerNormal.h"
#include "../../CommandContains/Commands/EnemyCommandName.h"
#include "../../CommandContains/Commands/Enemy02Contains/Standby/EnemyCommandEnemy02Standby.h"

//State
#include "../../StateContains/States/Caught/EnemyStateCaught.h"
#include "../../StateContains/States/Crush/EnemyStateCrush.h"
#include "../../StateContains/States/Dead/EnemyStateDead.h"
#include "../../StateContains/States/Enemy02Contains/MoveContains/Idle/EnemyStateEnemy02Idle.h"
#include "../../StateContains/States/Enemy02Contains/MoveContains/Move/EnemyStateEnemy02Move.h"
#include "../../StateContains/States/Repel/EnemyStateRepel.h"
#include "../../StateContains/States/Stop/EnemyStateStop.h"

#include "../../../../Utility/TurnDirection/TurnDirection.h"
#include "../../../../ActorContains/Body/OrientedBoundingBox.h"


//コンストラクタ
Enemy02::Enemy02(
	IWorld* world,
	const GSvector2& position,
	const FourDirection front,
	const FourDirection turnDirection,
	const IGameManagerPtr& gameManager)
	:EnemyBase(
		world,
		ActorName::Enemy_02,
		position,
		front,
		1.0f,
		10,
		gameManager,
		std::make_shared<Texture>("Enemy01", gameManager->GetRenderer2D()),
		std::make_shared<OrientedBoundingBox>(GSvector2(0.0f, 0.0f), -90.0f, GSvector2(1.0f, 1.0f)))
	, m_TurnDirection(turnDirection) {
}

void Enemy02::SetUpCommand() {
	//生成
	p_CommandManager = std::make_shared<EnemyCommandManagerNormal>(shared_from_this());
	//コマンド追加
	p_CommandManager->AddDic(EnemyCommandName::Standby, std::make_shared<EnemyCommandEnemy02Standby>(shared_from_this(), m_TurnDirection));
	//初期設定
	p_CommandManager->Change(EnemyCommandName::Standby);
}

void Enemy02::SetUpState() {
	//生成
	p_StateManager = new EnemyStateManager();
	//State追加
	p_StateManager->add(EnemyStateName::Caught, std::make_shared<EnemyStateCaught>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Crush, std::make_shared<EnemyStateCrush>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Dead, std::make_shared<EnemyStateDead>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Idle, std::make_shared<EnemyStateEnemy02Idle>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Move, std::make_shared<EnemyStateEnemy02Move>(shared_from_this(), 10.0f));
	p_StateManager->add(EnemyStateName::Repel, std::make_shared<EnemyStateRepel>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Stop, std::make_shared<EnemyStateStop>(shared_from_this(), 120));
	//初期State設定
	p_StateManager->change(EnemyStateName::Idle);
}

void Enemy02::onDraw() const {
	p_Body->transform(getTransform())->draw();

}

