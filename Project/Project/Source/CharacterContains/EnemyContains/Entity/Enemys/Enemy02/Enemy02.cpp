#include "Enemy02.h"
#include "../../../../../ActorContains/ActorName.h"
#include "../../../../../ActorContains/BodyContains/AARectangle/AARectangle.h"
#include "../../../../../ActorContains/Transform/Transform.h"
#include "../../../../../TextureContains/Texture/Texture.h"
#include "../../../../../Base/GameManagerContains/IGameManager.h"
#include "../../../../../Utility/Rederer2D/Renderer2D.h"
#include "../../../../../Utility/FourDirection/FourDirection.h"
#include "../../../../../Utility/TurnDirection/TurnDirection.h"
#include "../../../../../Utility/CsvConvertTwoDVector/CsvConvertTwoDVector.h"
#include "../../../../../Utility/MathSupport/MathSupport.h"
#include "../../../../../Define/Def_Nakayama.h"
//CommandContains
#include "../../../CommandContains/CommandManagers/Nomal/EnemyCommandManagerNormal.h"
#include "../../../CommandContains/Commands/EnemyCommandName.h"
#include "../../../CommandContains/Commands/Enemy02Contains/Standby/EnemyCommandEnemy02Standby.h"
//State
#include "../../../StateContains/StateManager/EnemyStateManager.h"
#include "../../../StateContains/States/CaughtContains/Standard/EnemyStateCaughtStandard.h"
#include "../../../StateContains/States/CrushContains/Standard/EnemyStateCrushStandard.h"
#include "../../../StateContains/States/DeadContaint/Inform/EnemyStateDeadInform.h"
#include "../../../StateContains/States/MoveContains/OnlyInTheBack/Idle/EnemyStateIdleOnlyInTheBack.h"
#include "../../../StateContains/States/MoveContains/OnlyInTheBack/Move/EnemyStateMoveOnlyInTheBack.h"
#include "../../../StateContains/States/RepelContains/Repel/EnemyStateRepel.h"
#include "../../../StateContains/States/StopContains/OnlyInTheBack/EnemyStateStopOnlyInTheBack.h"



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
		10,
		MapType::Double,
		gameManager,
		std::make_shared<Texture>("Enemy01", gameManager->GetRenderer2D()),
		std::make_shared<Body::AARectangle>(CHIP_SIZE, CHIP_SIZE))
	, m_TurnDirection(turnDirection) {
}

ActorPtr Enemy02::CsvGenerate(const int x, const int y, const int csvparam)
{
	GSvector2 position = CsvConvertTwoDVector::CsvPosCnvVector2(x, y, m_MapType);
	FourDirection dir = FourDirection((FourDirectionName)MathSupport::GetCutNum(csvparam, 1, 1));
	//FourDirection turnDir = FourDirection((FourDirectionName)MathSupport::GetCutNum(csvparam, 2, 1));
	return std::make_shared<Enemy02>(p_World, position, dir, m_TurnDirection, p_GameManager);
}

void Enemy02::SetUpCommand() {
	//生成
	p_CommandManager.reset(new EnemyCommandManagerNormal(shared_from_this()));
	//コマンド追加
	p_CommandManager->AddDic(EnemyCommandName::Standby, std::make_shared<EnemyCommandEnemy02Standby>(shared_from_this(), m_TurnDirection));
	//初期設定
	p_CommandManager->Change(EnemyCommandName::Standby);
}

void Enemy02::SetUpState() {
	//生成
	p_StateManager.reset(new EnemyStateManager());
	//State追加
	p_StateManager->add(EnemyStateName::Caught, std::make_shared<EnemyStateCaughtStandard>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Crush, std::make_shared<EnemyStateCrushStandard>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Dead, std::make_shared<EnemyStateDeadInform>(shared_from_this(), m_Name));
	p_StateManager->add(EnemyStateName::Idle, std::make_shared<EnemyStateIdleOnlyInTheBack>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Move, std::make_shared<EnemyStateMoveOnlyInTheBack>(shared_from_this(), 10.0f));
	p_StateManager->add(EnemyStateName::Repel, std::make_shared<EnemyStateRepel>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Stop, std::make_shared<EnemyStateStopOnlyInTheBack>(shared_from_this(), 120));
	//初期State設定
	p_StateManager->change(EnemyStateName::Idle);
}

void Enemy02::onDraw() const {
	Texture2DParameter param;
	param.SetPosition(p_Transform->m_Position);
	param.SetRotate(p_Transform->m_Angle + 90);
	param.SetCenter({ 16.0f, 16.0f });
	param.SetRect(*p_GameManager->GetRenderer2D()->GetTextureRect("Enemy02"));
	param.SetScale({ 1.0f , 1.0f });
	param.SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });
	p_GameManager->GetRenderer2D()->DrawTexture("Enemy02", param);
}

