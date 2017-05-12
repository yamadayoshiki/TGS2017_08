#ifndef IENEMYCOMMAND_H_
#define IENEMYCOMMAND_H_

enum class EnemyStateName;
enum class EnemyCommandName;
struct GSvector2;
class EnemyBase;

//�G�l�~�[�ɑ΂���R�}���h�C���^�[�t�F�C�X
class IEnemyCommand
{
public:
	//���z�f�X�g���N�^
	virtual ~IEnemyCommand() {}
	//������
	virtual void Initialize() = 0;
	//�X�V
	virtual void Update(float deltaTime) = 0;
	//�I��
	virtual void Finalize() = 0;
	//�I���`�F�b�N
	virtual bool IsEnd() = 0;
	//���R�}���h�̎擾
	virtual EnemyCommandName GetNextCommand() const = 0;
	//���߃X�e�[�g
	virtual EnemyStateName GetCurrentStateName() const = 0;
	//�ړ��x�N�g���̎擾
	virtual GSvector2 GetVelocity() const = 0;
	//��]�p�x�̎擾
	virtual float GetRotateAngle() const = 0;
};

#endif
