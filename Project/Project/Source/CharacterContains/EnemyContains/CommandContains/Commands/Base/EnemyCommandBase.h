#ifndef ENEMYCOMMANDBASE_H_
#define ENEMYCOMMANDBASE_H_

#include <gslib.h>
#include "../Interface/IEnemyCommand.h"
#include "../../../StateContains/States/EnemyStateName.h"
#include "../../../Enemys/Base/EnemyBasePtr.h"

class EnemyCommandBase :public IEnemyCommand
{
public:
	//�R���X�g���N�^
	EnemyCommandBase(const EnemyBasePtr& enemy);
	//���z�f�X�g���N�^
	virtual ~EnemyCommandBase() { Finalize(); }
	//������
	virtual void Initialize() override;
	//�ڕW�n�_�܂ł̈ړ��x�N�g���̎擾
	GSvector2 GetVelocity() const override;
	//��]�p�x�̎擾
	float GetRotateAngle() const override;

public:
	//�X�V
	virtual void Update(float deltaTime) override = 0;
	//�I��
	virtual void Finalize()override {};
	//�I���`�F�b�N
	virtual bool IsEnd() override = 0;
	//���߃X�e�[�g
	virtual EnemyStateName GetCurrentStateName() const override = 0;

protected:
	//�e��ŗL�̏�����
	virtual void OnInitialize() {};

protected:
	EnemyBasePtr p_Enemy;		//�G�l�~�[�{��
	GSvector2 m_Velocity;		//�ڕW�n�_�܂ł̈ړ��x�N�g��
	float m_RotateAngle;		//��]�p�x
};

#endif