#include "Enemy09.h"
#include "../../../../../ActorContains/ActorName.h"
#include "../../../../../ActorContains/Transform/Transform.h"
#include "../../../../../Base/GameManagerContains/IGameManager.h"
#include "../../../../../Define/Def_Nakayama.h"
#include "../../../../../TextureContains/Texture/Texture.h"
#include "../../../../../TextureContains/AnimationTexture/AnimationTexture.h"
#include "../../../../../CsvConvertTDV/CsvConvertTDV.h"
#include "../../../../../Utility/Rederer2D/Renderer2D.h"
#include "../../../../../Utility/FourDirection/FourDirection.h"
#include "../../../../../Utility/Animation/Animation.h"
//CommandContains
#include "../../../CommandContains/CommandManagers/Nomal/EnemyCommandManagerNormal.h"
#include "../../../CommandContains/Commands/EnemyCommandName.h"
#include "../../../CommandContains/Commands/Enemy09Contains/Standby/EnemyCommandEnemy09Standby.h"
#include "../../../CommandContains/Commands/Common/AttackContains/Rush/EnemyCommandRush.h"
#include "../../../CommandContains/Commands/Enemy09Contains/Rush/EnemyCommandEnemy09Rush.h"
#include "../../../CommandContains/Commands/Common/MoveContains/ReturnRegularPos/EnemyCommandReturnRegularPos.h"
//State
#include "../../../StateContains/StateManager/EnemyStateManager.h"
#include "../../../StateContains/States/CaughtContains/Standard/EnemyStateCaughtStandard.h"
#include "../../../StateContains/States/CrushContains/Standard/EnemyStateCrushStandard.h"
#include "../../../StateContains/States/DeadContaint/Standard/EnemyStateDeadStandard.h"
#include "../../../StateContains/States/MoveContains/OnlyInTheBack/Idle/EnemyStateIdleOnlyInTheBack.h"
#include "../../../StateContains/States/MoveContains/OnlyInTheBack/Move/EnemyStateMoveOnlyInTheBack.h"
#include "../../../StateContains/States/AttackContains/Rush/EnemyStateRush.h"
#include "../../../StateContains/States/StopContains/OnlyInTheBack/EnemyStateStopOnlyInTheBack.h"
#include "../../../StateContains/States/RepelContains/Repel/EnemyStateRepel.h"
#include "../../../StateContains/States/Damage/EnemyStateDamage.h"
#include "../../../StateContains/States/AttackContains/RushPreliminary/EnemyStateRushPreliminary.h"
#include "../../../../../TextureContains/AnimationTexture/AnimationTexture.h"
#include "../../../../../Utility/Texture2DParameter/Texture2DParameter.h"
#include "../../../../../DrawManager/DisplayMode.h"
Enemy09::Enemy09(
	IWorld * world,
	const GSvector2 & position,
	const FourDirection front,
	const IGameManagerPtr & gameManager)
	:EnemyBase(
		world,
		ActorName::Enemy_09,
		position,
		front,
		10,
		MapType::Double,
		gameManager,
		std::make_shared<Texture>("Enemy09", gameManager->GetDrawManager(), DrawOrder::Enemy),
		Body::MotionType::Enemy, Body::BodyDataName::AABB_32) {
}

Enemy09::~Enemy09() {
}

ActorPtr Enemy09::CsvGenerate(const int x, const int y, const int csvparam)
{
	GSvector2 position = CsvConvertTDV::CsvPosCnvVector2(x, y, m_MapType);
	FourDirection dir = FourDirection((FourDirectionName)csvparam);
	return std::make_shared<Enemy09>(p_World, position, dir, p_GameManager);
}

void Enemy09::SetUpCommand() {
	m_TextureMap["Normal"] = std::make_shared<Texture>("Enemy09", p_GameManager->GetDrawManager(), DrawOrder::Enemy);
	m_TextureMap["Rush"] = std::make_shared<Texture>("Enemy09", p_GameManager->GetDrawManager(), DrawOrder::Enemy);
	m_TextureMap["RushPreliminary"] = std::make_shared<AnimationTexture>("Enemy09RushPreliminary", p_GameManager->GetDrawManager(), DrawOrder::Enemy, 32, 6);

	for (auto itr = m_TextureMap.begin(); itr != m_TextureMap.end(); itr++)
		itr->second->ChangeDisplayMode(DisplayMode::NonDisplay);

	p_Texture = m_TextureMap["Normal"];
	p_Texture->Initialize();
	p_Texture->ChangeDisplayMode(DisplayMode::Display);

	//¶¬
	p_CommandManager.reset(new EnemyCommandManagerNormal(shared_from_this()));
	//Command’Ç‰Á
	p_CommandManager->AddDic(EnemyCommandName::Standby, std::make_shared<EnemyCommandEnemy09Standby>(shared_from_this()));
	p_CommandManager->AddDic(EnemyCommandName::Rush, std::make_shared<EnemyCommandRush>(shared_from_this(), m_MapType));
	p_CommandManager->AddDic(EnemyCommandName::ReturnToTheRegularPosition, std::make_shared<EnemyCommandReturnRegularPos>(shared_from_this(), m_MapType));
	//‰ŠúCommandÝ’è
	p_CommandManager->Change(EnemyCommandName::Standby);
}

void Enemy09::SetUpState() {
	//¶¬
	p_StateManager.reset(new EnemyStateManager());
	//State’Ç‰Á
	p_StateManager->add(EnemyStateName::Idle, std::make_shared<EnemyStateIdleOnlyInTheBack>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Move, std::make_shared<EnemyStateMoveOnlyInTheBack>(shared_from_this(), 4.0f));
	p_StateManager->add(EnemyStateName::Stop, std::make_shared<EnemyStateStopOnlyInTheBack>(shared_from_this(), 120));
	p_StateManager->add(EnemyStateName::Repel, std::make_shared<EnemyStateRepel>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Caught, std::make_shared<EnemyStateCaughtStandard>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Crush, std::make_shared<EnemyStateCrushStandard>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Dead, std::make_shared<EnemyStateDeadStandard>(shared_from_this()));
	p_StateManager->add(EnemyStateName::StickWall, std::make_shared<EnemyStateStopOnlyInTheBack>(shared_from_this(), 180));
	p_StateManager->add(EnemyStateName::RushPreliminary, std::make_shared<EnemyStateRushPreliminary>(shared_from_this(), 1));
	p_StateManager->add(EnemyStateName::Rush, std::make_shared<EnemyStateRush>(shared_from_this(), 10.0f));
	p_StateManager->add(EnemyStateName::Damage, std::make_shared<EnemyStateDamage>(shared_from_this()));
	//‰ŠúStateÝ’è
	p_StateManager->change(EnemyStateName::Idle);
}

void Enemy09::onDraw() const {
}

