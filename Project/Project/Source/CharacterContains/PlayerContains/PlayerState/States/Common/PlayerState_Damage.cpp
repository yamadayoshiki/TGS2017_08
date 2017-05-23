#include"PlayerState_Damage.h"

//コンストラクタ
PlayerState_Damage::PlayerState_Damage(const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player, gameManager)
{

}
//各状態独自の初期化
void PlayerState_Damage::unique_init()
{
	m_FramConter = 0;
	m_Parameter.m_Remaining -= 1;
	//p_GameManager->SetPlayerParameter(m_Parameter);
}
//更新処理
void PlayerState_Damage::update(float deltaTaime)
{
	if (m_Parameter.m_Remaining < 0) {
		change(PlayerStateName::Dead);
		return;
	}
		change(PlayerStateName::Idle);
}
//衝突判定
void PlayerState_Damage::collide(const Actor& other) {}
//終了処理
void PlayerState_Damage::end() {}
//入力処理
void PlayerState_Damage::input() {}