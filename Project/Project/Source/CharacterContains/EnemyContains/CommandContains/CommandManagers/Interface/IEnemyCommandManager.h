#ifndef IENEMYCOMMANDMANAGER_H_
#define IENEMYCOMMANDMANAGER_H_

#include "../../Commands/Interface/IEnemyCommandPtr.h"

//先行宣言
enum class EnemyCommandName;
enum class EnemyStateName;
struct GSvector2;

//エネミーコマンドマネージャインターフェイス
class IEnemyCommandManager
{
public:
	//仮想デストラクタ
	virtual ~IEnemyCommandManager() {}
	//初期化
	virtual void Initialize() = 0;
	//更新
	virtual void Update(float deltaTime) = 0;
	//終了
	virtual void Finalize() = 0;
	//追加
	virtual void AddDic(EnemyCommandName name, const IEnemyCommandPtr& command) = 0;
	//コマンド変更
	virtual void Change(const EnemyCommandName name) = 0;

public:
	//命令ステートの取得
	virtual EnemyStateName GetCommandState() = 0;
	//命令ベクトルの取得
	virtual GSvector2& GetCommandVector() = 0;
	//命令回転角度の取得
	virtual float GetCommandRotateAngle() = 0;
};

#endif