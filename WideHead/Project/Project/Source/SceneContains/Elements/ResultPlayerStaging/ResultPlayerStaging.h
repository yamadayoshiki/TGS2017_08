#ifndef RESULT_PLAYER_STANGING_H_
#define RESULT_PLAYER_STANGING_H_

#include"../../../ActorContains/Actor/Actor.h"
#include<gslib.h>

class ResultPlayerStaging :public Actor
{
public:

	// �R���X�g���N�^
	ResultPlayerStaging(IWorld* world, const IGameManagerPtr& gameManager);

	//�X�V
	virtual void onUpdate(float deltaTime)override;

private:
	// ���l
	GScolor m_Color{ 1.0f,1.0f,1.0f,0.0f };
	bool is_end{ false };
	float m_Timer{ 0.0f };
	float m_Maxtimer{ 90.0f };
	GSvector2 m_Position{ -650,30 };
};
#endif // !RESULT_PLAYER_STAGING_H_
