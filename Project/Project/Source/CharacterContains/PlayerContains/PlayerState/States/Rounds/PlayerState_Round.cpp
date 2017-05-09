#include"PlayerState_Round.h"

//コンストラクタ
PlayerState_Round::PlayerState_Round(GSvector2& position, GSmatrix4& matirx, const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState(position, matirx, player, gameManager)
{

}
//各状態独自の初期化
void PlayerState_Round::unique_init()
{

}
//更新処理
void PlayerState_Round::update(float deltaTime)
{

}
//衝突判定
void PlayerState_Round::collide(const Actor& other)
{
	
}
//終了処理
void PlayerState_Round::end()
{

}
//入力処理
void PlayerState_Round::input()
{
	//潰す状態に遷移
	if (p_Input->IsPadStateTrigger(GS_XBOX_PAD_Y)) {
		change(PlayerStateName::Crush);
	}
	//離す状態に遷移
	if (p_Input->IsPadStateTrigger(GS_XBOX_PAD_B)) {
		change(PlayerStateName::Release);
	}
}