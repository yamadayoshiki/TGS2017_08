#include "EnemyCommandBase.h"
#include "../../../../../Define/Def_GSvector2.h"
#include "../../../Enemys/Base/EnemyBase.h"
#include "../../../../../ActorContains/Body/Base/Body.h"
#include "../../../../../Map/Map.h"
#include "../../../../../WorldContains/IWorld.h"
#include "../../../../../Define/Def_Nakayama.h"

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

//指定方向,自身からのマップ配列
std::vector<int> EnemyCommandBase::GetFrontMapData(const FourDirectionName fourDirectionName, MapType type) {
	//エネミー本体の座標
	GSvector2 pos = p_Enemy->getPosition();
	//エネミー本体の向き
	FourDirection dir = FourDirection(fourDirectionName);
	//マップ
	Map& map = p_Enemy->getWorld()->GetMap();
	//自分+背面のマス数
	int backChipNum;

	//正面進行方向の配列の作成
	std::vector<int> result;
	switch (dir.name)
	{
	case FourDirectionName::Up:
		//縦軸Map配列
		result = map.GetRow(pos, type);
		//逆順に整理
		std::reverse(begin(result), end(result));
		//自分を含めない上からのマス数
		backChipNum = pos.y / (CHIP_SIZE* ((int)type + 1));
		//自分を含めた背面のマス数
		backChipNum = map.GetHeight(type) - backChipNum;
		break;

	case FourDirectionName::Down:
		//縦軸Map配列
		result = map.GetRow(pos, type);
		//自分を含めた上からのマス数
		backChipNum = pos.y / (CHIP_SIZE* ((int)type + 1)) + 1;
		break;

	case FourDirectionName::Left:
		//横軸Map配列
		result = map.GetColumn(pos, type);
		//逆順に整理
		std::reverse(begin(result), end(result));
		//自分を含めない左からのマス数
		backChipNum = pos.x / (CHIP_SIZE* ((int)type + 1));
		//自分を含めた背面のマス数
		backChipNum = map.GetWidth(type) - backChipNum;
		break;

	case FourDirectionName::Right:
		//横軸Map配列
		result = map.GetColumn(pos, type);
		//自分を含めた左からのマス数
		backChipNum = pos.x / (CHIP_SIZE* ((int)type + 1)) + 1;
		break;

	default:
		break;
	}

	//背面マスの削除
	for (int i = 0; i < result.size(); i++)
	{
		if (backChipNum > i)
			result.erase(result.begin());

		else
			break;
	}

	return result;
}
