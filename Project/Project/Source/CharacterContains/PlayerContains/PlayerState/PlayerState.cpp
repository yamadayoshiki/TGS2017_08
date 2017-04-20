#include"PlayerState.h"

//コンストラクタ
PlayerState::PlayerState(GSvector2& position,GSmatrix4& matrix, GameManager* gameManager)
	:mPosition(position)
	,mMatrix(matrix)
	,mVelocity(GSvector2(0.0f,0.0f))
	,mAngle(0)
	,p_GameManager(gameManager)
	{
		p_Input = p_GameManager->GetInputState();
}

//パッド入力
void PlayerState::input() {}

////モーション変更
//void PlayerState::motion_change(Actor& actor, const PlayerStateID)
//{
//
//}
//移動処理
void PlayerState::move(Actor& actor, float deltaTime, float speed)
{
    mPosition += p_Input->PadVelocity() * speed;
}