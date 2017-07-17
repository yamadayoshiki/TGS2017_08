#include"PlayerState_Open.h"
#include"../../PlayerStateName.h"
#include"../../../../../ActorContains/BodyContains/Factory/BodyFactory.h"

//コンストラクタ
PlayerState_Open::PlayerState_Open(const Player_WPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player, gameManager)
{

}

//各状態独自の初期化
void PlayerState_Open::unique_init()
{
	TextureName_Change("Player_Open");
	gsPlaySE(SE_PLAYER_ARM);
	p_Player.lock()->getWorld()->GetBodyFactory()->Transform(p_Player.lock()->getBody(), Body::BodyDataName::Player_Open);
}

//更新処理
void PlayerState_Open::update(float deltaTaime)
{
	if (p_Player.lock()->GetLoopCount() > 0)
		change(PlayerStateName::O_Walk);
	move(deltaTaime);
}

//衝突判定
void PlayerState_Open::collide(const Actor& other, const Body::ContactSet& contactSet)
{
	Collide(other,contactSet);
}

//終了処理
void PlayerState_Open::end()
{

}