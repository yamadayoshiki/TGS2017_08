#ifndef PLAYER_STATE_H_
#define PLAYER_STATE_H_

#include"../../../ActorContains/State/Base/State.h"
#include"../PlayerState/PlayerStateName.h"
#include"../../../Base/GameManagerContains/GameManager/GameManager.h"
#include"../../../Utility/InputState/InputState.h"
#include"../Arm/Arm.h"
#include"../Arm/ArmPtr.h"

#include <unordered_map>

// 各プレイヤーステートの基底クラス
class PlayerState :public State
{
public:
	//コンストラクタ
	PlayerState(GSvector2& position, GSmatrix4& matrix, IGameManagerPtr gameManager);
	//パッド入力
	virtual void input()override;

protected:
	//モーション変更
	//void motion_change(Actor& actor, const PlayerStateID);
	//移動処理
	void move(Actor& actor, float deltaTime, float speed = 1.0f);
	//挟む処理
	void Rounds(const Actor& actor);

protected:
	//座標の参照
	GSvector2&			mPosition;
	//行列
	GSmatrix4&			mMatrix;
	//速度
	GSvector2			mVelocity;
	//回転角度
	float				mAngle;
	//GameManager
	IGameManagerPtr		p_GameManager;
	//InoutState
	InputStatePtr		p_Input;
	//
	ArmPtr				p_Arm;

};

#endif // !PLAYER_STATE_H_