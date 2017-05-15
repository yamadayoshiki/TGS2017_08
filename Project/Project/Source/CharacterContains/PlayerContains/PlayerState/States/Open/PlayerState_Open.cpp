#include"PlayerState_Open.h"
#include"../../PlayerStateName.h"

//コンストラクタ
PlayerState_Open::PlayerState_Open(const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player, gameManager)
{

}

//各状態独自の初期化
void PlayerState_Open::unique_init()
{

}

//更新処理
void PlayerState_Open::update(float deltaTaime)
{
	change(PlayerStateName::O_Idle);
}

//衝突判定
void PlayerState_Open::collide(const Actor& other)
{

}

//終了処理
void PlayerState_Open::end()
{

}