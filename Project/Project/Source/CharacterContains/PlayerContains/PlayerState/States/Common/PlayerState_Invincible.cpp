#include"PlayerState_Invincible.h"

//コンストラクタ
PlayerState_Invincible::PlayerState_Invincible(const Player_WPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player,gameManager)
{

}
//各状態独自の初期化
void PlayerState_Invincible::unique_init()
{
	TextureName_Change("Player_Invincble");
	gsPlaySE(SE_PLAYER_RESPAWN);
	m_FramConter = 0.0f;
}
//更新処理
void PlayerState_Invincible::update(float deltaTaime)
{
	if (m_FramConter >= 30) {
		change(PlayerStateName::Walk);
	}
	move(deltaTaime, 8.0f);
	m_FramConter += deltaTaime;
}
//衝突判定
void PlayerState_Invincible::collide(const Actor& other)
{

}

//入力処理
void PlayerState_Invincible::input()
{
	//アームを開く
	if (p_Input->IsPadStateTrigger(GS_XBOX_PAD_B))
		change(PlayerStateName::Open);
	//ダッシュ
	if (p_Input->IsPadStateTrigger(GS_XBOX_PAD_A) ||
		gsGetKeyState(GKEY_Z)) {
		change(PlayerStateName::Dash);
	}
}