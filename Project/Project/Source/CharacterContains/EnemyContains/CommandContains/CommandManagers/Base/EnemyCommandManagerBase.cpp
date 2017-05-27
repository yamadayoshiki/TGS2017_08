#include "EnemyCommandManagerBase.h"
#include "../../Commands/Interface/IEnemyCommand.h"
#include "../../Commands/Null/EnemyCommandNull.h"

//コンストラクタ
EnemyCommandManagerBase::EnemyCommandManagerBase(const EnemyBasePtr& enemy)
	: p_Enemy(enemy)
	, p_CurCommand(std::make_shared<EnemyCommandNull>(enemy)) {
	Initialize();
}

//初期化
void EnemyCommandManagerBase::Initialize() {
	m_CommandDic.clear();
	//各種固有の初期化
	OnInitialize();
}

//更新
void EnemyCommandManagerBase::Update(float deltaTime) {
	//現在のコマンド更新
	p_CurCommand->Update(deltaTime);

	//終了判定がtrueの場合変更
	if (p_CurCommand->IsEnd() == true)
		Change(GetNextCommand());
}

//終了
void EnemyCommandManagerBase::Finalize() {
	m_CommandDic.clear();
	//各種固有の終了
	OnFinalize();
}

//追加
void EnemyCommandManagerBase::AddDic(EnemyCommandName name, const IEnemyCommandPtr & command) {
	m_CommandDic[name] = command;
}

//命令ステートの取得
EnemyStateName EnemyCommandManagerBase::GetCommandState() {
	return p_CurCommand->GetCurrentStateName();
}

//注視移動か
bool EnemyCommandManagerBase::IsRegard() const {
	return p_CurCommand->IsRegard();
}

//命令ベクトルの取得
GSvector2 & EnemyCommandManagerBase::GetCommandVector() {
	return p_CurCommand->GetVelocity();
}

//命令回転角度の取得
float EnemyCommandManagerBase::GetCommandRotateAngle() {
	return p_CurCommand->GetRotateAngle();
}

//コマンド変更
void EnemyCommandManagerBase::Change(const EnemyCommandName name) {
	p_CurCommand->Finalize();
	p_CurCommand = m_CommandDic[name];
	p_CurCommand->Initialize();
}

//メッセージ処理
void EnemyCommandManagerBase::handleMessage(EventMessage message, void * param) {
	p_CurCommand->handleMessage(message, param);
}
