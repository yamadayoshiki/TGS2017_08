#include"PlayerState_Damage.h"

//コンストラクタ
PlayerState_Damage::PlayerState_Damage(GSvector2& position, GSmatrix4& matrix, const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState(position, matrix, player, gameManager)
{

}
//各状態独自の初期化
void PlayerState_Damage::unique_init()
{

}
//更新処理
void PlayerState_Damage::update(float deltaTaime)
{

}
//衝突判定
void PlayerState_Damage::collide(const Actor& other) {}
//終了処理
void PlayerState_Damage::end() {}
//入力処理
void PlayerState_Damage::input() {}