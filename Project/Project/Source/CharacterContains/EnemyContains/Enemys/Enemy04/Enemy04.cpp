#include "Enemy04.h"
#include "../../../../ActorContains/ActorName.h"
#include "../../../../TextureContains/Texture/Texture.h"
#include "../../../../Base/GameManagerContains/IGameManager.h"
#include "../../../../Utility/Rederer2D/Renderer2D.h"
#include "../../../../Utility/FourDirection/FourDirection.h"
#include "../../../../Utility/MathSupport/MathSupport.h"
#include "../../../../Utility/TurnDirection/TurnDirection.h"
#include "../../../../ActorContains/Body/OrientedBoundingBox.h"

//CommandContains
#include "../../CommandContains/CommandManagers/Nomal/EnemyCommandManagerNormal.h"
#include "../../CommandContains/Commands/EnemyCommandName.h"
#include "../../CommandContains/Commands/Enemy04Contains/Standby/EnemyCommandEnemy04Standby.h"

//State
#include "../../StateContains/States/Caught/EnemyStateCaught.h"
#include "../../StateContains/States/Crush/EnemyStateCrush.h"
#include "../../StateContains/States/Dead/EnemyStateDead.h"
#include "../../StateContains/States/MoveContains/Idle/EnemyStateIdle.h"
#include "../../StateContains/States/MoveContains/Move/EnemyStateMove.h"
#include "../../StateContains/States/Stop/EnemyStateStop.h"

Enemy04::Enemy04(
	IWorld * world,
	const GSvector2 & position,
	const FourDirection & front,
	const IGameManagerPtr & gameManager)
	:EnemyBase(
		world,
		ActorName::Enemy_04,
		position,
		front,
		1.0f,
		100,
		gameManager,
		std::make_shared<Texture>("Enemy04", gameManager->GetRenderer2D()),
		std::make_shared<OrientedBoundingBox>(GSvector2(0.0f, 0.0f), -90.0f, GSvector2(1.0f, 1.0f))) {
}

//クローン生成(使用時継承先でoverride)
ActorPtr Enemy04::clone(const GSvector2 & position, const FourDirection & front)
{
	return std::make_shared<Enemy04>(p_World, position, front, p_GameManager);
}

void Enemy04::SetUpCommand() {
	//生成
	p_CommandManager = std::make_shared<EnemyCommandManagerNormal>(shared_from_this());
	//Command追加
	p_CommandManager->AddDic(EnemyCommandName::Standby, std::make_shared<EnemyCommandEnemy04Standby>(shared_from_this(), m_FourDirection));
	//初期Command設定
	p_CommandManager->Change(EnemyCommandName::Standby);
}

void Enemy04::SetUpState() {
	//生成
	p_StateManager = new EnemyStateManager();
	//State追加
	p_StateManager->add(EnemyStateName::Caught, std::make_shared<EnemyStateCaught>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Crush, std::make_shared<EnemyStateCrush>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Dead, std::make_shared<EnemyStateDead>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Idle, std::make_shared<EnemyStateIdle>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Move, std::make_shared<EnemyStateMove>(shared_from_this(), 10.0f));
	p_StateManager->add(EnemyStateName::Stop, std::make_shared<EnemyStateStop>(shared_from_this(), 120));
	//初期State設定
	p_StateManager->change(EnemyStateName::Idle);
}

void Enemy04::onDraw() const {
	Texture2DParameter param;
	param.SetPosition(m_Transform.m_Position);
	param.SetRotate(m_Transform.m_Angle + 90);
	param.SetCenter({ 16.0f, 16.0f });
	param.SetRect(*p_GameManager->GetRenderer2D()->GetTextureRect("Enemy04"));
	param.SetScale({ 1.0f , 1.0f });
	param.SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });
	p_GameManager->GetRenderer2D()->DrawTexture("Enemy04", param);
}
