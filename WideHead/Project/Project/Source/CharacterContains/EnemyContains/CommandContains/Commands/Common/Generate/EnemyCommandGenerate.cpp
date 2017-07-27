#include "EnemyCommandGenerate.h"
#include "../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../../WorldContains/IWorld.h"
#include "../../../../../../Map/Map.h"
#include "../../../../../Factory/CharacterFactory.h"
#include "../../../../StateContains/StateManager/EnemyStateManager.h"
#include "../../../../StateContains/States/EnemyStateName.h"
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
	EnemyStateName name = p_Enemy.lock()->GetStateManager()->GetCurStateName();
	if (name != EnemyStateName::Idle&&name != EnemyStateName::Move)	return;

	m_Timer += deltaTime;
	if (m_Timer >= m_IntervalTime)
	{
		m_CurStateName = EnemyStateName::Generate;

		m_Timer = 0;
	}
}

