#pragma once

#include "IState.h"
#include "../../Actor/Actor.h"

// 各プレイヤーステートの基底クラス
class State : public IState
{
public:
	// コンストラクタ
	State();
	// 全状態共通の初期化
	virtual void common_init(Actor& actor, const int id) override;
	// 入力処理
	virtual void input() override;
	// 時間管理
	virtual void timer(const float& deltaTime) override;
	// ステートの変更処理
	void change_int(const int id) override;
	// ステートの変更処理(template版)
	template <class STATE>
	void change(const STATE id);
	// ステートが終了したか否か
	virtual bool isEnd() override;
	// 次のステートの要素
	virtual int next() const override;
	// 子の追加
	virtual void addChild(const ActorName& name, const ActorPtr& child) override;

protected:
	// ステートの要素
	int m_ID;
	// 次ステートの要素
	int m_NextID;
	// ステートが終了したか否か
	bool m_IsEnd;
	// タイマー
	float m_Timer;
	// 子リスト
	std::unordered_map<ActorName, ActorPtr> m_Children;
};

// ステートの変更処理(template版)
template<class STATE>
inline void State::change(const STATE id) {
	if (m_ID == static_cast<int>(id)) return;
	// 次のステート情報の格納
	m_NextID = static_cast<int>(id);
	// ステートの終了条件をtrueに変更
	m_IsEnd = true;
}