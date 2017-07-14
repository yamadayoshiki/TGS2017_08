#include "Enemy03.h"
#include "../../../../../ActorContains/ActorName.h"
#include "../../../../../ActorContains/Transform/Transform.h"
#include "../../../../../Base/GameManagerContains/IGameManager.h"
#include "../../../../../Define/Def_Nakayama.h"
#include "../../../../../TextureContains/Texture/Texture.h"
#include "../../../../../TextureContains/AnimationTexture/AnimationTexture.h"
#include "../../../../../Utility/CsvConvertTwoDVector/CsvConvertTwoDVector.h"
#include "../../../../../Utility/Rederer2D/Renderer2D.h"
#include "../../../../../Utility/FourDirection/FourDirection.h"
#include "../../../../../Utility/Animation/Animation.h"
#include "../../../../../Utility/MathSupport/MathSupport.h"
#include "../../../../../Utility/Texture2DParameter/Texture2DParameter.h"
//CommandContains
#include "../../../CommandContains/CommandManagers/Nomal/EnemyCommandManagerNormal.h"
#include "../../../CommandContains/Commands/EnemyCommandName.h"
#include "../../../CommandContains/Commands/Common/MoveContains/AlongWallMove/EnemyCommandAlongWallMove.h"

//State
#include "../../../StateContains/StateManager/EnemyStateManager.h"
#include "../../../StateContains/States/MoveContains/Repel/Idle/EnemyStateIdleRepel.h"
#include "../../../StateContains/States/MoveContains/Repel/Move/EnemyStateMoveRepel.h"
#include "../../../StateContains/States/RepelContains/Repel/EnemyStateRepel.h"

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
		std::make_shared<AnimationTexture>("Enemy03", gameManager->GetDrawManager(), DrawOrder::Enemy, 32, 8),
		Body::MotionType::Enemy, Body::BodyDataName::AABB_32)
	, m_TurnDirection(turnDirection) {
}

ActorPtr Enemy03::CsvGenerate(const int x, const int y, const int csvparam) {
	GSvector2 position = CsvConvertTwoDVector::CsvPosCnvVector2(x, y, m_MapType);
	FourDirection dir = FourDirection((FourDirectionName)MathSupport::GetCutNum(csvparam, 1, 1));
	//TurnDirection turnDir = TurnDirection((TurnDirectionName)MathSupport::GetCutNum(csvparam, 2, 1));
	return std::make_shared<Enemy03>(p_World, position, dir, m_TurnDirection, p_GameManager);
}

void Enemy03::SetUpCommand() {
	p_Texture->GetParameter()->m_Center = { 16.0f, 16.0f };
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
	p_StateManager->add(EnemyStateName::Move, std::make_shared<EnemyStateMoveRepel>(shared_from_this(), 4.0f));
	p_StateManager->add(EnemyStateName::Repel, std::make_shared<EnemyStateRepel>(shared_from_this()));
	//初期State設定
	p_StateManager->change(EnemyStateName::Idle);
}

void Enemy03::onDraw() const {
}
