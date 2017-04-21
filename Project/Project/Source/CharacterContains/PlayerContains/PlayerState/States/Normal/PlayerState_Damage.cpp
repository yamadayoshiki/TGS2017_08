#include"PlayerState_Damage.h"

//コンストラクタ
PlayerState_Damage::PlayerState_Damage(GSvector2& position,GSmatrix4& matrix, IGameManager* gameManager)
	:PlayerState(position,matrix,gameManager)
{

}
//各状態独自の初期化
void PlayerState_Damage::unique_init(Actor& actor)
{

}
//更新処理
void PlayerState_Damage::update(Actor& actor, float deltaTaime)
{

}
//衝突判定
void PlayerState_Damage::collide(const Actor& other){}
//終了処理
void PlayerState_Damage::end(){}
//入力処理
void PlayerState_Damage::input(){}