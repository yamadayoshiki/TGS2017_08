#include"PlayerState_O_MoveBase.h"
#include"../../../PlayerStateName.h"
#include"../../../../../../ActorContains/ActorGroup.h"
#include"../../../../../NeutralContains/Charge_Effect/Charge.h" 
#include "../../../../../../ActorContains/BodyContains/Elements/ContactSet/ContactSet.h"

//コンストラクタ
PlayerState_O_MoveBase::PlayerState_O_MoveBase(const Player_WPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player,gameManager){}

//各状態独自の初期化
void PlayerState_O_MoveBase::unique_init()
{
	if (p_Player.lock()->getParameter().getChargeFlag() == false) {
		p_Player.lock()->getParameter().Chargeflag = true;
		p_Player.lock()->getWorld()->addActor(
			ActorGroup::Effect, 
			std::make_shared<Charge>(
				p_Player.lock()->getWorld(), 
				m_Children[ActorName::Player_Arm]->getPosition(), p_GameManager,p_Player));
	}
	TextureName_Change("Player_Open");
	// 継承先の各状態独自の初期化
	onUniqueInit();
}
//更新処理
void PlayerState_O_MoveBase::update(float deltaTaime)
{
	if (p_Input->PadVelocity().length() >= 0.5f) {
		change(PlayerStateName::O_Walk);
	}
	else if (p_Input->PadVelocity().length() <= 0.0f) {
		change(PlayerStateName::O_Idle);
	}

	//チャージ
	m_Parameter.Charge(deltaTaime);

	//継承先の更新処理
	onUpdate(deltaTaime);
}
//衝突判定
void PlayerState_O_MoveBase::collide(const Actor& other, const Body::ContactSet& contactSet)
{
	//アームに当たっていたら返す
	if (m_Children[ActorName::Player_Arm]->isCollide(other).m_IsCollide && is_Scorp_Angle(other)) return;

	//敵との衝突処理
	Collide(other,contactSet);

	//継承先の衝突処理
	onCollide(other,contactSet);
}
//終了処理
void PlayerState_O_MoveBase::end()
{
	//継承先の終了処理
	onEnd();
}
//入力処理
void PlayerState_O_MoveBase::input()
{
	if (!p_Input->IsPadState(GS_XBOX_PAD_B)) {
		change(PlayerStateName::Swich);
	}
	//ダッシュ
	if (p_Input->IsPadStateTrigger(GS_XBOX_PAD_A) ||
		gsGetKeyState(GKEY_Z)) {
		change(PlayerStateName::Dash);
	}
	//継承先の入力処理
	onInput();
}