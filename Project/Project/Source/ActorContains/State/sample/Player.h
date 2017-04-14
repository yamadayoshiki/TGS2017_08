#pragma once

#include "../../Base/Actor.h"
#include "../../../World/IWorld.h"
#include "../../../Math/Vector3.h"
#include "State/PlayerStateMgr.h"

// プレーヤー
class Player : public Actor {
public:
	// コンストラクタ
	Player(IWorld* world, const Vector3& position);
	// デストラクタ
	~Player();
	// 更新処理
	virtual void onUpdate(float deltaTime) override;
	// 描画処理
	virtual void onDraw() const override;
	// 衝突判定
	virtual void onCollide(Actor& other) override;
private:
	// 状態管理
	PlayerStateMgr* mStateMgr;
};
