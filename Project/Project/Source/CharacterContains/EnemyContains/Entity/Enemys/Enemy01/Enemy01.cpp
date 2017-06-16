#include "Enemy01.h"
#include "../../../../../ActorContains/ActorName.h"
#include "../../../../../ActorContains/Transform/Transform.h"
#include "../../../../../ActorContains/BodyContains/AARectangle/AARectangle.h"
#include "../../../../../Base/GameManagerContains/IGameManager.h"
#include "../../../../../Define/Def_Nakayama.h"
#include "../../../../../TextureContains/Texture/Texture.h"
#include "../../../../../TextureContains/AnimationTexture/AnimationTexture.h"
#include "../../../../../Utility/CsvConvertTwoDVector/CsvConvertTwoDVector.h"
#include "../../../../../Utility/Rederer2D/Renderer2D.h"
#include "../../../../../Utility/FourDirection/FourDirection.h"
#include "../../../../../Utility/Animation/Animation.h"
//CommandContains
#include "../../../CommandContains/CommandManagers/Nomal/EnemyCommandManagerNormal.h"
#include "../../../CommandContains/Commands/EnemyCommandName.h"
#include "../../../CommandContains/Commands/Enemy01Contains/Detour/EnemyCommandEnemy01Detour.h"
#include "../../../CommandContains/Commands/Enemy01Contains/Straight/EnemyCommandEnemy01Straight.h"
//State
#include "../../../StateContains/States/EnemyStateName.h"
#include "../../../StateContains/StateManager/EnemyStateManager.h"
#include "../../../StateContains/States/MoveContains/Repel/Idle/EnemyStateIdleRepel.h"
#include "../../../StateContains/States/MoveContains/Repel/Move/EnemyStateMoveRepel.h"
#include "../../../StateContains/States/StopContains/Standard/EnemyStateStopStandard.h"
#include "../../../StateContains/States/RepelContains/Repel/EnemyStateRepel.h"


//コンストラクタ
Enemy01::Enemy01(
	IWorld* world,
	const GSvector2& position,
	const FourDirection front,
	const IGameManagerPtr& gameManager)
	:EnemyBase(
		world,
		ActorName::Enemy_01,
		position,
		front,
		0,
		MapType::Double,
		gameManager,
		std::make_shared<Texture>("Enemy01", gameManager->GetRenderer2D()),
		std::make_shared<Body::AARectangle>(CHIP_SIZE, CHIP_SIZE)) {
}

//csvで生成(使用時継承先でoverride)
ActorPtr Enemy01::CsvGenerate(const int x, const int y, const int csvparam) {
	GSvector2 position = CsvConvertTwoDVector::CsvPosCnvVector2(x, y, m_MapType);
	FourDirection dir = FourDirection((FourDirectionName)csvparam);
	return std::make_shared<Enemy01>(p_World, position, dir, p_GameManager);
}

//各種固有のコマンドの設定
void Enemy01::SetUpCommand() {
	p_Texture = std::make_shared<AnimationTexture>("Enemy01", p_GameManager->GetRenderer2D(), new Animation(*p_GameManager->GetRenderer2D()->GetTextureRect("Enemy01"), 32, 8));

	//生成
	p_CommandManager.reset(new EnemyCommandManagerNormal(shared_from_this()));
	//Command追加
	p_CommandManager->AddDic(EnemyCommandName::Straight, std::make_shared<EnemyCommandEnemy01Straight>(shared_from_this()));
	p_CommandManager->AddDic(EnemyCommandName::AlongWallMoveShoest, std::make_shared<EnemyCommandEnemy01Detour>(shared_from_this()));
	//初期Command設定
	p_CommandManager->Change(EnemyCommandName::Straight);
}

//各種固有のStateの設定
void Enemy01::SetUpState() {
	//生成
	p_StateManager.reset(new EnemyStateManager());
	//State追加
	p_StateManager->add(EnemyStateName::Idle, std::make_shared<EnemyStateIdleRepel>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Move, std::make_shared<EnemyStateMoveRepel>(shared_from_this(), 4.0f));
	p_StateManager->add(EnemyStateName::Stop, std::make_shared<EnemyStateStopStandard>(shared_from_this(), 120));
	p_StateManager->add(EnemyStateName::Repel, std::make_shared<EnemyStateRepel>(shared_from_this()));
	//初期State設定
	p_StateManager->change(EnemyStateName::Idle);
}

//描画
void Enemy01::onDraw() const {
	//p_Body->transform(getTransform())->draw();

	p_Texture->GetParameter()->SetPosition(p_Transform->m_Position);
	p_Texture->GetParameter()->SetRotate(p_Transform->m_Angle);
	p_Texture->GetParameter()->SetCenter({ 16.0f, 16.0f });
	p_Texture->GetParameter()->SetScale({ 1.0f , 1.0f });
	p_Texture->GetParameter()->SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });
	//アニメーションの描画
	p_Texture->Draw();
}