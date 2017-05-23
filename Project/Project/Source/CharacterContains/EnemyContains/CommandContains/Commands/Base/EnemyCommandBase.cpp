#include "EnemyCommandBase.h"
#include "../../../../../Define/Def_GSvector2.h"
#include "../../../Enemys/Base/EnemyBase.h"
#include "../../../../../ActorContains/Body/Base/Body.h"
#include "../../../../../Map/Map.h"
#include "../../../../../WorldContains/IWorld.h"
#include "../../../../../Define/Def_Nakayama.h"
#include "../../../../../Define/Def_GSvector2.h"

//コンストラクタ
EnemyCommandBase::EnemyCommandBase(const EnemyBasePtr& enemy)
	: IEnemyCommand()
	, p_Enemy(enemy)
	, m_Velocity(GSVECTOR2_ZERO)
	, m_RotateAngle(0.0f)
	, m_NextCommand(EnemyCommandName::None)
	, m_IsEnd(false) {
}

//初期化
void EnemyCommandBase::Initialize() {
	m_NextCommand = EnemyCommandName::None;
	m_IsEnd = false;
	//各種固有の初期化
	OnInitialize();
}

//更新
void EnemyCommandBase::Update(float deltaTime) {
	//変数の初期化
	m_Velocity = GSVECTOR2_ZERO;
	m_RotateAngle = 0;
	//各種固有の更新
	OnUpdate(deltaTime);
}

//目標地点までの移動ベクトルの取得
GSvector2 EnemyCommandBase::GetVelocity() const {
	return m_Velocity;
}

//回転角度の取得
float EnemyCommandBase::GetRotateAngle() const {
	return m_RotateAngle;
}

//終了チェック
bool EnemyCommandBase::IsEnd() {
	return m_IsEnd;
}

//次コマンドの取得
EnemyCommandName EnemyCommandBase::GetNextCommand() const {
	return m_NextCommand;
}

//命令ステート
EnemyStateName EnemyCommandBase::GetCurrentStateName() const {
	return EnemyStateName::None;
}

//次コマンドの設定
void EnemyCommandBase::Change(EnemyCommandName next) {
	m_NextCommand = next;
	m_IsEnd = true;
}