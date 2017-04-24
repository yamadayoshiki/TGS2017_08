#ifndef ENEMY_ICOMMAND_H_
#define ENEMY_ICOMMAND_H_

enum class EnemyStateName;
struct GSvector2;

//エネミーに対するコマンドインターフェイス
class Enemy_ICommand
{
public:
	//仮想デストラクタ
	virtual ~Enemy_ICommand() {}
	//初期化
	virtual void Initialize() = 0;
	//更新
	virtual void Update() = 0;
	//終了
	virtual void Finalize() = 0;
	//命令ステート
	virtual EnemyStateName GetCurrentStateName() = 0;
	//終了しているか
	virtual bool IsEnd() = 0;
	//移動ベクトルの取得
	virtual GSvector2& GetVelocity() = 0;
	//ステート終了フラグの設定
	virtual void SetStateEnd(bool stateEnd) = 0;
};

#endif // !ENEMY_ICOMMAND_H_
