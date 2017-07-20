#ifndef BIG_BLOCK_2_H_
#define BIG_BLOCK_2_H_

#include"../../ActorContains/Actor/Actor.h"
class BigBlock2 :public Actor
{
public:
	// コンストラクタ
	BigBlock2(IWorld* world, const IGameManagerPtr& gameManager);
	// デストラクタ
	~BigBlock2();
	//更新
	virtual void onUpdate(float deltaTime)override;
private:
	
	float m_Alpha{ 0.1f };
	bool is_end{ false };
	float timer_{ 0.0f };

};
#endif // !BIG_BLOCK_2_H_
