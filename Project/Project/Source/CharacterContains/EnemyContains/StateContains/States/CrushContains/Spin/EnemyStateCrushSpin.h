#ifndef ENEMYSTATECRUSHSPIN_H_
#define ENEMYSTATECRUSHSPIN_H_

#include "../Standard/EnemyStateCrushStandard.h"

//�R��N���b�V�����ꂽ��X�s����ԂɈڍs
class EnemyStateCrushSpin : public EnemyStateCrushStandard
{
public:
	//�R���X�g���N�^
	EnemyStateCrushSpin(const EnemyBasePtr& enemy, int limitCounter);
protected:
	// �e��ԓƎ��̏�����
	virtual void unique_init() override;
	// �X�V����
	virtual void update(float deltaTime) override;

private:
	int m_Counter;		//�N���b�V����
	int m_LimitCounter;	//�N���b�V���񐔏��
};

#endif