#ifndef ENEMYCOMMANDGENERATE_H_
#define ENEMYCOMMANDGENERATE_H_

#include "../../Base/EnemyCommandBase.h"

//���̃G�l�~�[�����}��(�w���̂̂�)
class EnemyCommandGenerate : public EnemyCommandBase
{
public:
	//�R���X�g���N�^
	EnemyCommandGenerate(
		const EnemyBasePtr& enemy,
		const float charaNumber,
		const float intervalTime);
	//�f�X�g���N�^
	~EnemyCommandGenerate();

protected:
	//�e��ŗL�̏�����
	virtual void OnInitialize() override;
	//�e��ŗL�̍X�V
	virtual void OnUpdate(float deltaTime) override;

protected:
	float m_CharaNumber;	//��������L�����N�^�[�̔ԍ�
	float m_IntervalTime;	//�������鎞�Ԃ̊Ԋu
	float m_Timer;			//�^�C�}�[
};

#endif // !ENEMYCOMMANDGENERATE_H_
