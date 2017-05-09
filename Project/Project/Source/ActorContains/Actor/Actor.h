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

#include "../../WorldContains/IWorldPtr.h"
#include "../../Base/GameManagerContains/IGameManagerPtr.h"
#include "../../TextureContains/ITexturePtr.h"
#include "../../TextureContains/NullTexture/NullTexture.h"
#include "../Transform/Transform.h"

enum class EventMessage;

//アクタークラス
class Actor
{
public:
	//コンストラクタ
	Actor(
		const IWorldPtr& world,
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
	//名前を返す
	const ActorName getName() const;
	//座標を返す
	GSvector2 getPosition() const;
	////行列を返す
	//GSmatrix4 getMatrix() const;
	////座標を返す
	//GSmatrix4 getPose() const;
	////回転
	//void rotate(const float& angle);
	////拡大、縮小
	//void scale(const GSvector2& scale);

	//変換情報を返す
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
	void SetWorld(const IWorldPtr& world);
	//判定の形の取得
	IBodyPtr getBody() const;

	////行列の設定
	//void setMatrix(const GSmatrix4& mat);
	//座標の設定
	void setPosition(const GSvector2& pos);
	//角度の設定
	void setAngle(const float& angle);

	//テクスチャを取得
	ITexturePtr getTexture() const;
	// クローン生成
	ActorPtr clone(const ActorPtr& source);
	// クローン生成
	virtual ActorPtr clone(const GSvector2& position);

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
	IWorldPtr p_World;
	//ゲームマネージャー
	IGameManagerPtr p_GameManager;
	//名前
	ActorName m_Name;

	// 変換
	Transform m_Transform;

	////座標
	//GSvector2 m_Position;
	////変換行列
	//GSmatrix4 m_Matrix;
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