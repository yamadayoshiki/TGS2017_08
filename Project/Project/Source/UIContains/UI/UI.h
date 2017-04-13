#ifndef UI_H_
#define UI_H_

#include <gslib.h>
#include <memory>
#include <string>
#include <functional>
#include <forward_list>

#include "../UIPtr.h"
#include "../UIName.h"

enum class EventMessage;
class IWorld;

//UIクラス
class UI{
public:
	//コンストラクタ
	UI(IWorld* world, const UIName& name, const GSvector2& position);
	//コンストラクタ
	explicit UI(const UIName& name = UIName::None);
	//仮想デストラクタ
	virtual ~UI() {	}
	//更新
	void update(float deltaTime);
	//描画
	void draw() const;
	//死亡しているか
	bool GetDead() const;
	//死亡する
	void dead();
	//名前を返す
	const UIName getName() const;
	//座標を返す
	GSvector2 getPosition() const;
	//子の検索
	UIPtr findChildren_NullActor(const UIName& name);
	//子の検索（NullPtrあり）
	UIPtr findChildren(std::function<bool(const UI&)> fn);
	//子の追加
	void addChild(const UIPtr& child);
	//子を巡回
	void eachChildren(std::function<void(UI&)> fn);
	//子を巡回（const版）
	void eachChildren(std::function<void(const UI&)> fn) const;
	//子を削除する
	void removeChildren(std::function <bool(UI& actor)> fn);
	//子を削除する
	void removeChildren();
	//子を消去
	void clearChildren();
	//メッセージ処理
	void handleMessage(EventMessage message, void* param);

	//ワールドを設定
	void SetWorld(IWorld* world);

	//コピー禁止
	UI(const UI& other) = delete;
	UI& operator = (const UI& other) = delete;

private:
	//メッセージ処理
	virtual void onMessage(EventMessage message, void* param);
	//更新
	virtual void onUpdate(float deltaTime);
	//描画
	virtual void onDraw() const;

protected:
	//ワールド
	IWorld* p_World;
	//名前
	UIName m_Name;
	//座標
	GSvector2 m_Position;
	//死亡フラグ
	bool m_dead;

private:
	//子UI
	std::forward_list<UIPtr> m_children;
};

#endif // !UI_H_
