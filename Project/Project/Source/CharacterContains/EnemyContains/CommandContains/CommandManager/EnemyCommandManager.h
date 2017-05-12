#ifndef ENEMYCOMMANDMANAGER_H_
#define ENEMYCOMMANDMANAGER_H_

#include <gslib.h>
#include <map>
#include <vector>

#include "../../Enemys/Base/EnemyBasePtr.h"
#include "../Commands/Interface/IEnemyCommandPtr.h"

enum class EnemyStateName;
enum class EnemyCommandName;

class EnemyCommandManager
{
public:
	//コンストラクタ
	EnemyCommandManager(const EnemyBasePtr& enemy);
	//デストラクタ
	~EnemyCommandManager();
	//初期化処理
	void Initialize();
	//更新処理
	void Update(float deltaTime);
	//終了処理
	void Finalize();
	//コマンド辞書登録
	void AddDic(EnemyCommandName name, const IEnemyCommandPtr& command);
	//コマンド順序登録
	void AddList(EnemyCommandName name);

private:
	//コマンド変更
	void Change(const EnemyCommandName name);

public:
	//命令ステートの取得
	EnemyStateName GetCommandState() const;
	//命令ベクトルの取得
	GSvector2& GetCommandVector() const;
	//命令回転角度の取得
	float GetCommandRotateAngle() const;

private:
	EnemyBasePtr p_Enemy;										//エネミー本体
	std::map<EnemyCommandName, IEnemyCommandPtr> m_CommandDic;	//コマンド辞書
	std::vector<EnemyCommandName> m_CommandNameList;			//コマンド順序
	IEnemyCommandPtr p_CurCommand;								//現在のコマンド
	int m_CurCommandNum;										//現在のコマンド番号
};

#endif