#include"PlayerState_Awake.h"

//コンストラクタ
PlayerState_Awake::PlayerState_Awake(GSvector2& position,GSmatrix4& matrix,IGameManagerPtr gameManager)
	:PlayerState(position,matrix,gameManager)
{

}

//各状態独自の初期化
void PlayerState_Awake::unique_init(Actor& actor)
{

}

//更新処理
void PlayerState_Awake::update(Actor& actor, float deltaTaime)
{

}

//衝突判定
void PlayerState_Awake::collide(const Actor& other)
{

}

//終了処理
void PlayerState_Awake::end()
{

}