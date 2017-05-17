#include "EnemyCommandAlongWallMove.h"
#include "../../../../../Define/Def_GSvector2.h"
#include "../../../Enemys/Base/EnemyBase.h"
#include "../../../../../WorldContains/IWorld.h"
#include "../../../../../Map/Map.h"
#include "../../../../../Define/Def_Float.h"
#include "../../../../../ActorContains/Transform/Transform.h"
#include "../../../../../Utility/MathSupport/MathSupport.h"

//コンストラクタ
EnemyCommandAlongWallMove::EnemyCommandAlongWallMove(const EnemyBasePtr& enemy, const TurnDirection turnDirection)
	:EnemyCommandBase(enemy)
	, m_TurnDirection(turnDirection)
	, m_CurDirection(enemy->getTransform().m_Angle)
	, m_NextTargetPos(GSVECTOR2_ZERO) {
	// 壁に背を向けている前提で目標地点を設定
	SetTargetPos();
}

//更新
void EnemyCommandAlongWallMove::Update(float deltaTime) {
	//目標地点までの距離
	m_Velocity = m_NextTargetPos - p_Enemy->getPosition();
	//目標地点にたどり着いているか
	if (m_Velocity.length() <= FLOAT_EPSILON)
		SetTargetPos();
}

//終了
void EnemyCommandAlongWallMove::Finalize() {

}

//回転方向の設定
void EnemyCommandAlongWallMove::SetTurnDirection(TurnDirection turnDirection) {
	m_TurnDirection = turnDirection;
}

//各種固有の初期化
void EnemyCommandAlongWallMove::OnInitialize() {

}

//目標地点の設定
void EnemyCommandAlongWallMove::SetTargetPos() {
	//自分の周辺のタイルデータ配列
	std::unordered_map<FourDirection, TileData> mapDate
		= p_Enemy->getWorld()->GetMap().GetAroundTile(p_Enemy->getPosition());

	//進行方向の逆方向に変更
	m_CurDirection.TurnOver();

	//結果変数
	TileData result;

	//進行方向が決定するまで
	while (true)
	{
		//90度回転
		m_CurDirection.Turn(m_TurnDirection.GetReversal());
		//方向に応じたタイルデータの取り出し
		result = mapDate[m_CurDirection];
		//タイルが壁ではないか
		if (result.Flag() == 0)
			break;
	}

	//進行方向タイルの座標を設定
	m_NextTargetPos = result.Position();

	//目標地点までの距離
	m_Velocity = m_NextTargetPos - p_Enemy->getPosition();
}