#pragma once

#include "../Base/EnemyBase.h"
#include "../../CommandContains/Commands/Interface/IEnemyCommand.h"

class TestEnemy01 : public EnemyBase
{
public:
	//コンストラクタ
	TestEnemy01(
		IWorld* world,
		const GSvector2& position,
		const IGameManagerPtr& gameManager);
protected:
	//更新
	virtual void onUpdate(float deltaTime) override;
	//描画
	virtual void onDraw() const override;
	//衝突した
	virtual void onCollide(Actor& other) override;

protected:
	IEnemyCommand* command;		//コマンド
};