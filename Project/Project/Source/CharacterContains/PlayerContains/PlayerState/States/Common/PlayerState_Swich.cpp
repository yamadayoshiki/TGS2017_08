#include"PlayerState_Swich.h"

//コンストラクタ
PlayerState_Swich::PlayerState_Swich(GSvector2& position, GSmatrix4& matrix, const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState(position, matrix, player, gameManager) {
}

//各状態独自の初期化
void PlayerState_Swich::unique_init()
{

}

//更新処理
void PlayerState_Swich::update(float deltaTaime)
{
	if (m_Flag == true) {
		change(PlayerStateName::Rounds);
	}
	else {
		change(PlayerStateName::Close);
	}
}

//衝突判定
void PlayerState_Swich::collide(const Actor& other)
{

	//bool flag = false;

	//GSvector3 l = mMatrix.getAxisY();
	//GSvector2 tmp = GSvector2(l.x, l.y);
	//tmp.normalize();

	//GSvector2	V = GSvector2(1.0f,0.0f);
	//float angle1 = (tmp + m_Angle) * 3.14 / 180;
	//float angle2 = (tmp - m_Angle) * 3.14 / 180;
	////視野ベクトル
	//GSvector2 v1 = GSvector2(V.x * cosf(angle1) - V.y * sinf(angle1),
	//	V.x  * sinf(angle1) + V.y * cosf(angle1)).normalize();
	//GSvector2 v2 = GSvector2(V.x * cosf(angle2) - V.y * sinf(angle2),
	//	V.x  * sinf(angle2) + V.y * cosf(angle2)).normalize();

	//相手のベクトル
	//GSvector2 v = other.getPosition() - mPosition;
	//v.normalize();
	//float l_result = tmp.innerDegree(v);
	//if (l_result <= 45.0f) {
	//	flag = true;
	//}

	//////外積
	//float cross1 = v.normalize().CCW(v1.normalize());
	//float cross2 = v.normalize().CCW(v2.normalize());
	////結果
	//float result = cross1 * cross2;
	//if (result < 0) {
	//	flag = true;
	//}

	if (m_Children[ActorName::Player_Arm]->isCollide(other)) {
		m_Flag = true;
		//相手に挟んだ情報を送る
	}
}