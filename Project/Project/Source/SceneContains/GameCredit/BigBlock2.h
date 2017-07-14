#ifndef BIG_BLOCK_2_H_
#define BIG_BLOCK_2_H_

#include "../../StagingContains/TransitionStaging/Transition/Transition.h"
#include "../../Utility/Texture2DParameter/Texture2DParameterPtr.h"
#include <GStype.h>

class BigBlock2 :public Transition
{
public:
	// �R���X�g���N�^
	BigBlock2(const IGameManagerPtr& gameManager);
	// �f�X�g���N�^
	~BigBlock2();

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
	GScolor m_Color{ 1.0f,1.0f,1.0f,1.0f };
	float m_Alpha{ 0.1f };
	bool is_end{ false };
	float timer_{ 0.0f };
	Texture2DParameterSPtr p_Param;
};
#endif // !BIG_BLOCK_2_H_
