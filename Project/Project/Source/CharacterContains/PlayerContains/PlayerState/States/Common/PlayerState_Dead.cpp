#include"PlayerState_Dead.h"

//コンストラクタ
PlayerState_Dead::PlayerState_Dead(const Player_WPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player,gameManager)
{

}
//各状態独自の初期化
void PlayerState_Dead::unique_init()
{
	p_Player.lock()->getWorld()->EndRequest(SceneName::GameOver);
}
//更新処理
void PlayerState_Dead::update(float deltaTaime)
{
	//p_Player.lock()->dead();
}

//終了処理
void PlayerState_Dead::end()
{
	
}