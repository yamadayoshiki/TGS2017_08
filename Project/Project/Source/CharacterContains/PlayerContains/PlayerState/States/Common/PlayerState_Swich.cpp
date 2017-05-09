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
		change(PlayerStateName::R_Idle);
	}
	else {
		change(PlayerStateName::Close);
	}
}

//衝突判定
void PlayerState_Swich::collide(const Actor& other)
{
	if (m_Children[ActorName::Player_Arm]->isCollide(other)) {
		m_Flag = true;
		//相手に挟んだ情報を送る
	}
}