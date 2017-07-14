#include "Enemy07.h"
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
#include "../../../CommandContains/Commands/EnemyCommandName.h"
#include "../../../CommandContains/CommandManagers/Nomal/EnemyCommandManagerNormal.h"
#include "../../../CommandContains/Commands/Enemy07Contains/Patrol/EnemyCommandEnemy07Patrol.h"
#include "../../../CommandContains/Commands/Enemy07Contains/Spin/EnemyCommandEnemy07Spin.h"
//State
#include "../../../StateContains/StateManager/EnemyStateManager.h"
#include "../../../StateContains/States/CaughtContains/Standard/EnemyStateCaughtStandard.h"
#include "../../../StateContains/States/CrushContains/Spin/EnemyStateCrushSpin.h"
#include "../../../StateContains/States/DeadContaint/Standard/EnemyStateDeadStandard.h"
#include "../../../StateContains/States/MoveContains/Standard/Move/EnemyStateMoveStandard.h"
#include "../../../StateContains/States/MoveContains/Standard/Idle/EnemyStateIdleStandard.h"
#include "../../../StateContains/States/StopContains/Standard/EnemyStateStopStandard.h"
#include "../../../StateContains/States/SpinContains/Standard/EnemyStateSpinStandard.h"

#include <string>

//コンストラクタ
Enemy07::Enemy07(
	IWorld * world,
	const GSvector2 & position,
	const FourDirection front,
	const IGameManagerPtr & gameManager,
	const std::string fileName)
	: EnemyBase(
		world,
		ActorName::Enemy_07,
		position,
		front,
		10,
		MapType::Double,
		gameManager,
		std::make_shared<NullTexture>(),
		Body::MotionType::Enemy, Body::BodyDataName::AABB_32)
	, m_FileName(fileName) {
}

//デストラクタ
Enemy07::~Enemy07() {
}

ActorPtr Enemy07::CsvGenerate(const int x, const int y, const int csvparam)
{
	//座標設定
	GSvector2 position = CsvConvertTwoDVector::CsvPosCnvVector2(x, y, m_MapType);
	//方向の設定
	FourDirection dir = FourDirection((FourDirectionName)MathSupport::GetCutNum(csvparam, 1, 1));
	//巡回ファイルの設定
	int num = MathSupport::GetCutNum(csvparam, 2, 2);
	std::string name = "Resource/StreamingAssets/nokonoko/" + std::to_string(num) + ".csv";

	return std::make_shared<Enemy07>(p_World, position, dir, p_GameManager, name);
}

//各種固有のコマンドの設定
void Enemy07::SetUpCommand() {
	m_TextureMap["Normal"] = std::make_shared<AnimationTexture>("Enemy07Normal", p_GameManager->GetDrawManager(), DrawOrder::Enemy, 32, 8);
	m_TextureMap["Attack"] = std::make_shared<AnimationTexture>("Enemy07Attack", p_GameManager->GetDrawManager(), DrawOrder::Enemy, 32, 8);
	m_TextureMap["Normal"]->GetParameter()->m_Center = { 16.0f,16.0f };
	m_TextureMap["Attack"]->GetParameter()->m_Center = { 16.0f,16.0f };
	p_Texture = m_TextureMap["Normal"];

	//生成
	p_CommandManager.reset(new EnemyCommandManagerNormal(shared_from_this()));
	//Command追加
	p_CommandManager->AddDic(EnemyCommandName::Patrol, std::make_shared<EnemyCommandEnemy07Patrol>(shared_from_this(), m_FileName));
	p_CommandManager->AddDic(EnemyCommandName::SpinMove, std::make_shared<EnemyCommandEnemy07Spin>(shared_from_this(), 3));
	//初期Command設定
	p_CommandManager->Change(EnemyCommandName::Patrol);
}

//各種固有のStateの設定
void Enemy07::SetUpState() {
	//生成
	p_StateManager.reset(new EnemyStateManager());
	//State追加
	p_StateManager->add(EnemyStateName::Caught, std::make_shared<EnemyStateCaughtStandard>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Crush, std::make_shared<EnemyStateCrushSpin>(shared_from_this(), 3));
	p_StateManager->add(EnemyStateName::Dead, std::make_shared<EnemyStateDeadStandard>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Idle, std::make_shared<EnemyStateIdleStandard>(shared_from_this()));
	p_StateManager->add(EnemyStateName::Move, std::make_shared<EnemyStateMoveStandard>(shared_from_this(), 3.0f));
	p_StateManager->add(EnemyStateName::Stop, std::make_shared<EnemyStateStopStandard>(shared_from_this(), 120));
	p_StateManager->add(EnemyStateName::Spin, std::make_shared<EnemyStateSpinStandard>(shared_from_this(), 20.0f));
	//初期State設定
	p_StateManager->change(EnemyStateName::Idle);
}

//描画
void Enemy07::onDraw() const {
}