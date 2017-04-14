#ifndef ACTOR_H_
#define ACTOR_H_

#include <gslib.h>
#include <memory>
#include <string>
#include <functional>
#include <forward_list>

#include "../ActorPtr.h"
#include "../ActorName.h"

enum class EventMessage;
class IWorld;

//アクタークラス
class Actor
{
public:
	//コンストラクタ
	Actor(
		IWorld* world,
		const ActorName& name,
		const GSvector2& position
		);
	//コンストラクタ
	explicit Actor(const ActorName& name = ActorName::None);
	//仮想デストラクタ
	virtual ~Actor() {	}
	//更新
	void update(float deltaTime);
	//描画
	void draw() const;
	//衝突判定(自分は子を巡回、引数はそれ単体)
	void collide(Actor& other);
	//死亡しているか
	bool GetDead() const;
	//死亡する
	void dead();
	//名前を返す
	const ActorName getName() const;
	//座標を返す
	GSvector2 getPosition() const;
	//子の検索
	ActorPtr findChildren_NullActor(const ActorName& name);
	//子の検索（NullPtrあり）
	ActorPtr findChildren(std::function<bool(const Actor&)> fn);
	//子同士の衝突判定
	void collideChidren(Actor& other);
	//兄弟同士の衝突判定
	void collideSibling();
	//子の追加
	void addChild(const ActorPtr& child);
	//子を巡回
	void eachChildren(std::function<void(Actor&)> fn);
	//子を巡回（const版）
	void eachChildren(std::function<void(const Actor&)> fn) const;
	//子を削除する
	void removeChildren(std::function <bool(Actor& actor)> fn);
	//子を削除する
	void removeChildren();
	//子を消去
	void clearChildren();
	//メッセージ処理
	void handleMessage(EventMessage message, void* param);

	//ワールドを設定
	void SetWorld(IWorld* world);

	//コピー禁止
	Actor(const Actor& other) = delete;
	Actor& operator = (const Actor& other) = delete;

private:
	//メッセージ処理
	virtual void onMessage(EventMessage message, void* param);
	//更新
	virtual void onUpdate(float deltaTime);
	//描画
	virtual void onDraw() const;
	//衝突した
	virtual void onCollide(Actor& other);
	//衝突判定
	bool isCollide(const Actor& other) const;


protected:
	//ワールド
	IWorld* p_World;
	//名前
	ActorName m_Name;
	//座標
	GSvector2 m_Position;
	//死亡フラグ
	bool m_dead;

private:
	//子アクター
	std::forward_list<ActorPtr> m_children;
};

#endif // !ACTOR_H_
