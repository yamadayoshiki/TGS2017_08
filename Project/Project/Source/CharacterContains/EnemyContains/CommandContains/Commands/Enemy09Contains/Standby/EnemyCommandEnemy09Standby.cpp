#include "EnemyCommandEnemy09Standby.h"
#include "../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../PlayerWatch/PlayerWatch.h"
#include "../../../../../../Utility/MathSupport/MathSupport.h"
#include "../../../../../../FrontChipList/FrontChipList.h"
#include "../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../../WorldContains/IWorld.h"
#include "../../../../../../Utility/FourDirection/FourDirection.h"

EnemyCommandEnemy09Standby::EnemyCommandEnemy09Standby(
	const EnemyBasePtr & enemy)
	: EnemyCommandBase(enemy)
	, p_FrontChipList(new FrontChipList(enemy->getWorld()->GetMap(), enemy->getPosition(), enemy->GetDirection(), MapType::Double)) {
}

EnemyCommandEnemy09Standby::~EnemyCommandEnemy09Standby() {
	m_SpeaceNumMap.clear();
	delete p_FrontChipList;
}

void EnemyCommandEnemy09Standby::OnInitialize() {
	//各方向の壁マスまでの距離の設定
	SetSpeaceNum(FourDirectionName::Up);
	SetSpeaceNum(FourDirectionName::Left);
	SetSpeaceNum(FourDirectionName::Right);
	SetSpeaceNum(FourDirectionName::Down);
}

void EnemyCommandEnemy09Standby::OnUpdate(float deltaTime) {
	//プレイヤーがいる方向
	GSvector2 v = p_Enemy.lock()->GetPlayerWatch()->GetToPlayerDis();
	//角度算出
	float angle = MathSupport::GetVec2ToVec2Angle(v, GSvector2(0.0f, -1.0f));
	//角度設定
	p_Enemy.lock()->setAngle(angle);

	//軸がどちらか重なっていたら突進
	if (IsAxisOverlap() == true)
		Change(EnemyCommandName::Rush);
}

bool EnemyCommandEnemy09Standby::IsAxisOverlap() {
	//プレイヤーまでのマス準拠距離
	GSvector2 toPlayer = p_Enemy.lock()->GetPlayerWatch()->GetToPlayerChipDis();

	if (toPlayer.x == 0 || toPlayer.y == 0)
	{
		float speaceNum = m_SpeaceNumMap[FourDirection(toPlayer)];
		if (speaceNum >= toPlayer.length())
		{
			p_Enemy.lock()->SetDirection(FourDirection(toPlayer));
			return true;
		}
	}

	return false;
}

//指定方向の壁マスまでの距離の設定
void EnemyCommandEnemy09Standby::SetSpeaceNum(const FourDirectionName name) {
	FourDirection dir = FourDirection(name);
	//前方マスの設定
	p_FrontChipList->SetFrontChipList(p_Enemy.lock()->getPosition(), dir);
	//壁マスまでの距離
	m_SpeaceNumMap[dir] = p_FrontChipList->GetSpeaceNum();
}
