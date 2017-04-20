#ifndef PLAYER_STATE_H_
#define PLAYER_STATE_H_

#include"../../../ActorContains/State/Base/State.h"
#include"../../../Base/GameManagerContains/GameManager/GameManager.h"
#include"../../../Utility/InputState/InputState.h"


// 各プレイヤーステートの基底クラス
class PlayerState :public State
{
public:
	//コンストラクタ
	PlayerState(GSvector2& position,GSmatrix4& matrix,GameManager* gameManager);
	//パッド入力
	virtual void input()override;

protected:
	//モーション変更
	//void motion_change(Actor& actor, const PlayerStateID);
	//移動処理
	void move(Actor& actor, float deltaTime, float speed = 1.0f);

protected:
	//座標の参照
	GSvector2&		mPosition;
	//行列
	GSmatrix4&		mMatrix;
	//速度
	GSvector2		mVelocity;
	//回転角度
	float			mAngle;
	//GameManager
	GameManager*	p_GameManager;
	//InoutState
	InputState*		p_Input;
};

#endif // !PLAYER_STATE_H_