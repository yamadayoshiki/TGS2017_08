#ifndef RESULT_TRANSITION_H_
#define RESULT_TRANSITION_H_

#include"../../../StagingContains/TransitionStaging/Transition/Transition.h"
#include "../../../Utility/Texture2DParameter/Texture2DParameterPtr.h"
#include <GStype.h>
class ResultTransition :public Transition
{
public:

	// コンストラクタ
	ResultTransition(const IGameManagerPtr& gameManager);
	// デストラクタ
	~ResultTransition();

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
	GScolor m_Color{ 1.0f,1.0f,1.0f,0.0f };
	bool is_end{ false };
	float m_Timer{ 0.0f };
	float m_Maxtimer{ 40.0f };
	GSvector2 m_Position{ -650,30 };

	Texture2DParameterSPtr p_Param;
};
#endif // !RESULT_TRANSITION_H_
