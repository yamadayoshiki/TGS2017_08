#ifndef ACTOR_H_
#define ACTOR_H_

#include <string>
#include <functional>
#include <forward_list>

#include "../ActorPtr.h"
#include "../ActorName.h"

#include "../../Base/GameManagerContains/IGameManagerPtr.h"
#include "../../TextureContains/ITexturePtr.h"
#include "../../TextureContains/NullTexture/NullTexture.h"

#include "../../Utility/FourDirection/FourDirection.h"
#include "../../Map/MapType.h"

#include "../BodyContains/Interface/IBodyPtr.h"
#include "../BodyContains/Elements/MotionType.h"
#include "../BodyContains/BodyDataName.h"
#include "../Transform/TransformPtr.h"

enum class EventMessage;
class IWorld;
namespace Body {
	struct ContactSet;
}
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
		const Body::MotionType type = Body::MotionType::None,
		const Body::BodyDataName dataName = Body::BodyDataName::None);
	//コンストラクタ
	explicit Actor(const ActorName& name = ActorName::None);
	//仮想デストラクタ
	virtual ~Actor() {}
	//セットアップ
	virtual void SetUp() {}
	//初期化
	virtual void initialize();
	//更新
	void update(float deltaTime);
	//衝突判定後の更新
	void LateUpdate();
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
	TransformPtr getTransform() const;

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
	Body::IBodyPtr getBody() const;

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
	virtual void onMessage(EventMessage message, void* param) {}
	//更新
	virtual void onUpdate(float deltaTime) {}
	//衝突判定後の更新
	void OnLateUpdate() {}
	//描画
	virtual void onDraw() const {}
	//衝突リアクション
	virtual void onCollide(Actor& other,const Body::ContactSet& contactSet) {}
public:
	//衝突判定
	Body::ContactSet isCollide(const Actor& other);


protected:
	IWorld* p_World;				//ワールド
	IGameManagerPtr p_GameManager;	//ゲームマネージャ
	ActorName m_Name;				//名前
	TransformPtr p_Transform;		//トランスフォーム
	ITexturePtr	p_Texture;			//テクスチャ
	Body::IBodyPtr p_Body;			//衝突判定図形
	bool m_dead;					//死亡しているか

private:
	std::forward_list<ActorPtr> m_children;	//子アクター
};

#endif