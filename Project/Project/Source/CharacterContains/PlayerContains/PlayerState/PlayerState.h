#ifndef PLAYER_STATE_H_
#define PLAYER_STATE_H_

#include"../../../ActorContains/State/Base/State.h"
#include"../PlayerState/PlayerStateName.h"
#include"../../../Base/GameManagerContains/GameManager/GameManager.h"
#include"../../../Utility/InputState/InputState.h"
#include"../Arm/Arm.h"
#include"../Arm/ArmPtr.h"
#include"../Player/Player.h"
#include "../Player/PlayerPtr.h"
#include"../Player/Player_Parameter.h"
#include <unordered_map>

class Map;

// 各プレイヤーステートの基底クラス
class PlayerState :public State
{
public:
	//コンストラクタ
	PlayerState(const PlayerPtr& player, const IGameManagerPtr& gameManager);
	//パッド入力
	virtual void input()override;

protected:
	//モーション変更
	//void motion_change(Actor& actor, const PlayerStateID);
	//移動処理
	void move(float deltaTime, float speed = 1.0f);
	//アーム更新
	void armUpdate();

protected:
	//プレイヤー本体
	PlayerPtr			p_Player;
	//変換
	Transform&			m_TransForm;
	//プレイヤーパラメーター
	Player_Parameter	m_Parameter;
	//回転角度
	float				mAngle;
	//GameManager
	IGameManagerPtr		p_GameManager;
	//InoutState
	InputStatePtr		p_Input;
	//Map
	Map&				m_Map;

private:
	GSvector2			inputVelocity;
	GSvector2			m_Position;

};

#endif // !PLAYER_STATE_H_