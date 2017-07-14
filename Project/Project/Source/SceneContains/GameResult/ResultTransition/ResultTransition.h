#ifndef RESULT_TRANSITION_H_
#define RESULT_TRANSITION_H_

#include"../../../StagingContains/TransitionStaging/Transition/Transition.h"
#include "../../../Utility/Texture2DParameter/Texture2DParameterPtr.h"
#include <GStype.h>
class ResultTransition :public Transition
{
public:

	// �R���X�g���N�^
	ResultTransition(const IGameManagerPtr& gameManager);
	// �f�X�g���N�^
	~ResultTransition();

	// �J�n     
	virtual void onStart()override;
	//�X�V
	virtual void onUpdate(float deltaTime)override;
	//�`��
	virtual void onDraw() const override;
	// �I���t���O
	virtual bool isEnd() override;
private:
	// ���l
	GScolor m_Color{ 1.0f,1.0f,1.0f,0.0f };
	bool is_end{ false };
	float m_Timer{ 0.0f };
	float m_Maxtimer{ 40.0f };
	GSvector2 m_Position{ -650,30 };

	Texture2DParameterSPtr p_Param;
};
#endif // !RESULT_TRANSITION_H_
