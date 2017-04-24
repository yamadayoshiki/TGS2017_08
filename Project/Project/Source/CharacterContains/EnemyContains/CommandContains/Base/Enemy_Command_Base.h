#ifndef ENEMY_COMMAND_BASE_H_
#define ENEMY_COMMAND_BASE_H_

#include <gslib.h>
#include "../Enemy_ICommand.h"
#include "../../EnemyStateName.h"

class Enemy_Command_Base :public Enemy_ICommand
{
public:
	//コンストラクタ
	Enemy_Command_Base();
	//仮想デストラクタ
	virtual ~Enemy_Command_Base() { Finalize(); }
	//初期化
	virtual void Initialize() override;
	//終了しているか
	virtual bool IsEnd() override;
	//移動ベクトルの取得
	GSvector2& GetVelocity() override;
	//ステート終了フラグの設定
	virtual void SetStateEnd(bool stateEnd) override;

public:
	//更新
	virtual void Update() override = 0;
	//終了
	virtual void Finalize()override {};
	//命令ステート
	virtual EnemyStateName GetCurrentStateName()override = 0;

protected:
	//各種固有の初期化
	virtual void OnInitialize() {};

protected:
	bool m_IsEnd;			//終了フラグ
	bool m_StateEnd;		//ステート終了フラグ
	GSvector2 m_Velocity;	//移動ベクトル
};

#endif // !ENEMY_COMMAND_BASE_H_
