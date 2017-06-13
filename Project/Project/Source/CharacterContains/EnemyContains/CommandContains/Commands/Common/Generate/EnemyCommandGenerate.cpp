#include "EnemyCommandGenerate.h"
#include "../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../../WorldContains/IWorld.h"
#include "../../../../../../Map/Map.h"
#include "../../../../../Factory/CharacterFactory.h"

//コンストラクタ
EnemyCommandGenerate::EnemyCommandGenerate(
	const EnemyBasePtr & enemy,
	const float charaNumber,
	const float intervalTime)
	: EnemyCommandBase(enemy)
	, m_CharaNumber(charaNumber)
	, m_IntervalTime(intervalTime)
	, m_Timer(0) {
}

//デストラクタ
EnemyCommandGenerate::~EnemyCommandGenerate() {
}

//各種固有の初期化
void EnemyCommandGenerate::OnInitialize() {
	m_Timer = 0;
}

//各種固有の更新
void EnemyCommandGenerate::OnUpdate(float deltaTime) {
	m_Timer += deltaTime;
	if (m_Timer >= m_IntervalTime)
	{
		//周辺タイルの取得
		std::unordered_map<FourDirection, TileData> aroundTile = p_Enemy.lock()->getWorld()->GetMap()->GetAroundTile(p_Enemy.lock()->getPosition(), p_Enemy.lock()->GetMapType());
		//正面タイルのデータの取得
		TileData frontTile = aroundTile[p_Enemy.lock()->GetDirection()];
		//正面に生成
		p_Enemy.lock()->addChild(p_Enemy.lock()->getWorld()->GetCharacterFactory()->GetGenerateCharacter(frontTile.Position(), m_CharaNumber * 10 + (int)p_Enemy.lock()->GetDirection().name));
	
		m_Timer = 0;
	}
}

