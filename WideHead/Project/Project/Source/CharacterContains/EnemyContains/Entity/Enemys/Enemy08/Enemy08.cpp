#include "Enemy08.h"
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
#include "../../../../../Utility/Texture2DParameter/Texture2DParameter.h"
//CommandContains
#include "../../../CommandContains/CommandManagers/Nomal/EnemyCommandManagerNormal.h"
#include "../../../CommandContains/Commands/EnemyCommandName.h"
#include "../../../CommandContains/Commands/Common/Generate/EnemyCommandGenerate.h"
//State
#include "../../../StateContains/StateManager/EnemyStateManager.h"
#include "../../../StateContains/States/CaughtContains/Standard/EnemyStateCaughtStandard.h"
#include "../../../StateContains/States/CrushContains/Standard/EnemyStateCrushStandard.h"
#include "../../../StateContains/States/DeadContaint/Standard/EnemyStateDeadStandard.h"
#include "../../../StateContains/States/MoveContains/Standard/Idle/EnemyStateIdleStandard.h"
#include "../../../StateContains/States/MoveContains/Standard/Move/EnemyStateMoveStandard.h"
#include "../../../StateContains/States/StopContains/Standard/EnemyStateStopStandard.h"
#include "../../../../../TextureContains/AnimationTexture/AnimationTexture.h"
#include "../../../../../Utility/Animation/Animation.h"
#include "../../../../../DrawManager/DisplayMode.h"
#include "../../../StateContains/States/Damage/EnemyStateDamage.h"

Enemy08::Enemy08(
	IWorld * world,
	const GSvector2 & position,
	const FourDirection front,
	const IGameManagerPtr & gameManager)
	: EnemyBase(world,
		ActorName::Enemy_08,
		position,
		front,
		10,
		MapType::Double,
		gameManager,
		std::make_shared<NullTexture>(),
		Body::MotionType::Enemy, Body::BodyDataName::AABB_32) {
}

Enemy08::~Enemy08() {
}

ActorPtr Enemy08::CsvGenerate(const int x, const int y, const int csvparam) {
	GSvector2 position = CsvConvertTDV::CsvPosCnvVector2(x, y, m_MapType);
	FourDirection dir = FourDirection((FourDirectionName)csvparam);
	return std::make_shared<Enemy08>(p_World, position, dir, p_GameManager);
}

void Enemy08::SetUpCommand() {
	m_TextureMap["Normal"] = std::make_shared<AnimationTexture>("Enemy08Normal", p_GameManager->GetDrawManager(), DrawOrder::Enemy, 32, 8);
	m_TextureMap["Attack"] = std::make_shared<AnimationTexture>("Enemy08Attack", p_GameManager->GetDrawManager(), DrawOrder::Enemy, 32, 8);
	m_TextureMap["Normal"]->GetParameter()->m_Center = { 16.0f,16.0f };
	m_TextureMap["Attack"]->GetParameter()->m_Center = { 16.0f,16.0f };
	for (auto itr = m_TextureMap.begin(); itr != m_TextureMap.end(); itr++)
		itr->second->ChangeDisplayMode(DisplayMode::NonDisplay);

	p_Texture = m_TextureMap["Normal"];
	p_Texture->Initialize();
	p_Texture->ChangeDisplayMode(DisplayMode::Display);

	//¶¬
	p_CommandManager.reset(new EnemyCommandManagerNormal(shared_from_this()));
	//Command’Ç‰Á
	p_CommandManager->AddDic(EnemyCommandName::Generate, std::make_shared<EnemyCommandGenerate>(shared_from_this(), 24, 180));
	//‰ŠúCommandÝ’è
	p_CommandManager->Change(EnemyCommandName::Generate);
}

void Enemy08::SetUpState() {
	//¶¬
	p_StateManager.reset(new EnemyStateManager());
	//State’Ç‰Á
	p_StateManager->add(EnemyStateName::Caught, std::make_shared<EnemyStateCaughtStandard>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Crush, std::make_shared<EnemyStateCrushStandard>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Dead, std::make_shared<EnemyStateDeadStandard>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Idle, std::make_shared<EnemyStateIdleStandard>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Move, std::make_shared<EnemyStateMoveStandard>(shared_from_this(), 10.0f));
	p_StateManager->add(EnemyStateName::Stop, std::make_shared<EnemyStateStopStandard>(shared_from_this(), 120));
	p_StateManager->add(EnemyStateName::Damage, std::make_shared<EnemyStateDamage>(shared_from_this()));
	//‰ŠúStateÝ’è
	p_StateManager->change(EnemyStateName::Idle);
}