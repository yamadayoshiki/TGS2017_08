#include "Enemy04.h"
#include "../../../../../ActorContains/ActorName.h"
#include "../../../../../TextureContains/Texture/Texture.h"
#include "../../../../../Base/GameManagerContains/IGameManager.h"
#include "../../../../../Utility/Rederer2D/Renderer2D.h"
#include "../../../../../Utility/FourDirection/FourDirection.h"
#include "../../../../../Utility/MathSupport/MathSupport.h"
#include "../../../../../Utility/TurnDirection/TurnDirection.h"
#include "../../../../../ActorContains/Body/OrientedBoundingBox.h"
//Map
#include "../../../../../WorldContains/IWorld.h"
#include "../../../../../Map/Map.h"
//CommandContains
#include "../../../CommandContains/CommandManagers/Nomal/EnemyCommandManagerNormal.h"
#include "../../../CommandContains/Commands/EnemyCommandName.h"
#include "../../../CommandContains/Commands/Enemy04Contains/Standby/EnemyCommandEnemy04Standby.h"

//State
#include "../../../StateContains/StateManager/EnemyStateManager.h"
#include "../../../StateContains/States/CaughtContains/Standard/EnemyStateCaughtStandard.h"
#include "../../../StateContains/States/CrushContains/Standard/EnemyStateCrushStandard.h"
#include "../../../StateContains/States/DeadContaint/Standard/EnemyStateDeadStandard.h"
#include "../../../StateContains/States/MoveContains/Standard/Idle/EnemyStateIdleStandard.h"
#include "../../../StateContains/States/MoveContains/Standard/Move/EnemyStateMoveStandard.h"
#include "../../../StateContains/States/Stop/EnemyStateStop.h"

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
		100,
		MapType::Double,
		gameManager,
		std::make_shared<Texture>("Enemy02", gameManager->GetRenderer2D()),
		std::make_shared<OrientedBoundingBox>(GSvector2(0.0f, 0.0f), -90.0f, GSvector2(1.0f, 1.0f))) {
}

ActorPtr Enemy04::CsvGenerate(const int x, const int y, const int csvparam)
{
	GSvector2 position = p_World->GetMap()->CsvPosCnvVector2(x, y, m_MapType);
	FourDirection dir = FourDirection((FourDirectionName)csvparam);
	return std::make_shared<Enemy04>(p_World, position, dir, p_GameManager);
}

void Enemy04::SetUpCommand() {
	//¶¬
	p_CommandManager.reset(new EnemyCommandManagerNormal(shared_from_this()));
	//Command’Ç‰Á
	p_CommandManager->AddDic(EnemyCommandName::Standby, std::make_shared<EnemyCommandEnemy04Standby>(shared_from_this(), m_FourDirection));
	//‰ŠúCommandÝ’è
	p_CommandManager->Change(EnemyCommandName::Standby);
}

void Enemy04::SetUpState() {
	//¶¬
	p_StateManager.reset(new EnemyStateManager());
	//State’Ç‰Á
	p_StateManager->add(EnemyStateName::Caught, std::make_shared<EnemyStateCaughtStandard>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Crush, std::make_shared<EnemyStateCrushStandard>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Dead, std::make_shared<EnemyStateDeadStandard>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Idle, std::make_shared<EnemyStateIdleStandard>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Move, std::make_shared<EnemyStateMoveStandard>(shared_from_this(), 10.0f));
	p_StateManager->add(EnemyStateName::Stop, std::make_shared<EnemyStateStop>(shared_from_this(), 120));
	//‰ŠúStateÝ’è
	p_StateManager->change(EnemyStateName::Idle);
}

void Enemy04::onDraw() const {
	Texture2DParameter param;
	param.SetPosition(m_Transform.m_Position);
	param.SetRotate(m_Transform.m_Angle + 90);
	param.SetCenter({ 16.0f, 16.0f });
	param.SetRect(*p_GameManager->GetRenderer2D()->GetTextureRect("Enemy02"));
	param.SetScale({ 1.0f , 1.0f });
	param.SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });
	p_GameManager->GetRenderer2D()->DrawTexture("Enemy02", param);
}
