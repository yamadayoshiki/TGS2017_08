#ifndef RESULT_PLAYER_STANGING_H_
#define RESULT_PLAYER_STANGING_H_

#include"../../../ActorContains/Actor/Actor.h"
#include<gslib.h>

class ResultPlayerStaging :public Actor
{
public:

	// コンストラクタ
	ResultPlayerStaging(IWorld* world, const IGameManagerPtr& gameManager);

	//更新
	virtual void onUpdate(float deltaTime)override;

private:
	// α値
	GScolor m_Color{ 1.0f,1.0f,1.0f,0.0f };
	bool is_end{ false };
	float m_Timer{ 0.0f };
	float m_Maxtimer{ 90.0f };
	GSvector2 m_Position{ -650,30 };
};
#endif // !RESULT_PLAYER_STAGING_H_
