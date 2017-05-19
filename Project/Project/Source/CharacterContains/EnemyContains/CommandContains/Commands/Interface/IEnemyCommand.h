#ifndef IENEMYCOMMAND_H_
#define IENEMYCOMMAND_H_

//先行宣言
enum class EnemyStateName;
enum class EnemyCommandName;
struct GSvector2;
class EnemyBase;
enum class EventMessage;

//エネミーに対するコマンドインターフェイス
class IEnemyCommand
{
public:
	//仮想デストラクタ
	virtual ~IEnemyCommand() {}
	//初期化
	virtual void Initialize() = 0;
	//更新
	virtual void Update(float deltaTime) = 0;
	//終了
	virtual void Finalize() = 0;
	//終了チェック
	virtual bool IsEnd() = 0;
	//次コマンドの取得
	virtual EnemyCommandName GetNextCommand() const = 0;
	//メッセージ処理
	virtual void handleMessage(EventMessage message, void* param) = 0;
	//命令ステート
	virtual EnemyStateName GetCurrentStateName() const = 0;
	//目標地点までの移動ベクトルの取得
	virtual GSvector2 GetVelocity() const = 0;
	//回転角度の取得
	virtual float GetRotateAngle() const = 0;
};

#endif
