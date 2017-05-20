#include"PlayerState_Release.h"

//コンストラクタ
PlayerState_Release::PlayerState_Release(const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player,gameManager)
{

}
//各状態独自の初期化
void PlayerState_Release::unique_init()
{
	m_FramConter = 0.0f;
}
//更新処理
void PlayerState_Release::update(float deltaTaime)
{
	/*if (m_FramConter > 10)
	{*/
		change(PlayerStateName::Open);
	//}
	m_FramConter += deltaTaime;
}
//衝突判定
void PlayerState_Release::collide(const Actor& other)
{

}