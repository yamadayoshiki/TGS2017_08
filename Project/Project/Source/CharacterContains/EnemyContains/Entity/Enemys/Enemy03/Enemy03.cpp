#include "Enemy03.h"
#include "../../../../../ActorContains/ActorName.h"
#include "../../../../../TextureContains/Texture/Texture.h"
#include "../../../../../Base/GameManagerContains/IGameManager.h"
#include "../../../../../Utility/Rederer2D/Renderer2D.h"
#include "../../../../../Utility/FourDirection/FourDirection.h"
//Map
#include "../../../../../WorldContains/IWorld.h"
#include "../../../../../Map/Map.h"
//CommandContains
#include "../../../CommandContains/CommandManagers/Nomal/EnemyCommandManagerNormal.h"
#include "../../../CommandContains/Commands/EnemyCommandName.h"
#include "../../../CommandContains/Commands/Common/MoveContains/AlongWallMove/EnemyCommandAlongWallMove.h"

//State
#include "../../../StateContains/StateManager/EnemyStateManager.h"
#include "../../../StateContains/States/MoveContains/Repel/Idle/EnemyStateIdleRepel.h"
#include "../../../StateContains/States/MoveContains/Repel/Move/EnemyStateMoveRepel.h"
#include "../../../StateContains/States/RepelContains/Repel/EnemyStateRepel.h"

#include "../../../../../Utility/TurnDirection/TurnDirection.h"
#include "../../../../../ActorContains/Body/OrientedBoundingBox.h"

//コンストラクタ
Enemy03::Enemy03(
	IWorld* world,
	const GSvector2& position,
	const FourDirection front,
	const TurnDirection turnDirection,
	const IGameManagerPtr& gameManager)
	:EnemyBase(
		world,
		ActorName::Enemy_03,
		position,
		front,
		0,
		MapType::Default,
		gameManager,
		std::make_shared<Texture>("Enemy03", gameManager->GetRenderer2D()),
		std::make_shared<OrientedBoundingBox>(GSvector2(0.0f, 0.0f), -90.0f, GSvector2(1.0f, 1.0f)))
	, m_TurnDirection(turnDirection) {
}

ActorPtr Enemy03::CsvGenerate(const int x, const int y, const int csvparam) {
	GSvector2 position = p_World->GetMap()->CsvPosCnvVector2(x, y, m_MapType);
	FourDirection dir = FourDirection((FourDirectionName)MathSupport::GetCutNum(csvparam, 1, 1));
	//TurnDirection turnDir = TurnDirection((TurnDirectionName)MathSupport::GetCutNum(csvparam, 2, 1));
	return std::make_shared<Enemy03>(p_World, position, dir, m_TurnDirection, p_GameManager);
}

void Enemy03::SetUpCommand() {
	//生成
	p_CommandManager.reset(new EnemyCommandManagerNormal(shared_from_this()));
	//Command追加
	p_CommandManager->AddDic(EnemyCommandName::AlongWall, std::make_shared<EnemyCommandAlongWallMove>(shared_from_this(), MapType::Default, m_TurnDirection));
	//初期Command設定
	p_CommandManager->Change(EnemyCommandName::AlongWall);
}

void Enemy03::SetUpState()
{
	//生成
	p_StateManager.reset(new EnemyStateManager());
	//State追加
	p_StateManager->add(EnemyStateName::Idle, std::make_shared<EnemyStateIdleRepel>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Move, std::make_shared<EnemyStateMoveRepel>(shared_from_this(), 10.0f));
	p_StateManager->add(EnemyStateName::Repel, std::make_shared<EnemyStateRepel>(shared_from_this()));
	//初期State設定
	p_StateManager->change(EnemyStateName::Idle);
}

void Enemy03::onDraw() const {
	//p_Body->transform(getTransform())->draw();

	Texture2DParameter param;
	param.SetPosition(m_Transform.m_Position);
	param.SetCenter({ 16.0f, 16.0f });
	param.SetRect(*p_GameManager->GetRenderer2D()->GetTextureRect("Enemy03"));
	param.SetScale({ 1.0f , 1.0f });
	param.SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });
	p_GameManager->GetRenderer2D()->DrawTexture("Enemy03", param);
}
