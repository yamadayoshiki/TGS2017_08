#include "Enemy01.h"
#include "../../../../ActorContains/ActorName.h"
#include "../../../../TextureContains/Texture/Texture.h"
#include "../../../../Base/GameManagerContains/IGameManager.h"
#include "../../../../Utility/Rederer2D/Renderer2D.h"
#include "../../../../Utility/FourDirection/FourDirection.h"
#include "../../../../Utility/MathSupport/MathSupport.h"

//CommandContains
#include "../../CommandContains/CommandManagers/Nomal/EnemyCommandManagerNormal.h"
#include "../../CommandContains/Commands/EnemyCommandName.h"
#include "../../CommandContains/Commands/Straight/EnemyCommandStraight.h"
#include "../../CommandContains/Commands/AlongWallMove/EnemyCommandAlongWallMove.h"

//State
#include "../../StateContains/States/Caught/EnemyStateCaught.h"
#include "../../StateContains/States/Crush/EnemyStateCrush.h"
#include "../../StateContains/States/Dead/EnemyStateDead.h"
#include "../../StateContains/States/MoveContains/Idle/EnemyStateIdle.h"
#include "../../StateContains/States/MoveContains/Move/EnemyStateMove.h"
#include "../../../../Utility/TurnDirection/TurnDirection.h"
#include "../../../../ActorContains/Body/OrientedBoundingBox.h"

//コンストラクタ
Enemy01::Enemy01(
	IWorld* world,
	const GSvector2& position,
	FourDirection& front,
	const IGameManagerPtr& gameManager)
	:EnemyBase(
		world,
		ActorName::Enemy_01,
		position,
		1.0f,
		gameManager,
		std::make_shared<Texture>("Enemy01", gameManager->GetRenderer2D()),
		std::make_shared<OrientedBoundingBox>(GSvector2(0.0f, 0.0f), -90.0f, GSvector2(1.0f, 1.0f))) {
	m_Transform.m_Angle = MathSupport::GetVec2ToVec2Angle(front.GetVector2());
}

//各種固有のコマンドの設定
void Enemy01::SetUpCommand() {
	//生成
	p_CommandManager = std::make_shared<EnemyCommandManagerNormal>(shared_from_this());
	//Command追加
	p_CommandManager->AddDic(EnemyCommandName::Straight, std::make_shared<EnemyCommandStraight>(shared_from_this(), FourDirection(p_Body->forward())));
	p_CommandManager->AddDic(EnemyCommandName::AlongWallMoveAntiClockwise, std::make_shared<EnemyCommandAlongWallMove>(shared_from_this(), TurnDirection(TurnDirectionName::AntiClockwise)));
	p_CommandManager->AddDic(EnemyCommandName::AlongWallMoveClockwise, std::make_shared<EnemyCommandAlongWallMove>(shared_from_this(), TurnDirection(TurnDirectionName::Clockwise)));
	//初期Command設定
	p_CommandManager->Change(EnemyCommandName::AlongWallMoveAntiClockwise);
}

//各種固有のStateの設定
void Enemy01::SetUpState() {
	//生成
	p_StateManager = new EnemyStateManager();
	//State追加
	p_StateManager->add(EnemyStateName::Caught, std::make_shared<EnemyStateCaught>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Crush, std::make_shared<EnemyStateCrush>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Dead, std::make_shared<EnemyStateDead>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Idle, std::make_shared<EnemyStateIdle>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Move, std::make_shared<EnemyStateMove>(shared_from_this()));
	//初期State設定
	p_StateManager->change(EnemyStateName::Idle);
}

//描画
void Enemy01::onDraw() const {
	p_Body->transform(getTransform())->draw();

	Texture2DParameter param;
	param.SetPosition(m_Transform.m_Position);
	param.SetCenter({ 16.0f, 16.0f });
	param.SetRect(*p_GameManager->GetRenderer2D()->GetTextureRect("Enemy01"));
	param.SetScale({ 1.0f , 1.0f });
	param.SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });
	p_GameManager->GetRenderer2D()->DrawTexture("Enemy01", param);
}

//衝突した
void Enemy01::onCollide(Actor& other) {

}