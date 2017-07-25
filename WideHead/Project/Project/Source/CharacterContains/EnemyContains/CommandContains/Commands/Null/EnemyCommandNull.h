#ifndef ENEMYCOMMANDNULL_H_
#define ENEMYCOMMANDNULL_H_

#include "../Interface/IEnemyCommand.h"

class EnemyCommandNull : public IEnemyCommand
{
public:
	//コンストラクタ
	EnemyCommandNull() {}
	//初期化
	virtual void Initialize()override {}
	//更新
	virtual void Update(float deltaTime) override {}
	//終了
	virtual void Finalize() override {}
	//終了チェック
	virtual bool IsEnd() override { return true; }
	//次コマンドの取得
	virtual EnemyCommandName GetNextCommand() const override;
	//メッセージ処理
	virtual void handleMessage(EventMessage message, void* param) override {}
	//命令ステート
	virtual EnemyStateName GetCurrentStateName() const override;
	//注視移動か
	virtual bool IsRegard() const override { return false; }
	//目標地点までの移動ベクトルの取得
	virtual GSvector2 GetVelocity() const override;
	//回転角度の取得
	virtual float GetRotateAngle() const override { return 0.0f; }
};


#endif
