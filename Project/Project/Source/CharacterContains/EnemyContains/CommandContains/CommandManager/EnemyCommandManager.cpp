#include "EnemyCommandManager.h"
#include "../Commands/Interface/IEnemyCommand.h"
#include "../Commands/NullCommand/Enemy_NullCommand.h"

//コンストラクタ
EnemyCommandManager::EnemyCommandManager(const EnemyBasePtr& enemy)
	: p_Enemy(enemy)
	, p_CurCommand(std::make_shared<EnemyCommandNull>(enemy))
	, m_CurCommandNum(-1) {
	Initialize();
}

//デストラクタ
EnemyCommandManager::~EnemyCommandManager() {
	m_CommandDic.clear();
	m_CommandNameList.clear();
}

//初期化処理
void EnemyCommandManager::Initialize() {
	m_CommandDic.clear();
	m_CommandNameList.clear();
	m_CurCommandNum = -1;
}

//更新処理
void EnemyCommandManager::Update(float deltaTime) {
	//現在のコマンド終了チェック
	if (p_CurCommand->IsEnd() == true)
	{
		m_CurCommandNum++;
		if (m_CurCommandNum >= m_CommandNameList.size())
			m_CurCommandNum = 0;

		//コマンド入れ替え
		Change(m_CommandNameList[m_CurCommandNum]);
	}

	//現在のコマンド更新
	p_CurCommand->Update(deltaTime);
}

//終了処理
void EnemyCommandManager::Finalize() {
}

//コマンド辞書登録
void EnemyCommandManager::AddDic(EnemyCommandName name, const IEnemyCommandPtr& command) {
	m_CommandDic[name] = command;
}

//コマンド順序登録
void EnemyCommandManager::AddList(EnemyCommandName name) {
	m_CommandNameList.push_back(name);
}

//コマンド変更
void EnemyCommandManager::Change(const EnemyCommandName name) {
	p_CurCommand->Finalize();
	p_CurCommand = m_CommandDic[name];
	p_CurCommand->Initialize();
}

//命令ベクトルの取得
GSvector2& EnemyCommandManager::GetCommandVector() const {
	return p_CurCommand->GetVelocity();
}

//命令ステートの取得
EnemyStateName EnemyCommandManager::GetCommandState() const {
	return p_CurCommand->GetCurrentStateName();
}

//命令回転角度の取得
float EnemyCommandManager::GetCommandRotateAngle() const {
	return p_CurCommand->GetRotateAngle();
}