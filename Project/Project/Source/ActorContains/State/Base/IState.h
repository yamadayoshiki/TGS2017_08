#pragma once

#include "ActionType.h"

// 先行宣言
class Actor;

// ステートクラスのインターフェース
class IState {
public:
	// ステートの要素
	struct Component {
		// ステートのID
		int mID;
		// ステートのタイプ
		ActionType mType;
	};
public:
	// 仮想デストラクタ
	virtual ~IState() {}
	// 全状態共通の初期化
	virtual void common_init(Actor& actor, const Component comp) = 0;
	// 各状態独自の初期化
	virtual void unique_init(Actor& actor) = 0;
	// 入力処理
	virtual void input() = 0;
	// 更新処理
	virtual void update(Actor & actor, float deltaTime) = 0;
	// 時間更新処理
	virtual void timer(const float& deltaTime) = 0;
	// 状態の変更
	virtual void change(const Component comp) = 0;
	// 衝突判定
	virtual void collide(const Actor & other) = 0;
	// 終了を返す
	virtual bool isEnd() = 0;
	// 次のステートの要素
	virtual Component next() const = 0;
	// 終了時の処理
	virtual void end() = 0;
};
