#ifndef ENEMYCOMMANDENEMY04STANDBY_H_
#define ENEMYCOMMANDENEMY04STANDBY_H_

#include "../../Base/EnemyCommandBase.h"

//3�񋲂܂ꂽ��w������ɓ���
class EnemyCommandEnemy04Standby : public EnemyCommandBase
{
public:
	//�R���X�g���N�^
	EnemyCommandEnemy04Standby(
		const EnemyBasePtr& enemy,
		const FourDirection front);

	//���b�Z�[�W����
	virtual void handleMessage(EventMessage message, void* param)override;

protected:
	//�e��ŗL�̏�����
	virtual void OnInitialize() override;
	//�e��ŗL�̍X�V
	virtual void OnUpdate(float deltaTime) override;

	//�ڕW�n�_�ɓ����������A�N�V����
	virtual void ArriveReaction();
	//���̖ڕW�n�_��ݒ肷��
	void SetNextTargetPos();

protected:
	FourDirection m_Front;	//�w�����
	int m_Counter;			//���܂ꂽ��
	bool m_Flag;			//���ʂ��ǂ�
};

#endif // !ENEMYCOMMANDSTNDBY_H_

