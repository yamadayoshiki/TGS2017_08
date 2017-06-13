#include "EnemyBullet01.h"
//コンストラクタ
#include "../../../../../ActorContains/ActorName.h"
#include "../../../../../TextureContains/Texture/Texture.h"
#include "../../../../../ActorContains/Body/OrientedBoundingBox.h"
#include "../../../../../Utility/CsvConvertTwoDVector/CsvConvertTwoDVector.h"
//描画
#include "../../../../../Base/GameManagerContains/IGameManager.h"
#include "../../../../../Utility/Rederer2D/Renderer2D.h"
//CommandContains
#include "../../../CommandContains/CommandManagers/Nomal/EnemyCommandManagerNormal.h"
#include "../../../CommandContains/Commands/EnemyCommandName.h"
#include "../../../CommandContains/Commands/EnemyBullet01Contains/Straight/EnemyCommandEnemyBullet01StraightTouchWall.h"
//State
#include "../../../StateContains/States/EnemyStateName.h"
#include "../../../StateContains/StateManager/EnemyStateManager.h"
#include "../../../StateContains/States/MoveContains/Standard/Idle/EnemyStateIdleStandard.h"
#include "../../../StateContains/States/MoveContains/Standard/Move/EnemyStateMoveStandard.h"
#include "../../../StateContains/States/CaughtContains/ReleaseDead/EnemyStateCaughtReleaseDead.h"
#include "../../../StateContains/States/CrushContains/Standard/EnemyStateCrushStandard.h"
#include "../../../StateContains/States/DeadContaint/Standard/EnemyStateDeadStandard.h"


EnemyBullet01::EnemyBullet01(
	IWorld * world, 
	const GSvector2 & position, 
	const FourDirection front, 
	const IGameManagerPtr & gameManager)
: EnemyBase(world,
	ActorName::Enemy_01,
	position,
	front,
	0,
	MapType::Double,
	gameManager,
	std::make_shared<Texture>("Enemy01", gameManager->GetRenderer2D()),
	std::make_shared<OrientedBoundingBox>(GSvector2(0.0f, 0.0f), -90.0f, GSvector2(1.0f, 1.0f))) {
}

ActorPtr EnemyBullet01::CsvGenerate(const int x, const int y, const int csvparam){
	GSvector2 position = CsvConvertTwoDVector::CsvPosCnvVector2(x, y, m_MapType);
	FourDirection dir = FourDirection((FourDirectionName)csvparam);
	return std::make_shared<EnemyBullet01>(p_World, position, dir, p_GameManager);
}

void EnemyBullet01::SetUpCommand(){
	//生成
	p_CommandManager.reset(new EnemyCommandManagerNormal(shared_from_this()));
	//Command追加
	p_CommandManager->AddDic(EnemyCommandName::Straight, std::make_shared<EnemyCommandEnemyBullet01StraightTouchWall>(shared_from_this(),MapType::Double));
	//初期Command設定
	p_CommandManager->Change(EnemyCommandName::Straight);
}

void EnemyBullet01::SetUpState(){
	//生成
	p_StateManager.reset(new EnemyStateManager());
	//State追加
	p_StateManager->add(EnemyStateName::Idle, std::make_shared<EnemyStateIdleStandard>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Move, std::make_shared<EnemyStateMoveStandard>(shared_from_this(), 30.0f));
	p_StateManager->add(EnemyStateName::Caught, std::make_shared<EnemyStateCaughtReleaseDead>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Crush, std::make_shared<EnemyStateCrushStandard>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Dead, std::make_shared<EnemyStateDeadStandard>(shared_from_this()));
	//初期State設定
	p_StateManager->change(EnemyStateName::Idle);
}

void EnemyBullet01::onDraw() const{
	Texture2DParameter param;
	param.SetPosition(m_Transform.m_Position);
	param.SetCenter({ 16.0f, 16.0f });
	param.SetRect(*p_GameManager->GetRenderer2D()->GetTextureRect("Enemy01"));
	param.SetScale({ 1.0f , 1.0f });
	param.SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });
	p_GameManager->GetRenderer2D()->DrawTexture("Enemy01", param);
}
