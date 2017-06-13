#ifndef ACTOR_H_
#define ACTOR_H_

#include <gslib.h>
#include <memory>
#include <string>
#include <functional>
#include <forward_list>

#include "../ActorPtr.h"
#include "../ActorName.h"

#include "../Body/Base/IBodyPtr.h"
#include "../Body/Base/DammyBody.h"
#include "../Body/Base/HitInfo.h"

#include "../../Base/GameManagerContains/IGameManagerPtr.h"
#include "../../TextureContains/ITexturePtr.h"
#include "../../TextureContains/NullTexture/NullTexture.h"
#include "../Transform/Transform.h"

#include "../../Utility/FourDirection/FourDirection.h"
#include "../../Map/MapType.h"

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
		const GSvector2& position,
		const IGameManagerPtr& gaemManager,
		const ITexturePtr& texture = std::make_shared<NullTexture>(),
		const IBodyPtr& body = std::make_shared<DammyBody>());
	//コンストラクタ
	explicit Actor(const ActorName& name = ActorName::None);
	//仮想デストラクタ
	virtual ~Actor();
	//初期化
	virtual void initialize();
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
	//名前を取得
	const ActorName getName() const;
	//座標を取得
	GSvector2 getPosition() const;

	//変換情報を取得
	Transform getTransform() const;

	//子の検索
	ActorPtr findChildren_NullActor(const ActorName& name);
	//子の検索（NullPtrあり）
	ActorPtr findChildren(std::function<bool(const Actor&)> fn);
	//子同士の衝突判定
	void collideChildren(Actor& other);
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
	//ワールドを取得
	IWorld* getWorld() const;
	//判定の形の取得
	IBodyPtr getBody() const;

	int getCount() const;

	virtual MapType GetMapType() const;

	//座標の設定
	void setPosition(const GSvector2& pos);
	//角度の設定
	void setAngle(const float& angle);

	//テクスチャを取得
	ITexturePtr getTexture() const;
	//csvで生成(使用時継承先でoverride)
	virtual ActorPtr CsvGenerate(const int x, const int y, const int csvparam);

	// コピー禁止
	Actor(const Actor& other) = delete;
	Actor& operator = (const Actor& other) = delete;

protected:
	//メッセージ処理
	virtual void onMessage(EventMessage message, void* param);
	//更新
	virtual void onUpdate(float deltaTime);
	//描画
	virtual void onDraw() const;
	//衝突した
	virtual void onCollide(Actor& other);
public:
	//衝突判定
	bool isCollide(const Actor& other);


protected:
	//ワールド
	IWorld* p_World;
	//ゲームマネージャー
	IGameManagerPtr p_GameManager;
	//名前
	ActorName m_Name;

	// 変換
	Transform m_Transform;

	//衝突判定
	IBodyPtr p_Body;
	// 衝突情報
	HitInfo m_HitInfo;
	//死亡フラグ
	bool m_dead;
	//テクスチャ
	ITexturePtr	p_Texture;

private:
	//子アクター
	std::forward_list<ActorPtr> m_children;
};

#endif // !ACTOR_H_