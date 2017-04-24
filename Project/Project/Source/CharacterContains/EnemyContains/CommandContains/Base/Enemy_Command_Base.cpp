#include "Enemy_Command_Base.h"

//コンストラクタ
Enemy_Command_Base::Enemy_Command_Base()
	: m_IsEnd(false)
	, m_StateEnd(false) {
}

//初期化
void Enemy_Command_Base::Initialize() {
	m_IsEnd = false;
	m_StateEnd = false;
	OnInitialize();
}

//終了しているか
bool Enemy_Command_Base::IsEnd() {
	return m_IsEnd;
}

//移動ベクトルの取得
GSvector2& Enemy_Command_Base::GetVelocity() {
	return m_Velocity;
}

//ステート終了フラグの設定
void Enemy_Command_Base::SetStateEnd(bool stateEnd) {
	m_StateEnd = stateEnd;
}