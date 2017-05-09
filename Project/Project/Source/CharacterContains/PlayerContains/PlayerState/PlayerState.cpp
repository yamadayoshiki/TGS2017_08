#include"PlayerState.h"
#include <algorithm>
#include<GSmath.h>


//コンストラクタ
PlayerState::PlayerState(GSvector2& position, GSmatrix4& matrix, const PlayerPtr& player, const IGameManagerPtr& gameManager)
	:mPosition(position)
	, mMatrix(matrix)
	, mVelocity(GSvector2(0.0f, 0.0f))
	, p_Player(player)
	, p_GameManager(gameManager)
{
	p_Input = gameManager->GetInputState();
}

//パッド入力
void PlayerState::input() {}

////モーション変更
//void PlayerState::motion_change(Actor& other, const PlayerStateID)
//{
//
//}
//移動処理
void PlayerState::move(float deltaTime, float speed)
{
	GSvector2 v1;
	GSvector2 v2;
	GSvector2 v;
	if (p_Input->PadVelocity().length() > 0.0f)
	{
		//入力ベクトル
		v2 = p_Input->PadVelocity();
		//基準ベクトル
		v1 = GSvector2(0.0f, -1.0f);
		//外積を求める
		float cross = v1.CCW(v2);
		//結果
		float result = v1.normalize().dot(v2.normalize());
		//ベクトルを角度に置き換え
		mAngle = acosf(result);
		mAngle = mAngle * 180 / 3.14;

		//符号入れ替え
		if (cross < 0)
			mAngle = -mAngle;
		//角度設定
		mMatrix.setRotationZ(mAngle);
		//座標移動
		mPosition += p_Input->PadVelocity() * speed * deltaTime;
	}
	//m_Children[ActorName::Player_Arm]->setMatrix(mMatrix);
	m_Children[ActorName::Player_Arm]->setAngle(mAngle);
	m_Children[ActorName::Player_Arm]->setPosition(mPosition - GSvector2(mMatrix.getAxisY()) * 16);
}