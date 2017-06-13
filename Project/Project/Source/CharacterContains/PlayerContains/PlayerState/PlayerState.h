#ifndef PLAYER_STATE_H_
#define PLAYER_STATE_H_

#include"../../../ActorContains/State/Base/State.h"
#include"../PlayerState/PlayerStateName.h"
#include"../../../Base/GameManagerContains/GameManager/GameManager.h"
#include"../../../Utility/InputState/InputState.h"
#include"../Player/Player.h"
#include "../Player/PlayerPtr.h"
#include"../Player/Player_Parameter.h"
#include "../../../Map/MapPtr.h"
#include"../../../Utility/Sound_Name.h"
#include"../../../Map/TerrainName.h"


// 各プレイヤーステートの基底クラス
class PlayerState :public State
{
public:
	//コンストラクタ
	PlayerState(const Player_WPtr& player, const IGameManagerPtr& gameManager);
	//パッド入力
	virtual void input()override;

protected:
	//移動処理
	void move(float deltaTime, float speed = 8.0f);
	//アーム更新
	void armUpdate();
	//視野角内にいるか
	bool is_Scorp_Angle(const Actor& other);
	//テクスチャ名前変更
	void TextureName_Change(const std::string& name);
	//敵との衝突処理
	void Collide(const Actor& other);
	//
	void Center_Adjustment();

protected:
	//プレイヤー本体
	Player_WPtr			p_Player;
	//変換
	Transform&			m_TransForm;
	//プレイヤーパラメーター
	Player_Parameter&	m_Parameter;
	//回転角度
	float				mAngle;
	//GameManager
	IGameManagerPtr		p_GameManager;
	//InoutState
	InputStatePtr		p_Input;
	//Map
	MapWPtr				p_Map;

private:
	GSvector2			inputVelocity;
	GSvector2			m_Position;

};

#endif // !PLAYER_STATE_H_