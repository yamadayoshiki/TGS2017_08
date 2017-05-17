#ifndef ENEMYCOMMANDMANAGERORDER_H_
#define ENEMYCOMMANDMANAGERORDER_H_

#include <vector>
#include "../Base/EnemyCommandManagerBase.h"

//エネミーコマンドマネージャ/順序付け
class EnemyCommandManagerOrder :public EnemyCommandManagerBase
{
public:
	//コンストラクタ
	EnemyCommandManagerOrder(const EnemyBasePtr& enemy);
	//コマンド順序登録(追加順)
	void AddList(EnemyCommandName name);

protected:
	//各種固有の初期化
	virtual void OnInitialize() override;
	//各種固有の終了
	virtual void OnFinalize() override;
	//次のコマンド
	virtual EnemyCommandName GetNextCommand() override;

protected:
	std::vector<EnemyCommandName> m_CommandNameList;	//コマンド順序
	int m_CurCommandNum;								//現在のコマンド番号
};

#endif // !ENEMYCOMMANDMANAGERORDER_H_
