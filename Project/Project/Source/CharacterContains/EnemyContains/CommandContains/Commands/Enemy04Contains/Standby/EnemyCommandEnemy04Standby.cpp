#include "EnemyCommandEnemy04Standby.h"
#include "../../../../../../WorldContains/EventMessage/EventMessage.h"
#include "../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../../Define/Def_Float.h"	//for FLOAT_EPSILON
#include "../../../../../../WorldContains/IWorld.h"
#include "../../../../../../Map/Map.h"
#include "../../../../../../Define/Def_Nakayama.h"

//コンストラクタ
EnemyCommandEnemy04Standby::EnemyCommandEnemy04Standby(
	const EnemyBasePtr & enemy,
	const FourDirection front)
	:EnemyCommandMoveBase(enemy,MapType::Double)
	, m_Front(front)
	, m_Counter(0)
	, m_Flag(false) {
}

//メッセージ処理
void EnemyCommandEnemy04Standby::handleMessage(EventMessage message, void * param) {
	switch (message)
	{
	case EventMessage::PLAYER_RELEASE:
		m_Counter++;
		if (m_Counter >= 3)
			SetNextTargetPos();

		break;
	}
}

//各種固有の初期化
void EnemyCommandEnemy04Standby::OnInitialize() {
	//変数初期化
	m_Counter = 0;
}

//各種固有の更新
void EnemyCommandEnemy04Standby::OnUpdate(float deltaTime) {
	//挟まれた回数が指定回数未満の場合return
	if (m_Counter < 3)
		return;

	//挟まれた回数が指定回数以上の場合行動
	else if (m_Counter >= 3)
		EnemyCommandMoveBase::OnUpdate(deltaTime);
}

//目標地点に到達したときのリアクション
void EnemyCommandEnemy04Standby::ArriveReaction() {
	//挟まれた回数を減らす
	m_Counter = m_Counter - 3;
}

//次の目標地点を設定する
void EnemyCommandEnemy04Standby::SetNextTargetPos() {
	//正面が壁ならreturn
	if (m_Flag == true) return;

	//進行方向にあるマスが壁か
	if (p_Enemy.lock()->getWorld()->GetMap()->IsInFrontOfTheWall(p_Enemy.lock()->getPosition(), m_Front, MapType::Double) == true)
		m_Flag = true;

	//正面にあるタイルの座標を設定
	else
	{
		//移動量
		GSvector2 velocity = p_Enemy.lock()->GetDirection().GetVector2() * CHIP_SIZE * 2;
		//座標設定
		m_NextTargetPos = p_Enemy.lock()->getPosition() + velocity;
	}
}
