#pragma once

// 先行宣言
class Actor;

#include <unordered_map>
#include "../../ActorPtr.h"

enum class ActorName;

// ステートクラスのインターフェース
class IState {
public:
	// 仮想デストラクタ
	virtual ~IState() {}
	// 全状態共通の初期化
	virtual void common_init(const int id) = 0;
	// 各状態独自の初期化
	virtual void unique_init() = 0;
	// 入力処理
	virtual void input() = 0;
	// 更新処理
	virtual void update(float deltaTime) = 0;
	// 時間更新処理
	virtual void timer(const float& deltaTime) = 0;
	// 状態の変更
	virtual void change_int(const int id) = 0;
	// 衝突判定
	virtual void collide(const Actor & other) = 0;
	// 終了を返す
	virtual bool isEnd() = 0;
	// 次のステートの要素
	virtual int next() const = 0;
	// 終了時の処理
	virtual void end() = 0;
	// 子の追加
	virtual void addChild(const ActorName& name, const ActorPtr& child) = 0;
};