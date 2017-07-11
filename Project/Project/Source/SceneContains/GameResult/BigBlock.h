#ifndef BIG_BLOCK_H_
#define BIG_BLOCK_H_

#include "../../StagingContains/TransitionStaging/Transition/Transition.h"

class BigBlock :public Transition
{
public:
	// コンストラクタ
	BigBlock(const IGameManagerPtr& gameManager);
	// デストラクタ
	~BigBlock();

	// 開始     
	virtual void onStart()override;
	//更新
	virtual void onUpdate(float deltaTime)override;
	//描画
	virtual void onDraw() const override;
	// 終了フラグ
	virtual bool isEnd() override;
private:
	// α値
	GScolor m_Color{ 1.0f,1.0f,1.0f,1.0f };
	float m_Alpha{ 0.1f };
	bool is_end{ false };
	float timer_{ 0.0f };
};
#endif // !BIG_BLOCK_H_
