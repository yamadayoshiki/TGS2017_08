#ifndef ENEMYCOMMANDBASE_H_
#define ENEMYCOMMANDBASE_H_

#include <gslib.h>
#include "../Interface/IEnemyCommand.h"
#include "../../../StateContains/States/EnemyStateName.h"
#include "../../../Enemys/Base/EnemyBasePtr.h"

class EnemyCommandBase :public IEnemyCommand
{
public:
	//コンストラクタ
	EnemyCommandBase(const EnemyBasePtr& enemy);
	//仮想デストラクタ
	virtual ~EnemyCommandBase() { Finalize(); }
	//初期化
	virtual void Initialize() override;
	//目標地点までの移動ベクトルの取得
	GSvector2 GetVelocity() const override;
	//回転角度の取得
	float GetRotateAngle() const override;

public:
	//更新
	virtual void Update(float deltaTime) override = 0;
	//終了
	virtual void Finalize()override {};
	//終了チェック
	virtual bool IsEnd() override = 0;
	//命令ステート
	virtual EnemyStateName GetCurrentStateName() const override = 0;

protected:
	//各種固有の初期化
	virtual void OnInitialize() {};

protected:
	EnemyBasePtr p_Enemy;		//エネミー本体
	GSvector2 m_Velocity;		//目標地点までの移動ベクトル
	float m_RotateAngle;		//回転角度
};

#endif