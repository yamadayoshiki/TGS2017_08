#ifndef BIG_BLOCK_2_H_
#define BIG_BLOCK_2_H_

#include "../../StagingContains/TransitionStaging/Transition/Transition.h"
#include "../../Utility/Texture2DParameter/Texture2DParameterPtr.h"
#include <GStype.h>

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
	// α値
	GScolor m_Color{ 1.0f,1.0f,1.0f,1.0f };
	float m_Alpha{ 0.1f };
	bool is_end{ false };
	float timer_{ 0.0f };
	Texture2DParameterSPtr p_Param;
};
#endif // !BIG_BLOCK_2_H_
