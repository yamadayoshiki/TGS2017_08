#include "EnemyBullet01.h"
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
#include "../../../CommandContains/Commands/EnemyBullet01Contains/Straight/EnemyCommandEB01Straight.h"
//State
#include "../../../StateContains/States/EnemyStateName.h"
#include "../../../StateContains/StateManager/EnemyStateManager.h"
#include "../../../StateContains/States/MoveContains/Standard/Idle/EnemyStateIdleStandard.h"
#include "../../../StateContains/States/MoveContains/Standard/Move/EnemyStateMoveStandard.h"
#include "../../../StateContains/States/CaughtContains/ReleaseDead/EnemyStateCaughtReleaseDead.h"
#include "../../../StateContains/States/CrushContains/Standard/EnemyStateCrushStandard.h"
#include "../../../StateContains/States/DeadContaint/Standard/EnemyStateDeadStandard.h"
#include "../../../StateContains/States/Damage/EnemyStateDamage.h"

EnemyBullet01::EnemyBullet01(
	IWorld * world,
	const GSvector2 & position,
	const FourDirection front,
	const IGameManagerPtr& gameManager)
	: EnemyBase(world,
		ActorName::Enemy_01,
		position,
		front,
		0,
		MapType::Double,
		gameManager,
		std::make_shared<AnimationTexture>("EnemyBullet01", gameManager->GetDrawManager(), DrawOrder::Enemy, 32, 8),
		Body::MotionType::Enemy, Body::BodyDataName::AABB_32) {
	int i = 0;
}

ActorPtr EnemyBullet01::CsvGenerate(const int x, const int y, const int csvparam) {
	GSvector2 position = CsvConvertTDV::CsvPosCnvVector2(x, y, m_MapType);
	FourDirection dir = FourDirection((FourDirectionName)csvparam);
	return std::make_shared<EnemyBullet01>(p_World, position, dir, p_GameManager);
}

void EnemyBullet01::SetUpCommand() {
	p_Texture->GetParameter()->m_Center = { 16.0f,16.0f };
	//¶¬
	p_CommandManager.reset(new EnemyCommandManagerNormal(shared_from_this()));
	//Command’Ç‰Á
	p_CommandManager->AddDic(EnemyCommandName::Straight, std::make_shared<EnemyCommandEB01Straight>(shared_from_this(), MapType::Double));
	//‰ŠúCommandÝ’è
	p_CommandManager->Change(EnemyCommandName::Straight);
}

void EnemyBullet01::SetUpState() {
	//¶¬
	p_StateManager.reset(new EnemyStateManager());
	//State’Ç‰Á
	p_StateManager->add(EnemyStateName::Idle, std::make_shared<EnemyStateIdleStandard>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Move, std::make_shared<EnemyStateMoveStandard>(shared_from_this(), 30.0f));
	p_StateManager->add(EnemyStateName::Caught, std::make_shared<EnemyStateCaughtReleaseDead>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Crush, std::make_shared<EnemyStateCrushStandard>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Dead, std::make_shared<EnemyStateDeadStandard>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Damage, std::make_shared<EnemyStateDamage>(shared_from_this()));
	//‰ŠúStateÝ’è
	p_StateManager->change(EnemyStateName::Idle);
}