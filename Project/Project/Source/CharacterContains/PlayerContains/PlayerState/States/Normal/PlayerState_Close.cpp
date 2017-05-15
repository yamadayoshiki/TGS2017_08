#include"PlayerState_Close.h"

//コンストラクタ
PlayerState_Close::PlayerState_Close(const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player, gameManager)
{

}

//各状態独自の初期化
void PlayerState_Close::unique_init()
{

}

//更新処理
void PlayerState_Close::update(float deltaTaime)
{
	change(PlayerStateName::Idle);
}

//衝突判定
void PlayerState_Close::collide(const Actor& other)
{

}

//終了処理
void PlayerState_Close::end()
{

}