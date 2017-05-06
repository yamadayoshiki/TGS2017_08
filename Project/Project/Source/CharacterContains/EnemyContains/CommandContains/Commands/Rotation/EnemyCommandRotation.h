#ifndef ENEMYCOMMANDROTATION_H_
#define ENEMYCOMMANDROTATION_H_

#include "../Base/EnemyCommandBase.h"

class EnemyCommandRotation :public EnemyCommandBase
{
public:
	//コンストラクタ
	EnemyCommandRotation(
		const EnemyBasePtr& enemy,	//エネミー本体
		const float angle,			//回転角度
		const float endTimer		//回転終了までの時間
		);
	//更新
	virtual void Update(float deltaTime) override;
	//終了
	virtual void Finalize() override;
	//終了チェック
	virtual bool IsEnd() override;
	//命令ステート
	virtual EnemyStateName GetCurrentStateName() const override;

protected:
	//各種固有の初期化
	virtual void OnInitialize() override;

protected:
	float m_Angle;			//回転角度
	float m_Angle_PerFrame;	//毎フレームの回転角度
	float m_EndTimer;		//回転終了までの時間
	float m_Timer;			//タイマー
};

#endif // !ENEMY_COMMAND_ROTATION_H_
