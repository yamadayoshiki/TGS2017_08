#include "Enemy06.h"
#include "../../../../../TextureContains/Texture/Texture.h"
#include "../../../../../Base/GameManagerContains/IGameManager.h"
#include "../../../../../Utility/Rederer2D/Renderer2D.h"
#include "../../../../../ActorContains/Body/OrientedBoundingBox.h"
//Map
#include "../../../../../WorldContains/IWorld.h"
#include "../../../../../Map/Map.h"
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

//コンストラクタ
Enemy06::Enemy06(
	IWorld * world,
	const GSvector2 & position,
	const FourDirection front,
	const IGameManagerPtr & gameManager)
	:EnemyBase(
		world,
		ActorName::Enemy_06,
		position,
		front,
		10,
		MapType::Double,
		gameManager,
		std::make_shared<Texture>("Enemy02", gameManager->GetRenderer2D()),
		std::make_shared<OrientedBoundingBox>(GSvector2(0.0f, 0.0f), -90.0f, GSvector2(1.0f, 1.0f))) {
}

ActorPtr Enemy06::CsvGenerate(const int x, const int y, const int csvparam)
{
	GSvector2 position = p_World->GetMap()->CsvPosCnvVector2(x, y, m_MapType);
	FourDirection dir = FourDirection((FourDirectionName)csvparam);
	return std::make_shared<Enemy06>(p_World, position, dir, p_GameManager);
}

//各種固有のコマンドの設定
void Enemy06::SetUpCommand() {
	p_Texture = std::make_shared<AnimationTexture>("Enemy06", p_GameManager->GetRenderer2D(), new Animation(*p_GameManager->GetRenderer2D()->GetTextureRect("Enemy06"), 32, 8));


	//生成
	p_CommandManager.reset(new EnemyCommandManagerNormal(shared_from_this()));
	//Command追加
	p_CommandManager->AddDic(EnemyCommandName::Generate, std::make_shared<EnemyCommandGenerate>(shared_from_this(), 23, 180));
	//初期Command設定
	p_CommandManager->Change(EnemyCommandName::Generate);
}

//各種固有のStateの設定
void Enemy06::SetUpState() {
	//生成
	p_StateManager.reset(new EnemyStateManager());
	//State追加
	p_StateManager->add(EnemyStateName::Caught, std::make_shared<EnemyStateCaughtStandard>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Crush, std::make_shared<EnemyStateCrushStandard>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Dead, std::make_shared<EnemyStateDeadStandard>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Idle, std::make_shared<EnemyStateIdleStandard>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Move, std::make_shared<EnemyStateMoveStandard>(shared_from_this(), 10.0f));
	p_StateManager->add(EnemyStateName::Stop, std::make_shared<EnemyStateStopStandard>(shared_from_this(), 120));
	//初期State設定
	p_StateManager->change(EnemyStateName::Idle);
}

//描画
void Enemy06::onDraw() const {
	p_Texture->GetParameter()->SetPosition(m_Transform.m_Position);
	p_Texture->GetParameter()->SetRotate(m_Transform.m_Angle - 90);
	p_Texture->GetParameter()->SetCenter({ 16.0f, 16.0f });
	p_Texture->GetParameter()->SetScale({ 1.0f , 1.0f });
	p_Texture->GetParameter()->SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });
	//アニメーションの描画
	p_Texture->Draw();
}