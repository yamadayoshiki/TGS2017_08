#include"PlayerState_Close.h"

//コンストラクタ
PlayerState_Close::PlayerState_Close(GSvector2& position, GSmatrix4& matrix, const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState(position, matrix, player, gameManager)
{

}

//各状態独自の初期化
void PlayerState_Close::unique_init()
{

}

//更新処理
void PlayerState_Close::update(float deltaTaime)
{
	change(PlayerStateName::Idol);
}

//衝突判定
void PlayerState_Close::collide(const Actor& other)
{

}

//終了処理
void PlayerState_Close::end()
{

}