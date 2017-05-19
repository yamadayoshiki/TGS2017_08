#ifndef ENEMYCOMMANDBASE_H_
#define ENEMYCOMMANDBASE_H_

#include <gslib.h>
#include <vector>
#include "../Interface/IEnemyCommand.h"
#include "../../../StateContains/States/EnemyStateName.h"
#include "../../../Enemys/Base/EnemyBasePtr.h"
#include "../EnemyCommandName.h"
#include "../../../../../Map/MapType.h"
#include "../../../../../Utility/FourDirection/FourDirection.h"

//�G�l�~�[�ɑ΂���R�}���h���N���X
class EnemyCommandBase :public IEnemyCommand
{
public:
	//�R���X�g���N�^
	EnemyCommandBase(const EnemyBasePtr& enemy);
	//���z�f�X�g���N�^
	virtual ~EnemyCommandBase() { Finalize(); }
	//������
	virtual void Initialize() override;
	//�X�V
	virtual void Update(float deltaTime) override;
	//�I��
	virtual void Finalize()override {}
	//�I���`�F�b�N
	bool IsEnd() override;
	//���R�}���h�̎擾
	EnemyCommandName GetNextCommand() const override;
	//���߃X�e�[�g
	virtual EnemyStateName GetCurrentStateName() const override;
	//�ڕW�n�_�܂ł̈ړ��x�N�g���̎擾
	GSvector2 GetVelocity() const override;
	//��]�p�x�̎擾
	float GetRotateAngle() const override;
protected:
	//�e��ŗL�̍X�V
	virtual void OnUpdate(float deltaTime) {}
	//�e��ŗL�̏�����
	virtual void OnInitialize() {}
	//�R�}���h�ύX
	void Change(EnemyCommandName next);

protected:
	//�w�����,���g����̃}�b�v�z��
	std::vector<int> GetFrontMapData(const FourDirectionName fourDirectionName, MapType type = MapType::Default);

protected:
	EnemyBasePtr p_Enemy;			//�G�l�~�[�{��
	GSvector2 m_Velocity;			//�ڕW�n�_�܂ł̈ړ��x�N�g��
	float m_RotateAngle;			//��]�p�x
	EnemyCommandName m_NextCommand;	//���̃R�}���h
	bool m_IsEnd;					//�I���t���O
};

#endif