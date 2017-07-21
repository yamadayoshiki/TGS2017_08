#include"PlayerState_MoveBase.h"
#include"../../../../../../ActorContains/Transform/Transform.h"
#include"../../../../../../ActorContains/BodyContains/Factory/BodyFactory.h"

//コンストラクタ
PlayerState_MoveBase::PlayerState_MoveBase(const Player_WPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player, gameManager) {
}

//各状態独自の初期化
void PlayerState_MoveBase::unique_init()
{
	if (p_Player.lock()->getParameter().getCreateFlag() == true) {
		p_Player.lock()->getParameter().Chargeflag = false;
		p_Player.lock()->getParameter().m_CreateFlag = false;
	}
	TextureName_Change("Player_Close");
	p_Player.lock()->getWorld()->GetBodyFactory()->Transform(p_Player.lock()->getBody(), Body::BodyDataName::Player_Close);
	p_Player.lock()->getParameter().m_ClipFlag = false;


	// 継承先の各状態独自の初期化
	onUniqueInit();
}
//更新処理
void PlayerState_MoveBase::update(float deltaTaime)
{
	//移動の入力状態によって状態を変更(待機、歩く)
	if (p_Input->PadVelocity().length() >= 0.5f) {
		change(PlayerStateName::Walk);
	}
	else if (p_Input->PadVelocity().length() <= 0.0f) {
		change(PlayerStateName::Idle);
	}
	//継承先の更新処理
	onUpdate(deltaTaime);
}
//衝突判定
void PlayerState_MoveBase::collide(const Actor& other, const Body::ContactSet& contactSet)
{
	//敵との衝突処理
	Collide(other,contactSet);

	//継承先の衝突処理
	onCollide(other,contactSet);
}
//終了処理
void PlayerState_MoveBase::end()
{
	//継承先の終了処理
	onEnd();
}
//入力処理
void PlayerState_MoveBase::input()
{
	//アームを開く
	if (p_Input->IsPadStateTrigger(GS_XBOX_PAD_B))
		change(PlayerStateName::Open);
	//ダッシュ
	if (p_Input->IsPadStateTrigger(GS_XBOX_PAD_A) &&
		p_Map.lock()->IsInFrontOfTheWall(
			p_Player.lock()->getPosition(), FourDirection(p_Player.lock()->getTransform()->m_Angle)) == false) {
		change(PlayerStateName::Dash);
	}

	//継承先の入力処理
	onInput();
}