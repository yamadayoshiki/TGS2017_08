#include "EnemyCommandRotation.h"
#include "../../../Enemys/Base/EnemyBase.h"

//コンストラクタ
EnemyCommandRotation::EnemyCommandRotation(const EnemyBasePtr& enemy, const float angle, const float endTimer)
	: EnemyCommandBase(enemy)
	, m_Angle(angle)
	, m_Angle_PerFrame(angle / endTimer)
	, m_EndTimer(endTimer)
	, m_Timer(0) {
}

//更新
void EnemyCommandRotation::Update(float deltaTime) {
	//回転
}

//終了
void EnemyCommandRotation::Finalize() {
}

//各種固有の初期化
void EnemyCommandRotation::OnInitialize() {
	m_Timer = 0;
}