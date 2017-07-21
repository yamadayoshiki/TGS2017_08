#include "CharacterFactory.h"
#include "../../ActorContains/ActorName.h"
#include "../../WorldContains/IWorld.h"
#include "../../Utility/TurnDirection/TurnDirection.h"
#include "../../Define/Def_GSvector2.h"
#include "../../Utility/MathSupport/MathSupport.h"
#include "../../Utility/CsvConvertTwoDVector/CsvCellData.h"
#include "../../Utility/CsvConvertTwoDVector/CsvConvertTwoDVector.h"

//生成キャラ
#include "../EnemyContains/Entity/Enemys/Enemy01/Enemy01.h"
#include "../EnemyContains/Entity/Enemys/Enemy02/Enemy02.h"
#include "../EnemyContains/Entity/Enemys/Enemy03/Enemy03.h"
#include "../EnemyContains/Entity/Enemys/Enemy04/Enemy04.h"
#include "../EnemyContains/Entity/Enemys/Enemy05/Enemy05.h"
#include "../EnemyContains/Entity/Enemys/Enemy06/Enemy06.h"
#include "../EnemyContains/Entity/Enemys/Enemy07/Enemy07.h"
#include "../EnemyContains/Entity/Enemys/Enemy08/Enemy08.h"
#include "../EnemyContains/Entity/Enemys/Enemy09/Enemy09.h"
#include "../EnemyContains/Entity/Enemys/Enemy10/Enemy10.h"
#include "../EnemyContains/Entity/Enemys/Enemy11/Enemy11.h"
#include "../EnemyContains/Entity/EnemyBullets/Bullet01/EnemyBullet01.h"
#include "../../Wall/BreakWall.h"
#include "../PlayerContains/Player/Player.h"

//コンストラクタ
CharacterFactory::CharacterFactory(
	const IWorldPtr& world,
	const IGameManagerPtr& gameManager)
	: p_IWorld(world)
	, p_IGameManager(gameManager) {
	//生成先登録
	m_ParentMap[ActorName::EnemyManager] = p_IWorld.lock()->findActor(ActorName::EnemyManager);
	m_ParentMap[ActorName::PlayerManager] = p_IWorld.lock()->findActor(ActorName::PlayerManager);

	//生成キャラ登録
	m_GenerateMap[11] = ActorData{ m_ParentMap[ActorName::EnemyManager],std::make_unique<Enemy01>(p_IWorld.lock().get(), GSVECTOR2_ZERO, FourDirection(FourDirectionName::None), p_IGameManager.lock()) };
	m_GenerateMap[12] = ActorData{ m_ParentMap[ActorName::EnemyManager],std::make_unique<Enemy02>(p_IWorld.lock().get(), GSVECTOR2_ZERO, FourDirection(FourDirectionName::None), FourDirection(FourDirectionName::Right), p_IGameManager.lock()) };
	m_GenerateMap[13] = ActorData{ m_ParentMap[ActorName::EnemyManager],std::make_unique<Enemy02>(p_IWorld.lock().get(), GSVECTOR2_ZERO, FourDirection(FourDirectionName::None), FourDirection(FourDirectionName::Left), p_IGameManager.lock()) };
	m_GenerateMap[14] = ActorData{ m_ParentMap[ActorName::EnemyManager],std::make_unique<Enemy02>(p_IWorld.lock().get(), GSVECTOR2_ZERO, FourDirection(FourDirectionName::None), FourDirection(FourDirectionName::Down), p_IGameManager.lock()) };
	m_GenerateMap[15] = ActorData{ m_ParentMap[ActorName::EnemyManager],std::make_unique<Enemy03>(p_IWorld.lock().get(), GSVECTOR2_ZERO, FourDirection(FourDirectionName::None), TurnDirection(TurnDirectionName::Clockwise), p_IGameManager.lock()) };
	m_GenerateMap[16] = ActorData{ m_ParentMap[ActorName::EnemyManager],std::make_unique<Enemy03>(p_IWorld.lock().get(), GSVECTOR2_ZERO, FourDirection(FourDirectionName::None), TurnDirection(TurnDirectionName::AntiClockwise), p_IGameManager.lock()) };
	m_GenerateMap[17] = ActorData{ m_ParentMap[ActorName::EnemyManager],std::make_unique<Enemy04>(p_IWorld.lock().get(), GSVECTOR2_ZERO, FourDirection(FourDirectionName::None), p_IGameManager.lock()) };
	m_GenerateMap[18] = ActorData{ m_ParentMap[ActorName::EnemyManager],std::make_unique<Enemy05>(p_IWorld.lock().get(), GSVECTOR2_ZERO, FourDirection(FourDirectionName::None), p_IGameManager.lock()) };
	m_GenerateMap[19] = ActorData{ m_ParentMap[ActorName::EnemyManager],std::make_unique<Enemy06>(p_IWorld.lock().get(), GSVECTOR2_ZERO, FourDirection(FourDirectionName::None), p_IGameManager.lock()) };
	m_GenerateMap[20] = ActorData{ m_ParentMap[ActorName::EnemyManager],std::make_unique<Enemy07>(p_IWorld.lock().get(), GSVECTOR2_ZERO, FourDirection(FourDirectionName::None), p_IGameManager.lock()) };
	m_GenerateMap[21] = ActorData{ m_ParentMap[ActorName::EnemyManager],std::make_unique<Enemy08>(p_IWorld.lock().get(), GSVECTOR2_ZERO, FourDirection(FourDirectionName::None), p_IGameManager.lock()) };
	m_GenerateMap[22] = ActorData{ m_ParentMap[ActorName::EnemyManager],std::make_unique<Enemy09>(p_IWorld.lock().get(), GSVECTOR2_ZERO, FourDirection(FourDirectionName::None), p_IGameManager.lock()) };
	m_GenerateMap[23] = ActorData{ m_ParentMap[ActorName::EnemyManager],std::make_unique<Enemy10>(p_IWorld.lock().get(), GSVECTOR2_ZERO, FourDirection(FourDirectionName::None), p_IGameManager.lock()) };
	m_GenerateMap[24] = ActorData{ m_ParentMap[ActorName::EnemyManager],std::make_unique<EnemyBullet01>(p_IWorld.lock().get(), GSVECTOR2_ZERO, FourDirection(FourDirectionName::None), p_IGameManager.lock()) };
	m_GenerateMap[25] = ActorData{ m_ParentMap[ActorName::EnemyManager],std::make_unique<Enemy11>(p_IWorld.lock().get(), GSVECTOR2_ZERO, FourDirection(FourDirectionName::None), p_IGameManager.lock()) };

	//ブロック
	m_GenerateMap[81] = ActorData{ m_ParentMap[ActorName::EnemyManager],std::make_unique<BreakWall>(p_IWorld.lock().get(),GSVECTOR2_ZERO,p_IGameManager.lock()) };

	//プレイヤー
	m_GenerateMap[91] = ActorData{ m_ParentMap[ActorName::PlayerManager],std::make_unique<Player>(p_IWorld.lock().get(),GSVECTOR2_ZERO,p_IGameManager.lock()) };
}

//デストラクタ
CharacterFactory::~CharacterFactory() {
	m_ParentMap.clear();
	m_GenerateMap.clear();
}

//生成
void CharacterFactory::Generate(const int x, const int y, const int csvData) {
	//最上位２桁をキャラキーに変換
	int key = MathSupport::GetCutNum(csvData, 1, 2);
	if (key == 0) return;
	//最上位２桁の排除
	int csvParam = csvData % (int)std::pow(10, MathSupport::GetDigit(csvData) - 2);

	ActorData& data = m_GenerateMap[key];
	data.parent.lock()->addChild(data.child->CsvGenerate(x, y, csvParam));
}

//生成
void CharacterFactory::Generate(const GSvector2 position, const int csvData) {
	//最上位２桁をキャラキーに変換
	int key = MathSupport::GetCutNum(csvData, 1, 2);
	if (key == 0) return;
	//最上位２桁の排除
	int csvParam = csvData % (int)std::pow(10, MathSupport::GetDigit(csvData) - 2);

	ActorData& data = m_GenerateMap[key];
	//キャラのマップタイプ
	MapType type = data.child->GetMapType();
	GSvector2 cellData = CsvConvertTwoDVector::Vector2CnvCsvPos(position, type);

	data.parent.lock()->addChild(data.child->CsvGenerate(cellData.x, cellData.y, csvParam));
}

//生成するCharacterを取得
ActorPtr CharacterFactory::GetGenerateCharacter(const GSvector2 position, const int csvData) {
	//最上位２桁をキャラキーに変換
	int key = MathSupport::GetCutNum(csvData, 1, 2);
	if (key == 0) return nullptr;
	//最上位２桁の排除
	int csvParam = csvData % (int)std::pow(10, MathSupport::GetDigit(csvData) - 2);

	ActorData& data = m_GenerateMap[key];
	//キャラのマップタイプ
	GSvector2 cellData = CsvConvertTwoDVector::Vector2CnvCsvPos(position, MapType::Default);

	return data.child->CsvGenerate(cellData.x, cellData.y, csvParam);
}
