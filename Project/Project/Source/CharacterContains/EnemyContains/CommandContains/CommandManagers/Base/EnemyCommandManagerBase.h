#ifndef ENEMYCOMMANDMANAGERBASE_H_
#define ENEMYCOMMANDMANAGERBASE_H_

#include <map>
#include <vector>
#include "../Interface/IEnemyCommandManager.h"
#include "../../../Entity/Enemys/Base/EnemyBasePtr.h"

enum class EnemyCommandName;

//エネミーコマンドマネージャ基底クラス
class EnemyCommandManagerBase : public IEnemyCommandManager
{
public:
	//コンストラクタ
	EnemyCommandManagerBase(const EnemyBasePtr& enemy);
	//デストラクタ
	virtual ~EnemyCommandManagerBase();
	//初期化
	void Initialize() override;
	//更新
	void Update(float deltaTime) override;
	//終了
	void Finalize() override;
	//追加
	void AddDic(const EnemyCommandName name,const IEnemyCommandPtr& command) override;
	//コマンド変更
	void Change(const EnemyCommandName name) override;
	//メッセージ処理
	virtual void handleMessage(EventMessage message, void* param) override;

public:
	//命令ステートの取得
	EnemyStateName GetCommandState() override;
	//注視移動か
	virtual bool IsRegard() const;
	//命令ベクトルの取得
	GSvector2& GetCommandVector() override;
	//命令回転角度の取得
	float GetCommandRotateAngle() override;

protected:
	//各種固有の初期化
	virtual void OnInitialize() {}
	//各種固有の終了
	virtual void OnFinalize() {}
	//次のコマンド
	virtual EnemyCommandName GetNextCommand() = 0;

protected:
	EnemyBaseWPtr p_Enemy;										//エネミー本体
	std::map<EnemyCommandName, IEnemyCommandPtr> m_CommandDic;	//コマンド辞書
	IEnemyCommandPtr p_CurCommand;								//現在のコマンド
};

#endif