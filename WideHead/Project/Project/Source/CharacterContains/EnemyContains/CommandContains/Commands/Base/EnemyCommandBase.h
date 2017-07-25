#ifndef ENEMYCOMMANDBASE_H_
#define ENEMYCOMMANDBASE_H_
#include "../Interface/IEnemyCommand.h"
#include "../../../StateContains/States/EnemyStateName.h"
#include "../../../Entity/Enemys/Base/EnemyBasePtr.h"
#include "../EnemyCommandName.h"
#include "../../../../../Map/MapType.h"
#include "../../../../../Utility/FourDirection/FourDirection.h"
#include <gslib.h>
#include <vector>
//エネミーに対するコマンド基底クラス
class EnemyCommandBase :public IEnemyCommand
{
public:
	//コンストラクタ
	EnemyCommandBase(const EnemyBasePtr& enemy);
	//仮想デストラクタ
	virtual ~EnemyCommandBase() { Finalize(); }
	//初期化
	void Initialize() override;
	//更新
	void Update(float deltaTime) override;
	//終了
	virtual void Finalize()override {}
	//終了チェック
	bool IsEnd() override;
	//次コマンドの取得
	EnemyCommandName GetNextCommand() const override;
	//メッセージ処理
	virtual void handleMessage(EventMessage message, void* param)override {}
	//命令ステート
	virtual EnemyStateName GetCurrentStateName() const override;
	//注視移動か
	virtual bool IsRegard() const override;
	//目標地点までの移動ベクトルの取得
	GSvector2 GetVelocity() const override;
	//回転角度の取得
	float GetRotateAngle() const override;
protected:
	//各種固有の初期化
	virtual void OnInitialize() {}
	//各種固有の更新
	virtual void OnUpdate(float deltaTime) {}
	//コマンド変更
	void Change(EnemyCommandName next);

protected:
	EnemyBaseWPtr p_Enemy;			//エネミー本体
	EnemyCommandName m_NextCommand;	//次のコマンド
	bool m_IsEnd;					//終了フラグ

	EnemyStateName m_CurStateName;	//エネミーステートネーム
	bool m_Regard;					//注視中か
	GSvector2 m_Velocity;			//目標地点までの移動ベクトル
	float m_RotateAngle;			//回転角度
};

#endif