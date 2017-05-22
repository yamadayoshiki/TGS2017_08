#include"PlayerState_Dead.h"

//コンストラクタ
PlayerState_Dead::PlayerState_Dead(const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player,gameManager)
{

}
//各状態独自の初期化
void PlayerState_Dead::unique_init()
{
	p_Player->getWorld()->EndRequest(SceneName::GameResult);
}
//更新処理
void PlayerState_Dead::update(float deltaTaime)
{
	p_Player->dead();
}

//終了処理
void PlayerState_Dead::end()
{
	
}