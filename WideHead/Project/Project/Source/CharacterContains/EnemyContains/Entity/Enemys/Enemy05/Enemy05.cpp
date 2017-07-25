#include "Enemy05.h"
#include "../../../../../ActorContains/ActorName.h"
#include "../../../../../ActorContains/Transform/Transform.h"
#include "../../../../../Base/GameManagerContains/IGameManager.h"
#include "../../../../../Define/Def_Nakayama.h"
#include "../../../../../TextureContains/AnimationTexture/AnimationTexture.h"
#include "../../../../../TextureContains/AnimationTexture/AnimationTexture.h"
#include "../../../../../CsvConvertTDV/CsvConvertTDV.h"
#include "../../../../../Utility/Rederer2D/Renderer2D.h"
#include "../../../../../Utility/FourDirection/FourDirection.h"
#include "../../../../../Utility/Animation/Animation.h"
//CommandContains
#include "../../../CommandContains/CommandManagers/Nomal/EnemyCommandManagerNormal.h"
#include "../../../CommandContains/Commands/EnemyCommandName.h"
#include "../../../CommandContains/Commands/Common/MoveContains/Straight/EnemyCommandStraight.h"

//State
#include "../../../StateContains/StateManager/EnemyStateManager.h"
#include "../../../StateContains/States/CaughtContains/Standard/EnemyStateCaughtStandard.h"
#include "../../../StateContains/States/CrushContains/Standard/EnemyStateCrushStandard.h"
#include "../../../StateContains/States/DeadContaint/Standard/EnemyStateDeadStandard.h"
#include "../../../StateContains/States/MoveContains/Standard/Idle/EnemyStateIdleStandard.h"
#include "../../../StateContains/States/MoveContains/Standard/Move/EnemyStateMoveStandard.h"
#include "../../../StateContains/States/StopContains/Standard/EnemyStateStopStandard.h"
#include "../../../StateContains/States/Damage/EnemyStateDamage.h"

Enemy05::Enemy05(
	IWorld * world,
	const GSvector2 & position,
	const FourDirection front,
	const IGameManagerPtr & gameManager)
	:EnemyBase(
		world,
		ActorName::Enemy_05,
		position,
		front,
		10,
		MapType::Double,
		gameManager,
		std::make_shared<AnimationTexture>("Enemy05", gameManager->GetDrawManager(), DrawOrder::Enemy, 32, 8),
		Body::MotionType::Enemy, Body::BodyDataName::AABB_32) {
}

ActorPtr Enemy05::CsvGenerate(const int x, const int y, const int csvparam)
{
	GSvector2 position = CsvConvertTDV::CsvPosCnvVector2(x, y, m_MapType);
	FourDirection dir = FourDirection((FourDirectionName)csvparam);
	return std::make_shared<Enemy05>(p_World, position, dir, p_GameManager);
}

//�e��ŗL�̃R�}���h�̐ݒ�
void Enemy05::SetUpCommand() {
	//����
	p_CommandManager.reset(new EnemyCommandManagerNormal(shared_from_this()));
	//Command�ǉ�
	p_CommandManager->AddDic(EnemyCommandName::Straight, std::make_shared<EnemyCommandStraight>(shared_from_this(), MapType::Double));
	//����Command�ݒ�
	p_CommandManager->Change(EnemyCommandName::Straight);
}

//�e��ŗL��State�̐ݒ�
void Enemy05::SetUpState() {
	//����
	p_StateManager.reset(new EnemyStateManager());
	//State�ǉ�
	p_StateManager->add(EnemyStateName::Caught, std::make_shared<EnemyStateCaughtStandard>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Crush, std::make_shared<EnemyStateCrushStandard>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Dead, std::make_shared<EnemyStateDeadStandard>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Idle, std::make_shared<EnemyStateIdleStandard>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Move, std::make_shared<EnemyStateMoveStandard>(shared_from_this(), 5.0f));
	p_StateManager->add(EnemyStateName::Stop, std::make_shared<EnemyStateStopStandard>(shared_from_this(), 120));
	p_StateManager->add(EnemyStateName::Damage, std::make_shared<EnemyStateDamage>(shared_from_this()));
	//����State�ݒ�
	p_StateManager->change(EnemyStateName::Idle);
}

//�`��
void Enemy05::onDraw() const {
}