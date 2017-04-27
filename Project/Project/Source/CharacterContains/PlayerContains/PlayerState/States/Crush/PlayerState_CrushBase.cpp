#include"PlayerState_CrushBase.h"

//コンストラクタ
PlayerState_CrushBase::PlayerState_CrushBase(GSvector2& position, GSmatrix4& matrix, IGameManagerPtr gameManager)
	:PlayerState(position, matrix, gameManager) ,m_FrameCounter(0.0f){}

//各状態独自の初期化
void PlayerState_CrushBase::unique_init(Actor& actor)
{
	// 継承先の各状態独自の初期化
	onUniqueInit(actor);
}
//更新処理
void PlayerState_CrushBase::update(Actor& actor, float deltaTaime)
{


	move(actor, deltaTaime);

	//継承先の更新処理
	onUpdate(actor, deltaTaime);
}
//衝突判定
void PlayerState_CrushBase::collide(const Actor& other)
{
	if (other.getName() == ActorName::Enemy)
	{

	}
	//継承先の衝突処理
	onCollide(other);
}
//終了処理
void PlayerState_CrushBase::end()
{
	//継承先の終了処理
	onEnd();
}
//入力処理
void PlayerState_CrushBase::input()
{
	//アームを開く
	if (p_Input->IsPadTrigger(GS_XBOX_PAD_B)) change(PlayerStateName::Open);

	//継承先の入力処理
	onInput();
}