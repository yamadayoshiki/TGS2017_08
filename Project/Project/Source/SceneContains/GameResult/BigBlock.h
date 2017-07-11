#ifndef BIG_BLOCK_H_
#define BIG_BLOCK_H_

#include "../../StagingContains/TransitionStaging/Transition/Transition.h"

class BigBlock :public Transition
{
public:
	// �R���X�g���N�^
	BigBlock(const IGameManagerPtr& gameManager);
	// �f�X�g���N�^
	~BigBlock();

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
};
#endif // !BIG_BLOCK_H_
