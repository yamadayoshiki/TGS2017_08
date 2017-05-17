#include "EnemyCommandManagerOrder.h"

//コンストラクタ
EnemyCommandManagerOrder::EnemyCommandManagerOrder(const EnemyBasePtr & enemy)
	: EnemyCommandManagerBase(enemy)
	, m_CurCommandNum(-1) {
}

//コマンド順序登録(追加順)
void EnemyCommandManagerOrder::AddList(EnemyCommandName name) {
	m_CommandNameList.push_back(name);
}

//各種固有の初期化
void EnemyCommandManagerOrder::OnInitialize() {
	m_CommandNameList.clear();
}

//各種固有の終了
void EnemyCommandManagerOrder::OnFinalize() {
	m_CommandNameList.clear();
}

//次のコマンド
EnemyCommandName EnemyCommandManagerOrder::GetNextCommand() {
	//List番号の加算
	m_CurCommandNum++;
	if (m_CurCommandNum >= m_CommandNameList.size())
		m_CurCommandNum = 0;

	//Listの順序
	return m_CommandNameList[m_CurCommandNum];
}
