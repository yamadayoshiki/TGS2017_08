#ifndef BIG_BLOCK_H_
#define BIG_BLOCK_H_

#include"../../ActorContains/Actor/Actor.h"
class BigBlock :public Actor
{
public:
	// コンストラクタ
	BigBlock(IWorld* world, const IGameManagerPtr& gameManager);
	// デストラクタ
	~BigBlock();
	//更新
	virtual void onUpdate(float deltaTime)override;
private:

	// α値
	bool is_end{ false };
	float timer_{ 0.0f };
	float m_Alpha{ 0.1f };
};
#endif // !BIG_BLOCK_H_
