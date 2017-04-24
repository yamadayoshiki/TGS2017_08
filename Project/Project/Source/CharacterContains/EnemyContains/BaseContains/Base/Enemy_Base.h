#ifndef ENEMY_BASE_H_
#define ENEMY_BASE_H_

#include "../../../../ActorContains/Actor/Actor.h"

//先行宣言
class Enemy_StateManager;

//エネミー基底クラス
class Enemy_Base :public Actor
{
public:
	//コンストラクタ
	Enemy_Base(
		const IWorldPtr& world,
		const ActorName& name,
		const GSvector2& position,
		const IGameManagerPtr& gameManager,
		const ITexturePtr& texture,
		const IBodyPtr& body = std::make_shared<DammyBody>()
		);
	//仮想デストラクタ
	virtual ~Enemy_Base() {}

protected:
	//更新
	virtual void onUpdate(float deltaTime) override;
	//描画
	virtual void onDraw() const override;
	//衝突した
	virtual void onCollide(Actor& other) override;

protected:
	Enemy_StateManager* p_Enemy_StateManager;	//ステートマネージャー
};
#endif // !ENEMY_H_
