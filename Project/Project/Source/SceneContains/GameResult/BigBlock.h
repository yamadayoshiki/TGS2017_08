#ifndef BIG_BLOCK_H_
#define BIG_BLOCK_H_

#include "../../StagingContains/TransitionStaging/Transition/Transition.h"
class Texture;
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
	bool is_end{ false };
	float timer_{ 0.0f };
	float m_Alpha{ 0.1f };
	std::unique_ptr<Texture> p_Texture;
};
#endif // !BIG_BLOCK_H_
