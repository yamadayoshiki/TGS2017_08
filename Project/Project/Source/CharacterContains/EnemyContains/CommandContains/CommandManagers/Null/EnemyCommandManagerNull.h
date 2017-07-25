#ifndef ENEMYCOMMANDMANAGERNULL_H_
#define ENEMYCOMMANDMANAGERNULL_H_
#include "../Interface/IEnemyCommandManager.h"
class EnemyCommandManagerNull : public IEnemyCommandManager
{
public:
	//コンストラクタ
	EnemyCommandManagerNull() {}
	//初期化
	virtual void Initialize() override{}
	//更新
	virtual void Update(float deltaTime) override {}
	//終了
	virtual void Finalize() override {}
	//追加
	virtual void AddDic(const EnemyCommandName name, const IEnemyCommandPtr& command) override{}
	//コマンド変更
	virtual void Change(const EnemyCommandName name) override{}
	//メッセージ処理
	virtual void handleMessage(EventMessage message, void* param) override {}

public:
	//命令ステートの取得
	virtual EnemyStateName GetCommandState() override;
	//注視移動か
	virtual bool IsRegard() const override { return false; }
	//命令ベクトルの取得
	virtual GSvector2& GetCommandVector() override;
	//命令回転角度の取得
	virtual float GetCommandRotateAngle() override { return 0.0f; }
};
#endif // !ENEMYCOMMANDMANAGERNULL_H_
