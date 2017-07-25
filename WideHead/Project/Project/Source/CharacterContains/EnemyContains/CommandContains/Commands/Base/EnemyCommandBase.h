#ifndef ENEMYCOMMANDBASE_H_
#define ENEMYCOMMANDBASE_H_
#include "../Interface/IEnemyCommand.h"
#include "../../../StateContains/States/EnemyStateName.h"
#include "../../../Entity/Enemys/Base/EnemyBasePtr.h"
#include "../EnemyCommandName.h"
#include "../../../../../Map/MapType.h"
#include "../../../../../Utility/FourDirection/FourDirection.h"
#include <gslib.h>
#include <vector>
//�G�l�~�[�ɑ΂���R�}���h���N���X
class EnemyCommandBase :public IEnemyCommand
{
public:
	//�R���X�g���N�^
	EnemyCommandBase(const EnemyBasePtr& enemy);
	//���z�f�X�g���N�^
	virtual ~EnemyCommandBase() { Finalize(); }
	//������
	void Initialize() override;
	//�X�V
	void Update(float deltaTime) override;
	//�I��
	virtual void Finalize()override {}
	//�I���`�F�b�N
	bool IsEnd() override;
	//���R�}���h�̎擾
	EnemyCommandName GetNextCommand() const override;
	//���b�Z�[�W����
	virtual void handleMessage(EventMessage message, void* param)override {}
	//���߃X�e�[�g
	virtual EnemyStateName GetCurrentStateName() const override;
	//�����ړ���
	virtual bool IsRegard() const override;
	//�ڕW�n�_�܂ł̈ړ��x�N�g���̎擾
	GSvector2 GetVelocity() const override;
	//��]�p�x�̎擾
	float GetRotateAngle() const override;
protected:
	//�e��ŗL�̏�����
	virtual void OnInitialize() {}
	//�e��ŗL�̍X�V
	virtual void OnUpdate(float deltaTime) {}
	//�R�}���h�ύX
	void Change(EnemyCommandName next);

protected:
	EnemyBaseWPtr p_Enemy;			//�G�l�~�[�{��
	EnemyCommandName m_NextCommand;	//���̃R�}���h
	bool m_IsEnd;					//�I���t���O

	EnemyStateName m_CurStateName;	//�G�l�~�[�X�e�[�g�l�[��
	bool m_Regard;					//��������
	GSvector2 m_Velocity;			//�ڕW�n�_�܂ł̈ړ��x�N�g��
	float m_RotateAngle;			//��]�p�x
};

#endif