#include "EnemyCommandBase.h"

//コンストラクタ
EnemyCommandBase::EnemyCommandBase(const EnemyBasePtr& enemy)
	:p_Enemy(enemy)
	, m_Velocity(GSvector2(0.0f, 0.0f))
	, m_RotateAngle(0.0f) {
}

//初期化
void EnemyCommandBase::Initialize() {
	OnInitialize();
}

//目標地点までの移動ベクトルの取得
GSvector2 EnemyCommandBase::GetVelocity() const {
	return m_Velocity;
}

//回転角度の取得
float EnemyCommandBase::GetRotateAngle() const {
	return m_RotateAngle;
}