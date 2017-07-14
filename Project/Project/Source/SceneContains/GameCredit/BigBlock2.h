#ifndef BIG_BLOCK_2_H_
#define BIG_BLOCK_2_H_

#include "../../StagingContains/TransitionStaging/Transition/Transition.h"
#include <GStype.h>

class Texture;

class BigBlock2 :public Transition
{
public:
	// コンストラクタ
	BigBlock2(const IGameManagerPtr& gameManager);
	// デストラクタ
	~BigBlock2();

	// 開始     
	virtual void onStart()override;
	//更新
	virtual void onUpdate(float deltaTime)override;
	//描画
	virtual void onDraw() const override;
	// 終了フラグ
	virtual bool isEnd() override;
private:
	
	float m_Alpha{ 0.1f };
	bool is_end{ false };
	float timer_{ 0.0f };

	std::unique_ptr<Texture> p_Texture;
};
#endif // !BIG_BLOCK_2_H_
